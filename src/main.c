#include <SDL2/SDL.h>
#include <string.h>
#include <stdint.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct {
    uint16_t tile_num;
    uint8_t hflip;
    uint8_t vflip;
    uint8_t palette;
} MapBlock;

typedef struct {
    uint8_t color;
} Tile;

typedef struct {
    uint8_t *tiles;
    int tilesLen;

    uint16_t *map;
    int mapLen;

    uint16_t *pal;
    int palLen;
} ASM;

void dumpASM(char *path, ASM *image) {
    FILE *f = fopen(path, "w");

    fprintf(f, "tiles:");
    for (int i = 0; i < image->tilesLen; i += 4) {
        if (!(i % 32)) fprintf(f, "\n");
        uint32_t tile = image->tiles[i] << 24;
        tile |= image->tiles[i+1] << 16;
        tile |= image->tiles[i+2] << 8;
        tile |= image->tiles[i+3];

        fprintf(f, "0x%08x,", tile);
    }

    fprintf(f, "\nmap:");
    for (int i = 0; i < image->mapLen; i++) {
        if (!(i % 8)) fprintf(f, "\n");

        fprintf(f, "0x%04x,", image->map[i]);
    }

    fprintf(f, "\npal:");
    for (int i = 0; i < image->palLen; i++) {
        if (!(i % 8)) fprintf(f, "\n");

        fprintf(f, "0x%04x,", image->pal[i]);
    }
    fprintf(f, "\n");
}

int loadASM(char *path, ASM *image) {
    FILE *f = fopen(path, "r");

    if (!f) {
        printf("Failed to open file\n");
        return 1;
    }

    printf("Reading file at: %s\n", path);

    int section = 0;
    char line[512];
    int line_num = 0;
    while (fgets(line, sizeof(line), f)) {
        line_num++;
        int line_start = 0;
        while (line[line_start] == ' ' || line[line_start] == 9) line_start++;
        if (line[line_start] == '.' || line[line_start] == '@' || line[line_start] == '\n') {
            printf("Line %d: %s -> Ignored\n", line_num, line);
            continue;
        }

        printf("Line %d: %s -> Section Start\n", line_num, line);

        switch (section) {
            case 0:
                {
                    int tile_i = 0;
                    while (1) {
                        char *r = fgets(line, sizeof(line), f);
                        line_num++;
                        int line_start = 0;
                        while (line[line_start] == ' ' || line[line_start] == 9) line_start++;

                        if ((line[line_start] != '.' && line[line_start] != '@' && line[line_start] != '\n') || !r) {
                            image->tilesLen = tile_i;
                            fseek(f, -strlen(line), SEEK_CUR);
                            section++;
                            break;
                        }

                        if (line[line_start] == '@' || line[line_start] == '\n') {
                            printf("Line %d: %s -> Ignored\n", line_num, line);
                            continue;
                        }
                        printf("Line %d: %s -> Tile\n", line_num, line);

                        int words[8];
                        sscanf(line, " .word 0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x",
                                &words[0],&words[1],&words[2],&words[3],&words[4],&words[5],&words[6],&words[7]);
                        for (int i = 0; i < 8; i++) {
                            image->tiles[tile_i++] = (0xFF000000 & words[i]) >> 24;
                            image->tiles[tile_i++] = (0x00FF0000 & words[i]) >> 16;
                            image->tiles[tile_i++] = (0x0000FF00 & words[i]) >> 8;
                            image->tiles[tile_i++] = 0x000000FF & words[i];
                        }
                    }
                }
                break;
            case 1:
                {
                    int map_i = 0;
                    while (1) {
                        char *r = fgets(line, sizeof(line), f);
                        line_num++;
                        int line_start = 0;
                        while (line[line_start] == ' ' || line[line_start] == 9) line_start++;

                        if ((line[line_start] != '.' && line[line_start] != '@' && line[line_start] != '\n') || !r) {
                            image->mapLen = map_i;
                            fseek(f, -strlen(line), SEEK_CUR);
                            section++;
                            break;
                        }

                        if (line[line_start] == '@' || line[line_start] == '\n') {
                            printf("Line %d: %s -> Ignored\n", line_num, line);
                            continue;
                        }
                        printf("Line %d: %s -> Map\n", line_num, line);

                        sscanf(line, " .hword 0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x",
                                &image->map[map_i],&image->map[map_i+1],&image->map[map_i+2],&image->map[map_i+3],
                                &image->map[map_i+4],&image->map[map_i+5],&image->map[map_i+6],&image->map[map_i+7]);
                        map_i += 8;
                    }
                }
                break;
            case 2:
                {
                    int pal_i = 0;
                    while (1) {
                        char *r = fgets(line, sizeof(line), f);
                        line_num++;
                        int line_start = 0;
                        while (line[line_start] == ' ' || line[line_start] == 9) line_start++;

                        if ((line[line_start] != '.' && line[line_start] != '@' && line[line_start] != '\n') || !r) {
                            image->palLen = pal_i;
                            break;
                        }

                        if (line[line_start] == '@' || line[line_start] == '\n') {
                            printf("Line %d: %s -> Ignored\n", line_num, line);
                            continue;
                        }
                        printf("Line %d: %s -> Palette\n", line_num, line);

                        sscanf(line, " .hword 0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x",
                                &image->pal[pal_i],&image->pal[pal_i+1],&image->pal[pal_i+2],&image->pal[pal_i+3],
                                &image->pal[pal_i+4],&image->pal[pal_i+5],&image->pal[pal_i+6],&image->pal[pal_i+7]);
                        pal_i += 8;
                    }
                }
                break;
        }
    }

    fclose(f);

    return 0;
}

int main(int argc, char* args[]){
    ASM image = {0};
    image.tiles = malloc(5000);
    image.map = malloc(3000);
    image.pal = malloc(40);
    loadASM("res/paused.s", &image);

    dumpASM("dump.s", &image);

    SDL_Window *window = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    window = SDL_CreateWindow("gba-tile", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN /*| SDL_WINDOW_FULLSCREEN*/);
    if(window == NULL){
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    if (!window) exit(1);

    SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
    uint8_t *pixels = (uint8_t*)screenSurface->pixels;
    SDL_Event e;

    while(1){
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT)
                exit(0);
        }

        for (int i = 0; i < image.mapLen; i++) {
            uint16_t tile_num = image.map[i] & 0b1111111111;
            uint8_t hflip = (image.map[i] & 0b10000000000) >> 10;
            uint8_t vflip = (image.map[i] & 0b100000000000) >> 11;
            uint8_t pal_num = (image.map[i] & 0b1111000000000000) >> 12;

            uint16_t tile_index = tile_num << 5;
            int x = 8*(i % 32), y = 8*(i / 32);
            for (int j = 0; j < 32; j++) {
                {
                    uint8_t tile = (image.tiles[tile_index] & 0xF0) >> 4;
                    uint8_t red = image.pal[tile] & 0b11111;
                    uint8_t green = (image.pal[tile] & 0b1111100000) >> 5;
                    uint8_t blue = (image.pal[tile] & 0b111110000000000) >> 10;
                    pixels[WIDTH*4*y + 4*x] = red << 3;
                    pixels[WIDTH*4*y + 4*x+1] = blue << 3;
                    pixels[WIDTH*4*y + 4*x+2] = green << 3;
                    x++;
                }
                {
                    uint8_t tile = image.tiles[tile_index] & 0xF;
                    uint8_t red = image.pal[tile] & 0b11111;
                    uint8_t green = (image.pal[tile] & 0b1111100000) >> 5;
                    uint8_t blue = (image.pal[tile] & 0b111110000000000) >> 10;
                    pixels[WIDTH*4*y + 4*x] = red << 3;
                    pixels[WIDTH*4*y + 4*x+1] = blue << 3;
                    pixels[WIDTH*4*y + 4*x+2] = green << 3;
                    x++;
                }
                if (!(x % 8)) {
                    y++;
                    x -= 8;
                }
            }
        }

        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    free(image.tiles);
    free(image.map);
    free(image.pal);

    return 0;
}

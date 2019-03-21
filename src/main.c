#include <SDL2/SDL.h>
#include <string.h>
#include <stdint.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct {
    uint16_t tile_num[262144];
    uint8_t hflip[262144];
    uint8_t vflip[262144];
    uint8_t palette[262144];
} Map;

typedef enum {
    COLOR16,
    COLOR256,
} ParseMode;

typedef struct {
    uint8_t tiles[1024][8][8];
    int tilesLen;

    Map map;
    int mapLen;

    uint16_t pal[256];
    int palLen;

    ParseMode mode;
} ASM;

void putPixel(SDL_Surface *surface, int x, int y, uint32_t pixel){
    uint32_t *pixels = (uint32_t*)surface->pixels;
    pixels[(y*surface->w) + x] = pixel;
}

int loadASM(char *path, ASM *image, ParseMode mode) {
    FILE *f = fopen(path, "r");
    FILE *log = fopen("log", "w");

    if (!f) {
        printf("Failed to open file\n");
        return 1;
    }

    fprintf(log, "Reading file: %s\n", path);

    image->mode = mode;

    int section = 0;
    char line[512];
    int line_num = 0;
    while (fgets(line, sizeof(line), f)) {
        line_num++;
        int line_start = 0;
        while (line[line_start] == ' ' || line[line_start] == 9) line_start++;
        if (line[line_start] == '.' || line[line_start] == '@' || line[line_start] == '\n') {
            fprintf(log, "Line %d: %s -> Ignored\n", line_num, line);
            continue;
        }

        fprintf(log, "Line %d: %s -> Section Start\n", line_num, line);

        switch (section) {
            case 0:
                {
                    int tile_i = 0;
                    int half = 0;
                    while (1) {
                        char *r = fgets(line, sizeof(line), f);
                        line_num++;
                        int line_start = 0;
                        while (line[line_start] == ' ' || line[line_start] == 9) line_start++;

                        if ((line[line_start] == '.' && line[line_start+1] != 'w') || (line[line_start] != '.' && line[line_start] != '@' && line[line_start] != '\n') || !r) {
                            image->tilesLen = tile_i;
                            fseek(f, -strlen(line), SEEK_CUR);
                            section++;
                            break;
                        }

                        if (line[line_start] == '@' || line[line_start] == '\n') {
                            fprintf(log, "Line %d: %s -> Ignored\n", line_num, line);
                            continue;
                        }
                        fprintf(log, "Line %d: %s -> Tile\n", line_num, line);

                        int words[8];
                        sscanf(line, " .word 0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x",
                                &words[0],&words[1],&words[2],&words[3],&words[4],&words[5],&words[6],&words[7]);
                        if (mode == COLOR16) {
                            for (int i = 0; i < 8; i++) {
                                image->tiles[tile_i][7][i] = (0xF0000000 & words[i]) >> 28;
                                image->tiles[tile_i][6][i] = (0x0F000000 & words[i]) >> 24;
                                image->tiles[tile_i][5][i] = (0x00F00000 & words[i]) >> 20;
                                image->tiles[tile_i][4][i] = (0x000F0000 & words[i]) >> 16;
                                image->tiles[tile_i][3][i] = (0x0000F000 & words[i]) >> 12;
                                image->tiles[tile_i][2][i] = (0x00000F00 & words[i]) >> 8;
                                image->tiles[tile_i][1][i] = (0x000000F0 & words[i]) >> 4;
                                image->tiles[tile_i][0][i] = (0x0000000F & words[i]);
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i += 2) {
                                image->tiles[tile_i][7][half+i/2] = (0xFF000000 & words[i+1]) >> 24;
                                image->tiles[tile_i][6][half+i/2] = (0x00FF0000 & words[i+1]) >> 16;
                                image->tiles[tile_i][5][half+i/2] = (0x0000FF00 & words[i+1]) >> 8;
                                image->tiles[tile_i][4][half+i/2] = (0x000000FF & words[i+1]);
                                image->tiles[tile_i][3][half+i/2] = (0xFF000000 & words[i]) >> 24;
                                image->tiles[tile_i][2][half+i/2] = (0x00FF0000 & words[i]) >> 16;
                                image->tiles[tile_i][1][half+i/2] = (0x0000FF00 & words[i]) >> 8;
                                image->tiles[tile_i][0][half+i/2] = (0x000000FF & words[i]);
                            }
                            half = half == 0 ? 4 : 0;
                        }
                        if (!half) {
                            tile_i++;
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

                        if ((line[line_start] == '.' && line[line_start+1] != 'h') || (line[line_start] != '.' && line[line_start] != '@' && line[line_start] != '\n') || !r) {
                            image->mapLen = map_i;
                            fseek(f, -strlen(line), SEEK_CUR);
                            section++;
                            break;
                        }

                        if (line[line_start] == '@' || line[line_start] == '\n') {
                            fprintf(log, "Line %d: %s -> Ignored\n", line_num, line);
                            continue;
                        }
                        fprintf(log, "Line %d: %s -> Map\n", line_num, line);

                        int words[8];
                        sscanf(line, " .hword 0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x",
                                &words[0],&words[1],&words[2],&words[3],&words[4],&words[5],&words[6],&words[7]);
                        for (int i = 0; i < 8; i++) {
                            image->map.tile_num[map_i] = words[i] & 0b1111111111;
                            image->map.hflip[map_i] = (words[i] & 0b10000000000) >> 10;
                            image->map.vflip[map_i] = (words[i] & 0b100000000000) >> 11;
                            image->map.palette[map_i] = (words[i] & 0b1111000000000000) >> 12;
                            map_i++;
                        }
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

                        if ((line[line_start] == '.' && line[line_start+1] != 'h') || (line[line_start] != '.' && line[line_start] != '@' && line[line_start] != '\n') || !r) {
                            image->palLen = pal_i;
                            break;
                        }

                        if (line[line_start] == '@' || line[line_start] == '\n') {
                            fprintf(log, "Line %d: %s -> Ignored\n", line_num, line);
                            continue;
                        }
                        fprintf(log, "Line %d: %s -> Palette\n", line_num, line);

                        sscanf(line, " .hword 0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x",
                                &image->pal[pal_i],&image->pal[pal_i+1],&image->pal[pal_i+2],&image->pal[pal_i+3],
                                &image->pal[pal_i+4],&image->pal[pal_i+5],&image->pal[pal_i+6],&image->pal[pal_i+7]);
                        pal_i += 8;
                    }
                }
                break;
        }
    }

    fprintf(log, "Finished parsing with %d tiles, %d maps blocks and %d palette entries\n", image->tilesLen, image->mapLen, image->palLen);

    fclose(f);
    fclose(log);

    return 0;
}

void dumpASM(char *path, ASM image) {
    FILE *f = fopen(path, "w");

    fprintf(f, "tiles:");
    for (int i = 0; i < image.tilesLen; i++) {
        if (!(i % 8)) fprintf(f, "\n");
        fprintf(f, "%08x,", image.tiles[i]);
    }
    fprintf(f, "\nmap:");
    for (int i = 0; i < image.mapLen; i++) {
        if (!(i % 8)) fprintf(f, "\n");
        int block = image.map.tile_num[i] | (image.map.hflip[i] << 10) | (image.map.vflip[i] << 11) | (image.map.palette[i] << 12);
        fprintf(f, "%04x,", block);
    }
    fprintf(f, "\npal:");
    for (int i = 0; i < image.palLen; i++) {
        if (!(i % 8)) fprintf(f, "\n");
        fprintf(f, "%04x,", image.pal[i]);
    }
    fprintf(f, "\n");

    fclose(f);
}

int main(int argc, char* argv[]){
    ASM image = {0};
    ParseMode mode = atoi(argv[2]);
    loadASM(argv[1], &image, mode);

    dumpASM("dump.s", image);

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

        int x = 0, y = 0;
        for (int i = 0; i < image.mapLen; i++) {
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 8; k++) {
                    int pal_index = image.tiles[image.map.tile_num[i]][k][j];
                    int color15 = image.mode == COLOR256 ? image.pal[pal_index] : image.pal[(image.map.palette[i] >> 4) + pal_index];

                    int r = color15 & 0x1F;
                    int g = (color15 >> 5) & 0x1F;
                    int b = (color15 >> 10) & 0x1F;

                    int color24 = b << 3 | g << 11 | r << 19;

                    int temp_x = k, temp_y = j;

                    if (image.map.hflip[i]) {
                        temp_x = 7 - temp_x;
                    }
                    if (image.map.vflip[i]) {
                        temp_y = 7 - temp_y;
                    }
                    putPixel(screenSurface, 8*x + temp_x, 8*y + temp_y, color24);
                }
            }
            x++;
            if (x == 32) { //32 map blocks -> 256 pixels
                x = 0;
                y++;
            }
        }

        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

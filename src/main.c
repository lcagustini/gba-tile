#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <string.h>
#include <stdint.h>

#include "types.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
TTF_Font *font = NULL;

ASM image = {0};

#include "asm-handler.c"
#include "tile.c"
#include "gfx.c"
#include "gui.c"

int tile = 0;
void nextTile() {
    tile++;
}
void previousTile() {
    if (tile > 0) tile--;
}

int main(int argc, char* argv[]){
    float zoom = 1;
    double screen_x = 0, screen_y = 0;
    bool update_screen = TRUE;
    SDL_Event e;

    initSDL();

    loadASM(argv[1], &image, atoi(argv[2]), atoi(argv[3]));
    exportASM("dump.s", image);

    UIWindow w = {0};
    {
        w.rect.x = 300;
        w.rect.y = 300;
        w.rect.w = 320;
        w.rect.h = 240;

        char l[] = "Tiles";
        strcpy(w.widgets[0].data.label.text, l);
        w.widgets[0].data.label.x = 10;
        w.widgets[0].data.label.y = 10;
        w.widgets[0].type = LABEL;

        w.widgets[1].data.tile.x = 10;
        w.widgets[1].data.tile.y = 50;
        w.widgets[1].data.tile.tile_num = 12;
        w.widgets[1].data.tile.palette = 0;
        w.widgets[1].data.tile.hflip = FALSE;
        w.widgets[1].data.tile.vflip = FALSE;
        w.widgets[1].type = TILE;

        w.widgets[2].data.button.rect.x = 50;
        w.widgets[2].data.button.rect.y = 140;
        w.widgets[2].data.button.rect.h = 10;
        w.widgets[2].data.button.rect.w = 10;
        w.widgets[2].data.button.args = NULL;
        w.widgets[2].data.button.callback = &previousTile;
        w.widgets[2].type = BUTTON;

        w.widgets[3].data.button.rect.x = 70;
        w.widgets[3].data.button.rect.y = 140;
        w.widgets[3].data.button.rect.h = 10;
        w.widgets[3].data.button.rect.w = 10;
        w.widgets[3].data.button.args = NULL;
        w.widgets[3].data.button.callback = &nextTile;
        w.widgets[3].type = BUTTON;

        w.widget_len = 4;
    }

    while(1){
        while(SDL_PollEvent(&e)){
            switch (e.type) {
                case SDL_QUIT:
                    goto exit;
                case SDL_MOUSEWHEEL:
                    zoom += e.wheel.y/10.0;
                    if (zoom < 1) zoom = 1;
                    update_screen = TRUE;
                    break;
                case SDL_MOUSEMOTION:
                    if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
                        screen_x += e.motion.xrel/zoom;
                        screen_y += e.motion.yrel/zoom;
                        update_screen = TRUE;
                    }
            }
            update_screen |= eventOnWindow(w, e);
        }

        int64_t start_time = SDL_GetPerformanceCounter();
        if (update_screen) {
            update_screen = FALSE;

            w.widgets[1].data.tile.tile_num = tile;

            setPosAndScale(screen_x, screen_y, zoom);

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);

            renderImage();

            setPosAndScale(0, 0, 1);
            drawWindow(w);

            SDL_RenderPresent(renderer);
        }
        int64_t elapsed_time = SDL_GetPerformanceCounter() - start_time;

        if (elapsed_time > 0) {
            SDL_Delay((double) (abs(elapsed_time) / (double) SDL_GetPerformanceFrequency()));
        }
    }

exit:
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

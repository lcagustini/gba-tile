#include <SDL2/SDL.h>

#include <string.h>
#include <stdint.h>

#include "types.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

ASM image = {0};

#include "asm-handler.c"
#include "gfx.c"

int main(int argc, char* argv[]){
    initSDL();

    loadASM(argv[1], &image, atoi(argv[2]), atoi(argv[3]));
    exportASM("dump.s", image);

    float zoom = 1;
    double screen_x = 0, screen_y = 0;

    bool update_screen = TRUE;
    SDL_Event e;
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
        }

        int64_t start_time = SDL_GetPerformanceCounter();
        if (update_screen) {
            update_screen = FALSE;
            renderImage(screen_x, screen_y, zoom);
        }
        int64_t elapsed_time = SDL_GetPerformanceCounter() - start_time;

        if (elapsed_time > 0) {
            SDL_Delay((double) (abs(elapsed_time) / (double) SDL_GetPerformanceFrequency()));
        }
    }

exit:
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

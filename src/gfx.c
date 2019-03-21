void initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    window = SDL_CreateWindow("gba-tile", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void putPixel(SDL_Surface *surface, int x, int y, uint32_t pixel){
    uint32_t *pixels = (uint32_t*)surface->pixels;
    pixels[(y*surface->w) + x] = pixel;
}

void renderImage(double screen_x, double screen_y, float zoom) {
    {
        SDL_RenderSetScale(renderer, zoom, zoom);
        SDL_Rect viewport = {.x = screen_x, .y = screen_y, .w = 0, .h = 0};
        SDL_GetWindowSize(window, &viewport.w, &viewport.h);
        SDL_RenderSetViewport(renderer, &viewport);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    int x = 0, y = 0;
    for (int i = 0; i < image.mapLen; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                int pal_index = image.tiles[image.map.tile_num[i]][k][j];
                int color15 = image.mode == COLOR256 ? image.pal[pal_index] : image.pal[(image.map.palette[i] << 4) + pal_index];

                int r = (color15 & 0x1F) << 3;
                int g = ((color15 >> 5) & 0x1F) << 3;
                int b = ((color15 >> 10) & 0x1F) << 3;

                int temp_x = k, temp_y = j;

                if (image.map.hflip[i]) {
                    temp_x = 7 - temp_x;
                }
                if (image.map.vflip[i]) {
                    temp_y = 7 - temp_y;
                }

                SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawPoint(renderer, 8*x + temp_x, 8*y + temp_y);
            }
        }
        x++;
        if (x == (image.size & 0b10 ? 64 : 32)) { //32 map blocks -> 256 pixels; 64 -> 512
            x = 0;
            y++;
        }
    }

    SDL_RenderPresent(renderer);
}

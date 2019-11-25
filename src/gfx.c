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
    if(TTF_Init() == -1) {
        printf("Failed to initialize TTF subsystem: %s\n", TTF_GetError());
    }
    if ((font = TTF_OpenFont("roboto.ttf", 28)) == NULL) {
        printf("Could not find font file\n");
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void setPosAndScale(double x, double y, float scale) {
    SDL_RenderSetScale(renderer, scale, scale);
    SDL_Rect viewport = {.x = x, .y = y, .w = 0, .h = 0};
    SDL_GetWindowSize(window, &viewport.w, &viewport.h);
    SDL_RenderSetViewport(renderer, &viewport);
}

void renderImage() {
    int x = 0, y = 0;
    for (int i = 0; i < image.mapLen; i++) {
        renderTile(8*x, 8*y,
                image.map.tile_num[i],
                image.map.palette[i],
                image.map.hflip[i],
                image.map.vflip[i]);
        x++;
        if (x == (image.size & 0b10 ? 64 : 32)) { //32 tiles -> 256 pixels; 64 -> 512
            x = 0;
            y++;
        }
    }
}

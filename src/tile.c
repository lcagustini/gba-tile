void renderTile(int x, int y, int num, int palette, bool hflip, bool vflip) {
    for (int j = 0; j < 8; j++) {
        for (int k = 0; k < 8; k++) {
            int pal_index = image.tiles[num][k][j];
            int color15 = image.mode == COLOR256 ? image.pal[pal_index] : image.pal[(palette << 4) + pal_index];

            int r = (color15 & 0x1F) << 3;
            int g = ((color15 >> 5) & 0x1F) << 3;
            int b = ((color15 >> 10) & 0x1F) << 3;

            int temp_x = k, temp_y = j;

            if (hflip) {
                temp_x = 7 - temp_x;
            }
            if (vflip) {
                temp_y = 7 - temp_y;
            }

            SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawPoint(renderer, x + temp_x, y + temp_y);
        }
    }
}

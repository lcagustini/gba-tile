int loadASM(char *path, ASM *image, ParseMode mode, ImageSize size) {
    FILE *f = fopen(path, "r");
    FILE *log = fopen("log", "w");

    if (!f) {
        printf("Failed to open file\n");
        return 1;
    }

    fprintf(log, "Reading file: %s\n", path);

    image->mode = mode;
    image->size = size;

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
                                image->tiles[tile_i][7][i] = 0xF & (words[i] >> 28);
                                image->tiles[tile_i][6][i] = 0xF & (words[i] >> 24);
                                image->tiles[tile_i][5][i] = 0xF & (words[i] >> 20);
                                image->tiles[tile_i][4][i] = 0xF & (words[i] >> 16);
                                image->tiles[tile_i][3][i] = 0xF & (words[i] >> 12);
                                image->tiles[tile_i][2][i] = 0xF & (words[i] >> 8);
                                image->tiles[tile_i][1][i] = 0xF & (words[i] >> 4);
                                image->tiles[tile_i][0][i] = 0xF & (words[i]);
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i += 2) {
                                image->tiles[tile_i][7][half+i/2] = 0xFF & (words[i+1] >> 24);
                                image->tiles[tile_i][6][half+i/2] = 0xFF & (words[i+1] >> 16);
                                image->tiles[tile_i][5][half+i/2] = 0xFF & (words[i+1] >> 8);
                                image->tiles[tile_i][4][half+i/2] = 0xFF & (words[i+1]);
                                image->tiles[tile_i][3][half+i/2] = 0xFF & (words[i] >> 24);
                                image->tiles[tile_i][2][half+i/2] = 0xFF & (words[i] >> 16);
                                image->tiles[tile_i][1][half+i/2] = 0xFF & (words[i] >> 8);
                                image->tiles[tile_i][0][half+i/2] = 0xFF & (words[i]);
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

                        sscanf(line, " .hword 0x%hx,0x%hx,0x%hx,0x%hx,0x%hx,0x%hx,0x%hx,0x%hx",
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

void exportASM(char *path, ASM image) {
    FILE *f = fopen(path, "w");

    fprintf(f, "tiles:\n    .word ");
    for (int i = 0; i < image.tilesLen; i++) {
        for (int j = 0; j < 8; j++) {
            if (image.mode == COLOR16) {
                int tile = (image.tiles[i][7][j] << 28);
                tile |= (image.tiles[i][6][j] << 24);
                tile |= (image.tiles[i][5][j] << 20);
                tile |= (image.tiles[i][4][j] << 16);
                tile |= (image.tiles[i][3][j] << 12);
                tile |= (image.tiles[i][2][j] << 8);
                tile |= (image.tiles[i][1][j] << 4);
                tile |= (image.tiles[i][0][j]);
                if (j < 7) {
                    fprintf(f, "0x%08x,", tile);
                }
                else {
                    fprintf(f, "0x%08x", tile);
                }
            }
            else {
                int tile = (image.tiles[i][3][j] << 24);
                tile |= (image.tiles[i][2][j] << 16);
                tile |= (image.tiles[i][1][j] << 8);
                tile |= (image.tiles[i][0][j]);
                fprintf(f, "0x%08x,", tile);

                tile = (image.tiles[i][7][j] << 24);
                tile |= (image.tiles[i][6][j] << 16);
                tile |= (image.tiles[i][5][j] << 8);
                tile |= (image.tiles[i][4][j]);
                if (j == 3 || j == 7) {
                    fprintf(f, "0x%08x", tile);
                }
                else {
                    fprintf(f, "0x%08x,", tile);
                }

                if (j == 3) fprintf(f, "\n    .word ");
            }
        }
        if (i < image.tilesLen-1) {
            fprintf(f, "\n    .word ");
        }
        else {
            fprintf(f, "\n");
        }
    }
    fprintf(f, "map:");
    for (int i = 0; i < image.mapLen; i++) {
        if (!(i % 8)) fprintf(f, "\n    .hword ");
        int block = image.map.tile_num[i] | (image.map.hflip[i] << 10) | (image.map.vflip[i] << 11) | (image.map.palette[i] << 12);
        if ((i+1) % 8) {
            fprintf(f, "0x%04x,", block);
        }
        else {
            fprintf(f, "0x%04x", block);
        }
    }
    fprintf(f, "\npal:");
    for (int i = 0; i < image.palLen; i++) {
        if (!(i % 8)) fprintf(f, "\n    .hword ");
        if ((i+1) % 8) {
            fprintf(f, "0x%04x,", image.pal[i]);
        }
        else {
            fprintf(f, "0x%04x", image.pal[i]);
        }
    }
    fprintf(f, "\n");

    fclose(f);
}

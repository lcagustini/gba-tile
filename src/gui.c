typedef enum {
    LABEL,
    TILE,
    BUTTON
} UIWidgetType;

typedef struct {
    char text[200];
    int x, y;
} UILabel;

typedef struct {
    int tile_num;
    int palette;
    bool hflip, vflip;
    int x, y;
} UITile;

typedef struct {
    SDL_Rect rect;

    void *args;
    void (*callback)();
} UIButton;

typedef struct {
    union {
        UILabel label;
        UITile tile;
        UIButton button;
    } data;
    UIWidgetType type;
} UIWidget;

typedef struct {
    SDL_Rect rect;

    UIWidget widgets[100];
    int widget_len;
} UIWindow;

void null() { return; }

bool eventOnWindow(UIWindow w, SDL_Event e) {
    bool r = FALSE;
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        if (e.button.button == SDL_BUTTON_LEFT) {
            for (int i = 0; i < w.widget_len; i++) {
                if (w.widgets[i].type == BUTTON) {
                    int x = w.rect.x + w.widgets[i].data.button.rect.x;
                    int y = w.rect.y + w.widgets[i].data.button.rect.y;
                    int xw = w.rect.x + w.widgets[i].data.button.rect.x + w.widgets[i].data.button.rect.w;
                    int yh = w.rect.y + w.widgets[i].data.button.rect.y + w.widgets[i].data.button.rect.h;

                    if (e.button.x > x && e.button.x < xw && e.button.y > y && e.button.y < yh) {
                        (*w.widgets[i].data.button.callback)(w.widgets[i].data.button.args);
                        r |= TRUE;
                    }
                }
            }
        }
    }
    return r;
}

void drawWindow(UIWindow w) {
    SDL_Color White = {255, 255, 255};

    SDL_SetRenderDrawColor(renderer, 100, 100, 100, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &w.rect);

    for (int i = 0; i < w.widget_len; i++) {
        switch (w.widgets[i].type) {
            case LABEL:
                {
                    setPosAndScale(0, 0, 1);
                    SDL_Surface *s = TTF_RenderText_Solid(font, w.widgets[i].data.label.text, White);
                    SDL_Texture *t = SDL_CreateTextureFromSurface(renderer, s);

                    SDL_Rect r = w.rect;
                    r.x += w.widgets[i].data.label.x;
                    r.y += w.widgets[i].data.label.y;
                    r.w = s->w;
                    r.h = s->h;
                    SDL_RenderCopy(renderer, t, NULL, &r);
                }
                break;
            case TILE:
                {
                    setPosAndScale(0, 0, 10);
                    renderTile((w.rect.x + w.widgets[i].data.tile.x)/10, (w.rect.y + w.widgets[i].data.tile.y)/10,
                                w.widgets[i].data.tile.tile_num, w.widgets[i].data.tile.palette,
                                w.widgets[i].data.tile.hflip, w.widgets[i].data.tile.vflip);
                }
                break;
            case BUTTON:
                {
                    setPosAndScale(0, 0, 1);
                    SDL_SetRenderDrawColor(renderer, 50, 50, 50, SDL_ALPHA_OPAQUE);
                    SDL_Rect r = w.rect;
                    r.x += w.widgets[i].data.button.rect.x;
                    r.y += w.widgets[i].data.button.rect.y;
                    r.w = w.widgets[i].data.button.rect.w;
                    r.h = w.widgets[i].data.button.rect.h;

                    SDL_RenderFillRect(renderer, &r);
                }
                break;
        }
    }
}

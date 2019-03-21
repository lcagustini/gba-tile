#define WIDTH 800
#define HEIGHT 800

#define bool uint8_t
#define TRUE 1
#define FALSE 0

typedef struct {
    uint16_t tile_num[262144];
    bool hflip[262144];
    bool vflip[262144];
    uint8_t palette[262144];
} Map;

typedef enum {
    COLOR16,
    COLOR256,
} ParseMode;

typedef enum {
    SIZE256x256 = 0b00,
    SIZE512x256 = 0b10,
    SIZE256x512 = 0b01,
    SIZE512x512 = 0b11,
} ImageSize;

typedef struct {
    uint8_t tiles[1024][8][8];
    int tilesLen;

    Map map;
    int mapLen;

    uint16_t pal[256];
    int palLen;

    ParseMode mode;
    ImageSize size;
} ASM;

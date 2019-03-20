
//{{BLOCK(hud)

//======================================================================
//
//	hud, 256x256@4, 
//	Transparent color : FF,00,FF
//	+ palette 16 entries, not compressed
//	+ 67 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 2144 + 2048 = 4224
//
//	Time-stamp: 2019-02-26, 22:38:10
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.15
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_HUD_H
#define GRIT_HUD_H

#define hudTilesLen 2144
extern const unsigned int hudTiles[536];

#define hudMapLen 2048
extern const unsigned short hudMap[1024];

#define hudPalLen 32
extern const unsigned short hudPal[16];

#endif // GRIT_HUD_H

//}}BLOCK(hud)


//{{BLOCK(paused)

//======================================================================
//
//	paused, 256x256@4, 
//	Transparent color : FF,00,FF
//	+ palette 16 entries, not compressed
//	+ 87 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 2784 + 2048 = 4864
//
//	Time-stamp: 2019-02-21, 10:33:23
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.15
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PAUSED_H
#define GRIT_PAUSED_H

#define pausedTilesLen 2784
extern const unsigned int pausedTiles[696];

#define pausedMapLen 2048
extern const unsigned short pausedMap[1024];

#define pausedPalLen 32
extern const unsigned short pausedPal[16];

#endif // GRIT_PAUSED_H

//}}BLOCK(paused)


@{{BLOCK(paused)

@=======================================================================
@
@	paused, 256x256@4, 
@	Transparent color : FF,00,FF
@	+ palette 16 entries, not compressed
@	+ 87 tiles (t|f|p reduced) not compressed
@	+ regular map (flat), not compressed, 32x32 
@	Total size: 32 + 2784 + 2048 = 4864
@
@	Time-stamp: 2019-02-21, 10:33:23
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.15
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global pausedTiles		@ 2784 unsigned chars
	.hidden pausedTiles
pausedTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x10000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x22222000,0x33333332,0x55554433
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00222222,0x02333333,0x03455555
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x20000000,0x33320000,0x44331000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x22222222,0x33333333,0x55555555
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x22000022,0x33200213,0x54320135
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00002222,0x00023333,0x00034555

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x02222220,0x23333332,0x34555543
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x12000000,0x33100000,0x54330000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x01333333,0x33344444,0x34555555
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000002,0x00000013
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x22200000,0x33333200,0x55443330
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x22222220,0x33333332,0x55555543
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00002222,0x02333333,0x33344555
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000002

	.word 0x31000000,0x43100000,0x54320000,0x55330000,0x55430000,0x55430000,0x55432000,0x55432000
	.word 0x55555554,0x55555555,0x55555555,0x55555555,0x33345555,0x33333555,0x32023455,0x32003455
	.word 0x03455555,0x03455555,0x03455555,0x03455555,0x03455554,0x03455554,0x23455554,0x23455554
	.word 0x55543100,0x55554310,0x55555432,0x55555533,0x55555543,0x35555543,0x34555543,0x34555543
	.word 0x55555555,0x55555555,0x55555555,0x55555555,0x55553334,0x55553333,0x55553102,0x55553100
	.word 0x55320135,0x55320135,0x55320135,0x55320135,0x55320135,0x55320135,0x55320135,0x55320135
	.word 0x00034555,0x00034555,0x00034555,0x00034555,0x00034555,0x00034555,0x00034555,0x00034555
	.word 0x34555543,0x34555543,0x34555543,0x34555543,0x34555543,0x34555543,0x34555543,0x34555543

	.word 0x55433000,0x55543100,0x55554320,0x55555310,0x55555330,0x55555430,0x55555430,0x55555430
	.word 0x55555555,0x55555555,0x55555555,0x55554455,0x55533334,0x55432233,0x55430023,0x55430023
	.word 0x00000134,0x10002345,0x32003355,0x33023455,0x43023455,0x43023555,0x43223555,0x53223555
	.word 0x55555433,0x55555543,0x55555554,0x55555555,0x34555555,0x33355555,0x02345555,0x00345555
	.word 0x03455555,0x03455555,0x03455555,0x03455555,0x01333333,0x00111113,0x00000000,0x00000000
	.word 0x55555543,0x55555543,0x55555543,0x55555543,0x35555543,0x35555543,0x35555543,0x35555543
	.word 0x34555555,0x45555555,0x55555555,0x55555555,0x55555433,0x55553333,0x55543202,0x55543002
	.word 0x00000023,0x00000033,0x00000134,0x00000335,0x00000345,0x00002345,0x00002355,0x00002355

	.word 0x55532000,0x55532000,0x55532000,0x55532000,0x55532000,0x55532000,0x55532000,0x55532000
	.word 0x32003455,0x32003455,0x32003455,0x31003455,0x33003455,0x43003355,0x43203355,0x53103355
	.word 0x23455554,0x23455555,0x23455555,0x23355555,0x21355555,0x21355555,0x22355555,0x22345555
	.word 0x34555553,0x34555553,0x34555553,0x34555553,0x34555553,0x34555553,0x34555553,0x34555553
	.word 0x55553100,0x55553100,0x55553100,0x55553100,0x55553100,0x55553100,0x55553100,0x55553100
	.word 0x55555430,0x55555430,0x55555430,0x55555430,0x55555330,0x55555310,0x55554320,0x55543100
	.word 0x55430023,0x55430023,0x55430013,0x55430033,0x55430134,0x55431345,0x44333455,0x33334555
	.word 0x53223555,0x53223555,0x53223555,0x53223555,0x53223555,0x53223555,0x53223344,0x53202333

	.word 0x00345555,0x00345555,0x00345555,0x00345555,0x00345555,0x00345555,0x00345555,0x00345555
	.word 0x55543002,0x55543002,0x55543002,0x55543002,0x55543002,0x55543002,0x55543002,0x55543002
	.word 0x00002355,0x00002355,0x00002355,0x00002355,0x00002355,0x00002355,0x00002355,0x00002355
	.word 0x53301355,0x54321355,0x55331355,0x55431355,0x55543355,0x55554355,0x55555555,0x55555555
	.word 0x20345555,0x20335555,0x20234555,0x20034555,0x20013555,0x20023455,0x20001345,0x20000334
	.word 0x34555553,0x34555553,0x34555553,0x34555553,0x34555553,0x44555553,0x55555553,0x55555553
	.word 0x55553100,0x55553100,0x55553100,0x55553100,0x55553333,0x55554444,0x55555555,0x55555555
	.word 0x55533000,0x55332000,0x53320000,0x33200000,0x32000000,0x20000000,0x00000000,0x00000000

	.word 0x23345555,0x33455555,0x35555555,0x55555554,0x55555543,0x55555433,0x55554310,0x55543100
	.word 0x53200000,0x53200002,0x53200023,0x53200033,0x53200334,0x53202345,0x53203355,0x53223455
	.word 0x33345555,0x44455555,0x55555555,0x55555555,0x55555555,0x55555555,0x44445555,0x33345555
	.word 0x00333333,0x03444444,0x03455555,0x03455555,0x03455555,0x03455555,0x03344444,0x00333333
	.word 0x45555555,0x34555555,0x33455555,0x01334555,0x00233455,0x00003455,0x00003455,0x00003455
	.word 0x20000233,0x20000023,0x20000002,0x20000000,0x20000000,0x20000000,0x20000000,0x20000000
	.word 0x55555553,0x55555553,0x45555553,0x34555553,0x34555553,0x34555553,0x34555553,0x34555553
	.word 0x00000000,0x00000000,0x00000000,0x33333300,0x44444330,0x55555430,0x55555430,0x55555430

	.word 0x55533000,0x55432000,0x55430000,0x55430002,0x55430023,0x55430023,0x55430023,0x55430023
	.word 0x53223555,0x53223555,0x53223555,0x53223555,0x53223555,0x53223555,0x53223555,0x53223555
	.word 0x00003455,0x00003455,0x00003455,0x00003455,0x00003455,0x00003455,0x00003455,0x00003455
	.word 0x20000000,0x20000000,0x20000000,0x20000000,0x20000000,0x20000000,0x20000000,0x20000000
	.word 0x55320135,0x55320135,0x55320135,0x55320135,0x54320135,0x54320135,0x54300135,0x53300135
	.word 0x00034555,0x00034555,0x00034555,0x20034555,0x20034555,0x10234555,0x33335555,0x43455555
	.word 0x34555543,0x34555543,0x34555543,0x34555543,0x34555553,0x34555553,0x33555554,0x13555555
	.word 0x55555430,0x55555430,0x55555430,0x55555430,0x55555430,0x55555430,0x55555330,0x55555310

	.word 0x55430023,0x55430023,0x55430023,0x55430023,0x55430023,0x55432033,0x55533334,0x55554445
	.word 0x53223555,0x53223555,0x53223555,0x53223555,0x53223555,0x53223555,0x53223555,0x53223455
	.word 0x00345555,0x00345555,0x00345555,0x00345555,0x00345555,0x22345555,0x33345555,0x55555555
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x02222222,0x22333333,0x23455555
	.word 0x35555543,0x35555543,0x35555543,0x35555543,0x35555543,0x35555543,0x35555543,0x55555543
	.word 0x55543002,0x55543002,0x55543002,0x55543002,0x55543202,0x55553312,0x55554333,0x55555555
	.word 0x00002355,0x00002355,0x00002355,0x00002355,0x00002355,0x00002345,0x00002345,0x00000345
	.word 0x55532000,0x55532000,0x55532000,0x55532000,0x33332000,0x33320000,0x00000000,0x00000000

	.word 0x00003455,0x00003455,0x00003455,0x00003455,0x00003333,0x00000333,0x00000000,0x00000000
	.word 0x20000000,0x20000000,0x20000000,0x20000000,0x20000000,0x00000000,0x00000000,0x00000000
	.word 0x34555553,0x34555553,0x34555553,0x34555553,0x33333333,0x03333332,0x00000000,0x00000000
	.word 0x55553100,0x55553100,0x55553100,0x55553100,0x33333100,0x33331000,0x00000000,0x00000000
	.word 0x43100135,0x43000135,0x31000135,0x10000135,0x00000133,0x00000013,0x00000000,0x00000000
	.word 0x55555555,0x55555555,0x55555554,0x55555543,0x45544331,0x33333320,0x22220000,0x00000000
	.word 0x23455555,0x03355555,0x02345555,0x00234555,0x00023344,0x00002133,0x00000002,0x00000000
	.word 0x55554320,0x55553300,0x55533200,0x54332000,0x33320000,0x31000000,0x00000000,0x00000000

	.word 0x55555555,0x55555555,0x55555555,0x45555555,0x33445544,0x23333333,0x00022222,0x00000000
	.word 0x53203355,0x53202345,0x53200134,0x53200013,0x33200001,0x32000000,0x00000000,0x00000000
	.word 0x55555555,0x55555555,0x55555555,0x55555555,0x33333333,0x33333333,0x00000000,0x00000000
	.word 0x23555555,0x23555555,0x23555555,0x23555555,0x23333333,0x02333333,0x00000000,0x00000000
	.word 0x55555543,0x55555543,0x55555543,0x55555543,0x33333333,0x33333330,0x00000000,0x00000000
	.word 0x55555555,0x55555555,0x35555555,0x33445555,0x23333333,0x00221133,0x00000000,0x00000000
	.word 0x00000134,0x00000233,0x00000023,0x00000002,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global pausedMap		@ 2048 unsigned chars
	.hidden pausedMap
pausedMap:
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001
	.hword 0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0009
	.hword 0x000A,0x000B,0x000C,0x0003,0x000D,0x000E,0x000F,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0010
	.hword 0x0011,0x0012,0x0013,0x0014,0x0015,0x0016,0x0017,0x0018
	.hword 0x0019,0x001A,0x001B,0x001C,0x001D,0x001E,0x001F,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0020
	.hword 0x0021,0x0022,0x0023,0x0024,0x0015,0x0016,0x0017,0x0025
	.hword 0x0026,0x0027,0x0028,0x0000,0x0423,0x0029,0x002A,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0020
	.hword 0x002B,0x002C,0x002D,0x002E,0x0015,0x0016,0x0017,0x002F
	.hword 0x0030,0x0031,0x0032,0x0033,0x0423,0x0029,0x002A,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0020
	.hword 0x0034,0x0035,0x0036,0x082E,0x0015,0x0016,0x0017,0x0037
	.hword 0x0038,0x0039,0x0028,0x0000,0x0423,0x0029,0x002A,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0020
	.hword 0x003A,0x003B,0x0023,0x0024,0x003C,0x003D,0x003E,0x003F
	.hword 0x0040,0x0041,0x0042,0x0043,0x0044,0x0045,0x0046,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0047
	.hword 0x0048,0x0049,0x004A,0x004B,0x004C,0x004D,0x004E,0x004F
	.hword 0x0050,0x0051,0x0052,0x0053,0x0054,0x0055,0x0056,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.section .rodata
	.align	2
	.global pausedPal		@ 32 unsigned chars
	.hidden pausedPal
pausedPal:
	.hword 0x7C1F,0x2809,0x5014,0x0421,0x4230,0x77DD,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(paused)
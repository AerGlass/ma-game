
/*
-------------------------------------------------
	Includes
-------------------------------------------------
*/

// Includes C
#include <stdio.h>

// Includes propietarios NDS
#include <nds.h>

// Includes librerias propias
#include <nf_lib.h>
#include "intro.h"
#include <unistd.h>

int mini(int c, int d){
	// Pantalla de espera inicializando NitroFS
	NF_Set2D(0, 0);
	NF_Set2D(1, 0);	
	consoleDemoInit();
	swiWaitForVBlank();
	printf("Loading... If it hangs then use a freaking r4 card and not nds-bootstrap.");
	u16 Pressed;
	u16 Held;
	NF_SetRootFolder("NITROFS");
	NF_Set2D(0, 0);//poner 2d en la pantalla de arriba

	consoleClear();
	float ballpx = 0;
	float ballpy = 0;
	float mapx = 0;
	float tmpx = 0;
	float tmpxa = 0;
	// Inicializa los fondos tileados
	NF_InitTiledBgBuffers();	// Inicializa los buffers para almacenar fondos
	NF_InitTiledBgSys(0);		// Inicializa los fondos Tileados para la pantalla superior
	// Inicializa los Sprites
	NF_InitSpriteBuffers();		// Inicializa los buffers para almacenar sprites y paletas
	NF_InitSpriteSys(0);		// Inicializa los sprites para la pantalla superior
	NF_InitSpriteSys(1);		// Inicializa los sprites para la pantalla superior
	NF_InitTextSys(0); //iniciar el motor de teclado en la pantalla superior
	NF_InitRawSoundBuffers();
	
	NF_LoadTextFont("default", "normal", 256, 256, 0);	// Carga la seccion "normal" de la fuente, tamaño del mapa 256x256
	NF_CreateTextLayer(0, 0, 0,	"normal"); // crear capa de texto

	NF_LoadTiledBg("background_intro", "bg3", 256, 256);
	NF_CreateTiledBg(0, 3, "bg3");

	NF_LoadSpriteGfx("maduro", 0, 64, 64);
	NF_LoadSpritePal("maduro", 0);
	NF_VramSpriteGfx(0, 0, 0, 0);
	NF_VramSpritePal(0, 0, 0);
	NF_CreateSprite(0, 0, 0, 0, 0, 0);
	
	NF_LoadSpriteGfx("whiteball", 1, 16, 16);
	NF_LoadSpritePal("whiteball", 1);
	NF_VramSpriteGfx(0, 1, 1, 1);
	NF_VramSpritePal(0, 1, 1);
	NF_CreateSprite(0, 1, 1, 1, ballpx, ballpy);
	ballpy = 144;
	float masp = 1;
	NF_LoadRawSound("sfx/line", 1, 11025, 0); //mas basura :DDDD
	while(1) {
	scanKeys();
	Pressed = keysDown();
	Held = keysHeld();
	if(mapx > 256) mapx = 0;
	if(Pressed & KEY_B) {
	NF_PlayRawSound(1, 127, 127, false, 0); //efecto de sonido para oido derecho
	NF_PlayRawSound(1, 127, 0, false, 0); //efecto de sonido para oido isquierdo
	for (int i = 0; i < 75; i++){
			if(mapx > 256) mapx = 0;
			scanKeys();
			Held = keysHeld();
			ballpy += 2.0;
			if(ballpy < 0) ballpy = 0;
			mapx += masp;
			ballpy -= 4.0;
			
			tmpx = mapx - 0;
			tmpxa = mapx + 30;
			
			if(ballpy < 5 && masp > 1) masp -= 0.1;
			if(ballpy < 50 && ballpx>(tmpx) && ballpx<tmpxa) {NF_DeleteSprite(0, 0);
			masp += 0.1;
			mapx = 0;
			NF_WriteText(0, 0, 0, 0, "You Won!!!");	// escribir texto a la pantalla
			for(int b = 0; b < 100; b++){
				swiWaitForVBlank();
				NF_UpdateTextLayers();
			}
			NF_ClearTextLayer(0, 0);
			NF_UpdateTextLayers();
			NF_CreateSprite(0, 0, 0, 0, 0, 0);
			break;

			}
			if(Held & KEY_RIGHT) ballpx += 2.0;
			if(Held & KEY_LEFT) ballpx -= 2.0;
			NF_MoveSprite(0, 0, mapx, false);
			NF_MoveSprite(0, 1, ballpx, ballpy);
			NF_SpriteOamSet(0);				// Actualiza el Array del OAM
			swiWaitForVBlank();				// Espera al sincronismo vertical
			oamUpdate(&oamMain);			// Actualiza a VRAM el OAM Secundario
		}
	}

	if(Pressed & KEY_A) {
	
	NF_PlayRawSound(1, 127, 127, false, 0); //efecto de sonido para oido derecho
	NF_PlayRawSound(1, 127, 0, false, 0); //efecto de sonido para oido isquierdo
	for (int i = 0; i < 75; i++){
			if(mapx > 256) mapx = 0;
			scanKeys();
			Held = keysHeld();
			ballpy += 2.0;
			if(ballpy < 0) ballpy = 0;
			mapx += masp;
			ballpy -= 4.0;
			
			tmpx = mapx - 0;
			tmpxa = mapx + 30;
			
			if(ballpy < 5 && masp > 1) masp -= 0.1;
			if(ballpy < 50 && ballpx>(tmpx) && ballpx<tmpxa){NF_DeleteSprite(0, 0);
			masp += 0.1;
			mapx = 0;
			NF_WriteText(0, 0, 0, 0, "You Won!!!");	// escribir texto a la pantalla
			NF_UpdateTextLayers();
			//sleep(2);
			for(int i = 0; i < 200; i ++) swiWaitForVBlank();
			NF_ClearTextLayer(0, 0);
			NF_UpdateTextLayers();
			NF_CreateSprite(0, 0, 0, 0, 0, 0);
			break;

			}
			if(Held & KEY_RIGHT) ballpx += 2.0;
			if(Held & KEY_LEFT) ballpx -= 2.0;
			NF_MoveSprite(0, 0, mapx, false);
			NF_MoveSprite(0, 1, ballpx, ballpy);
			NF_SpriteOamSet(0);				// Actualiza el Array del OAM
			swiWaitForVBlank();				// Espera al sincronismo vertical
			oamUpdate(&oamMain);			// Actualiza a VRAM el OAM Secundario
		}
	}
	if(ballpx < 0) ballpx = 0;
	if(ballpx > 256) ballpx = 256;
	mapx += masp;
	tmpx = mapx - 0;
	tmpxa = mapx + 30;
	NF_MoveSprite(0, 0, mapx, false);
	NF_MoveSprite(0, 1, ballpx, ballpy);
	ballpy = 144;
	if(Held & KEY_RIGHT) ballpx += 2.0;
	if(Held & KEY_LEFT) ballpx -= 2.0;
	NF_SpriteOamSet(0);				// Actualiza el Array del OAM
	oamUpdate(&oamMain);			// Actualiza a VRAM el OAM Secundario
	swiWaitForVBlank();				// Espera al sincronismo vertical
	}
return c+d;
}

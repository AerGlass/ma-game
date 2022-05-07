
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
#include "mini.h"

int intro(){
	// Inicializa los fondos tileados
	NF_InitTiledBgBuffers();	// Inicializa los buffers para almacenar fondos
	NF_InitTiledBgSys(0);		// Inicializa los fondos Tileados para la pantalla superior
	NF_LoadTiledBg("background_intro", "bg3", 256, 256);
	printf("loaded bg /n");
	NF_CreateTiledBg(0, 3, "bg3");
	printf("created tiledbg/n");

	NF_LoadTextFont("default", "normal", 256, 256, 0);	// Carga la seccion "normal" de la fuente, tamaño del mapa 256x256
	NF_CreateTextLayer(0, 0, 0,	"normal"); // crear capa de texto

	NF_WriteText(0, 0, 0, 0, "Ma");	// escribir texto a la pantalla
	NF_WriteText(0, 0, 0, 2, "Press A to play");	// escribir texto a la pantalla

	NF_UpdateTextLayers();
	while(1) {
	scanKeys();
	if(keysDown()& KEY_A) {
		mini();
		return 0;
	}
	swiWaitForVBlank();
	}
	return a+b;
}

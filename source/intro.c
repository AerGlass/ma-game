
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

int intro(int a, int b){
	int c, d;
	// Pantalla de espera inicializando NitroFS
	NF_Set2D(0, 0);
	NF_Set2D(1, 0);	
	consoleDemoInit();
	swiWaitForVBlank();
	printf("Loading...");
	u16 Pressed;
	// Define el ROOT e inicializa el sistema de archivos
	NF_SetRootFolder("NITROFS");	// Define la carpeta ROOT para usar NITROFS

	// Inicializa el motor 2D
	NF_Set2D(0, 0);				// Modo 2D_0 en ambas pantallas
	NF_Set2D(1, 0);

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
	Pressed = keysDown();
	if(Pressed & KEY_A) {
		printf("%d + %d = %d", c, d, mini(c, d));
		return 0;
	}
	swiWaitForVBlank();
	}
return a+b;
}

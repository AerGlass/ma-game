
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
 /*
-------------------------------------------------
	Main() - Bloque general del programa
-------------------------------------------------
*/
int main(int argc, char **argv) {
	consoleDemoInit();
	intro();
	return 0; 

}

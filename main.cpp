#include <vitasdk.h>
#include <stdio.h>
#include <stdlib.h>

// Configuración inicial de la burbuja en tu PlayStation Vita
#define TITLE_ID "ZOMBIE001"
#define GAME_NAME "Zombie Attack! Second Wave XL Port"

int main(int argc, char *argv[]) {
    // Configurar los controles analógicos de la PS Vita
    sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG);
    
    // Aquí es donde se programará el cargador del archivo 'zombies2' de iOS
    printf("Iniciando cargador para: %s\n", GAME_NAME);
    
    // Bucle principal (Evita que la consola se congele)
    while (1) {
        SceCtrlData pad;
        sceCtrlPeekBufferPositive(0, &pad, 1);
        
        // Si presionas el botón START, el juego se cierra de forma segura en la Vita
        if (pad.buttons & SCE_CTRL_START)
            break;
            
        sceKernelDelayThread(16 * 1000); // Mantiene el juego estable a ~60 FPS
    }

    sceKernelExitProcess(0);
    return 0;
}

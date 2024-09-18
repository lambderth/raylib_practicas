#include "raylib.h"

// Definir constantes
#define ANCHO_PANTALLA 800
#define ALTO_PANTALLA 600
#define TAMANO_RECT 50
#define VELOCIDAD_RECT 5

//------------------------------------------------------------------------------------
// Punto de entrada principal del programa
//------------------------------------------------------------------------------------
int main(void)
{
    // Inicialización
    //--------------------------------------------------------------------------------------
    // Función para inicializar la ventana (ancho, alto, titulo)
    InitWindow(ANCHO_PANTALLA, ALTO_PANTALLA, "raylib Practica #3 - Animación básica.");

    // Configurar la posición del objeto
    Vector2 posicionRect = { ANCHO_PANTALLA / 2 - TAMANO_RECT / 2, ALTO_PANTALLA / 2 - TAMANO_RECT / 2 };
    float velocidadRect = VELOCIDAD_RECT;

    SetTargetFPS(60);               // Establecer que el juego corra a 60 cuadros por segundo
    //--------------------------------------------------------------------------------------

    // Bucle principal del juego
    while (!WindowShouldClose())    // Detecta cuando se presiona la tecla ESC o el botón de cerrar ventana
    {
        // Actualizar
        //----------------------------------------------------------------------------------
        // Mover el objeto horizontalmente
        posicionRect.x += velocidadRect;

        // Cambiar la dirección del movimiento cuando el objeto llega a los bordes
//        if (posicionRect.x <= 0 || posicionRect.x >= ANCHO_PANTALLA - TAMANO_RECT)
//        {
//            velocidadRect *= -1; // Cambiar la dirección del movimiento
//        }

        if (posicionRect.x >= ANCHO_PANTALLA)
        {
            posicionRect.x = 0;
//            posicionRect.y = GetRandomValue(0, ALTO_PANTALLA - TAMANO_RECT);
        }
        //----------------------------------------------------------------------------------

        // Dibujar
        //----------------------------------------------------------------------------------
        BeginDrawing();             // Comienza a "dibujar"

            // Limpiar la pantalla con un color sólido
            ClearBackground(BLACK);

            // Dibujar el objeto
            DrawRectangleV(posicionRect, (Vector2){ TAMANO_RECT, TAMANO_RECT }, RED);

        EndDrawing();               // Finalizar el dibujo
        //----------------------------------------------------------------------------------
    }

    // Cierre del programa
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Cerrar la ventana y el contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;
}

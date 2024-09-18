#include "raylib.h"

/*
1.Setup
2.Dibujo
3.Update
*/

//------------------------------------------------------------------------------------
// Punto de entrada principal del programa
//------------------------------------------------------------------------------------
int main(void)
{
    // Inicializaci�n
    //--------------------------------------------------------------------------------------
    const int anchoVentana = 800;   // Definir el ancho de la ventana, en pixeles.
    const int altoVentana = 450;    // Definir el alto de la ventana, en pixeles.

    // Funci�n para inicializar la ventana (ancho, alto, titulo)
    InitWindow(anchoVentana, altoVentana, "raylib Practica #1 - Creaci�n de ventana b�sica.");

    SetTargetFPS(60);               // Establecer que el juego corra a 60 cuadros por segundo
    //--------------------------------------------------------------------------------------

    // Bucle principal del juego
    while (!WindowShouldClose())    // Detecta cuando se presiona la tecla ESC o el bot�n de cerrar ventana
    {
        // Actualizar
        //----------------------------------------------------------------------------------
        // Para hacer aqu�: Actualizar las variables aqu�
        //----------------------------------------------------------------------------------

        // Dibujar
        //----------------------------------------------------------------------------------
        BeginDrawing();             // Comienza a "dibujar"

            // Limpiar la pantalla con un color s�lido
            ClearBackground(RAYWHITE);

            // "Dibujar" texto en la pantalla
            DrawText("Creaste tu primera ventana! :)", 250, 200, 20, LIGHTGRAY);

        EndDrawing();               // Finalizar el dibujo
        //----------------------------------------------------------------------------------
    }

    // Cierre del programa
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Cerrar la ventana y el contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;
}

/* Actividades:
    -Modificar el color de fondo o el texto mostrado
    -Experimentar con diferentes resoluciones
*/

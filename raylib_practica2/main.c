#include "raylib.h"

//------------------------------------------------------------------------------------
// Punto de entrada principal del programa
//------------------------------------------------------------------------------------
int main(void)
{
    // Inicializaci�n
    //--------------------------------------------------------------------------------------
    const int anchoVentana = 800;   // Definir el ancho de la ventana, en pixeles.
    const int altoVentana = 600;    // Definir el alto de la ventana, en pixeles.

    // Funci�n para inicializar la ventana (ancho, alto, titulo)
    InitWindow(anchoVentana, altoVentana, "raylib Practica #2 - Dibujo de formas b�sicas y manejo de eventos.");

    // Establecer el color del fondo y lsa posiciones de las formas.
    Color colorFondo = BLACK;
    Vector2 posicionCirculo = { 400, 300 };
    Vector2 posicionRectangulo = { 200, 150 };
    Vector2 lineaInicio = { 100, 100 };
    Vector2 lineaFin = { 700, 500 };

    SetTargetFPS(60);               // Establecer que el juego corra a 60 cuadros por segundo
    //--------------------------------------------------------------------------------------

    // Bucle principal del juego
    while (!WindowShouldClose())    // Detecta cuando se presiona la tecla ESC o el bot�n de cerrar ventana
    {
        // Actualizar
        //----------------------------------------------------------------------------------
        // Manejo de eventos del teclado
        if (IsKeyPressed(KEY_R)) colorFondo = RED; // Cambiar color de fondo a rojo
        if (IsKeyPressed(KEY_G)) colorFondo = GREEN; // Cambiar color de fondo a verde
        if (IsKeyPressed(KEY_B)) colorFondo = BLUE; // Cambiar color de fondo a azul

        if (IsKeyDown(KEY_RIGHT)) posicionCirculo.x += 5; // Mover c�rculo a la derecha
        if (IsKeyDown(KEY_LEFT)) posicionCirculo.x -= 5; // Mover c�rculo a la izquierda
        if (IsKeyDown(KEY_UP)) posicionCirculo.y -= 5; // Mover c�rculo hacia arriba
        if (IsKeyDown(KEY_DOWN)) posicionCirculo.y += 5; // Mover c�rculo hacia abajo

        if (IsKeyDown(KEY_W)) posicionRectangulo.y -= 5; // Mover rect�ngulo hacia arriba
        if (IsKeyDown(KEY_S)) posicionRectangulo.y += 5; // Mover rect�ngulo hacia abajo
        if (IsKeyDown(KEY_A)) posicionRectangulo.x -= 5; // Mover rect�ngulo a la izquierda
        if (IsKeyDown(KEY_D)) posicionRectangulo.x += 5; // Mover rect�ngulo a la derecha
        //----------------------------------------------------------------------------------

        // Dibujar
        //----------------------------------------------------------------------------------
        BeginDrawing();             // Comienza a "dibujar"

            // Limpiar la pantalla con un color s�lido (negro en este caso)
            ClearBackground(colorFondo);

            // Dibujar el c�rculo
            DrawCircleV(posicionCirculo, 50, RED);

            // Dibujar el rect�ngulo
            DrawRectangleV(posicionRectangulo, (Vector2){ 100, 50 }, GREEN);

            // Dibujar la l�nea
            DrawLineV(lineaInicio, lineaFin, BLUE);


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
    -Modificar tama�os y colores
    -A�adir m�s formas

    -DIFICILDIFICL: Implementar un sistema de puntuaci�n o niveles.
    Las formas deben ser movidas a una posicion al azar para "ganar puntos". Mostrar esta puntuaci�n en la pantalla.
*/

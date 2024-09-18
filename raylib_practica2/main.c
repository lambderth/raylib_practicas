#include "raylib.h"

//------------------------------------------------------------------------------------
// Punto de entrada principal del programa
//------------------------------------------------------------------------------------
int main(void)
{
    // Inicialización
    //--------------------------------------------------------------------------------------
    const int anchoVentana = 800;   // Definir el ancho de la ventana, en pixeles.
    const int altoVentana = 600;    // Definir el alto de la ventana, en pixeles.

    // Función para inicializar la ventana (ancho, alto, titulo)
    InitWindow(anchoVentana, altoVentana, "raylib Practica #2 - Dibujo de formas básicas y manejo de eventos.");

    // Establecer el color del fondo y lsa posiciones de las formas.
    Color colorFondo = BLACK;
    Vector2 posicionCirculo = { 400, 300 };
    Vector2 posicionRectangulo = { 200, 150 };
    Vector2 lineaInicio = { 100, 100 };
    Vector2 lineaFin = { 700, 500 };

    SetTargetFPS(60);               // Establecer que el juego corra a 60 cuadros por segundo
    //--------------------------------------------------------------------------------------

    // Bucle principal del juego
    while (!WindowShouldClose())    // Detecta cuando se presiona la tecla ESC o el botón de cerrar ventana
    {
        // Actualizar
        //----------------------------------------------------------------------------------
        // Manejo de eventos del teclado
        if (IsKeyPressed(KEY_R)) colorFondo = RED; // Cambiar color de fondo a rojo
        if (IsKeyPressed(KEY_G)) colorFondo = GREEN; // Cambiar color de fondo a verde
        if (IsKeyPressed(KEY_B)) colorFondo = BLUE; // Cambiar color de fondo a azul

        if (IsKeyDown(KEY_RIGHT)) posicionCirculo.x += 5; // Mover círculo a la derecha
        if (IsKeyDown(KEY_LEFT)) posicionCirculo.x -= 5; // Mover círculo a la izquierda
        if (IsKeyDown(KEY_UP)) posicionCirculo.y -= 5; // Mover círculo hacia arriba
        if (IsKeyDown(KEY_DOWN)) posicionCirculo.y += 5; // Mover círculo hacia abajo

        if (IsKeyDown(KEY_W)) posicionRectangulo.y -= 5; // Mover rectángulo hacia arriba
        if (IsKeyDown(KEY_S)) posicionRectangulo.y += 5; // Mover rectángulo hacia abajo
        if (IsKeyDown(KEY_A)) posicionRectangulo.x -= 5; // Mover rectángulo a la izquierda
        if (IsKeyDown(KEY_D)) posicionRectangulo.x += 5; // Mover rectángulo a la derecha
        //----------------------------------------------------------------------------------

        // Dibujar
        //----------------------------------------------------------------------------------
        BeginDrawing();             // Comienza a "dibujar"

            // Limpiar la pantalla con un color sólido (negro en este caso)
            ClearBackground(colorFondo);

            // Dibujar el círculo
            DrawCircleV(posicionCirculo, 50, RED);

            // Dibujar el rectángulo
            DrawRectangleV(posicionRectangulo, (Vector2){ 100, 50 }, GREEN);

            // Dibujar la línea
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
    -Modificar tamaños y colores
    -Añadir más formas

    -DIFICILDIFICL: Implementar un sistema de puntuación o niveles.
    Las formas deben ser movidas a una posicion al azar para "ganar puntos". Mostrar esta puntuación en la pantalla.
*/

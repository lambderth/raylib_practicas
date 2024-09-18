#include <raylib.h>

int main(void)
{
    // Inicializar la ventana
    InitWindow(800, 600, "Raylib - Formas B�sicas y Eventos");

    // Configurar el color de fondo y la posici�n de las formas
    Color backgroundColor = BLACK;
    Vector2 circlePosition = { 400, 300 };
    Vector2 rectanglePosition = { 200, 150 };
    Vector2 lineStart = { 100, 100 };
    Vector2 lineEnd = { 700, 500 };

    SetTargetFPS(60); // Configurar el FPS a 60

    while (!WindowShouldClose()) // Detectar si la ventana deber�a cerrarse
    {
        // Manejo de eventos del teclado
        if (IsKeyPressed(KEY_R)) backgroundColor = RED; // Cambiar color de fondo a rojo
        if (IsKeyPressed(KEY_G)) backgroundColor = GREEN; // Cambiar color de fondo a verde
        if (IsKeyPressed(KEY_B)) backgroundColor = BLUE; // Cambiar color de fondo a azul

        if (IsKeyDown(KEY_RIGHT)) circlePosition.x += 5; // Mover c�rculo a la derecha
        if (IsKeyDown(KEY_LEFT)) circlePosition.x -= 5; // Mover c�rculo a la izquierda
        if (IsKeyDown(KEY_UP)) circlePosition.y -= 5; // Mover c�rculo hacia arriba
        if (IsKeyDown(KEY_DOWN)) circlePosition.y += 5; // Mover c�rculo hacia abajo

        if (IsKeyDown(KEY_W)) rectanglePosition.y -= 5; // Mover rect�ngulo hacia arriba
        if (IsKeyDown(KEY_S)) rectanglePosition.y += 5; // Mover rect�ngulo hacia abajo
        if (IsKeyDown(KEY_A)) rectanglePosition.x -= 5; // Mover rect�ngulo a la izquierda
        if (IsKeyDown(KEY_D)) rectanglePosition.x += 5; // Mover rect�ngulo a la derecha

        // Comenzar a dibujar
        BeginDrawing();

        // Limpiar la pantalla con el color de fondo
        ClearBackground(backgroundColor);

        // Dibujar el c�rculo
        DrawCircleV(circlePosition, 50, RED);

        // Dibujar el rect�ngulo
        DrawRectangleV(rectanglePosition, (Vector2){ 100, 50 }, GREEN);

        // Dibujar la l�nea
        DrawLineV(lineStart, lineEnd, BLUE);

        // Finalizar el dibujo
        EndDrawing();
    }

    // Cerrar la ventana y liberar recursos
    CloseWindow();

    return 0;
}

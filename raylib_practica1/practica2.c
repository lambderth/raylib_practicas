#include <raylib.h>

int main(void)
{
    // Inicializar la ventana
    InitWindow(800, 600, "Raylib - Formas Básicas y Eventos");

    // Configurar el color de fondo y la posición de las formas
    Color backgroundColor = BLACK;
    Vector2 circlePosition = { 400, 300 };
    Vector2 rectanglePosition = { 200, 150 };
    Vector2 lineStart = { 100, 100 };
    Vector2 lineEnd = { 700, 500 };

    SetTargetFPS(60); // Configurar el FPS a 60

    while (!WindowShouldClose()) // Detectar si la ventana debería cerrarse
    {
        // Manejo de eventos del teclado
        if (IsKeyPressed(KEY_R)) backgroundColor = RED; // Cambiar color de fondo a rojo
        if (IsKeyPressed(KEY_G)) backgroundColor = GREEN; // Cambiar color de fondo a verde
        if (IsKeyPressed(KEY_B)) backgroundColor = BLUE; // Cambiar color de fondo a azul

        if (IsKeyDown(KEY_RIGHT)) circlePosition.x += 5; // Mover círculo a la derecha
        if (IsKeyDown(KEY_LEFT)) circlePosition.x -= 5; // Mover círculo a la izquierda
        if (IsKeyDown(KEY_UP)) circlePosition.y -= 5; // Mover círculo hacia arriba
        if (IsKeyDown(KEY_DOWN)) circlePosition.y += 5; // Mover círculo hacia abajo

        if (IsKeyDown(KEY_W)) rectanglePosition.y -= 5; // Mover rectángulo hacia arriba
        if (IsKeyDown(KEY_S)) rectanglePosition.y += 5; // Mover rectángulo hacia abajo
        if (IsKeyDown(KEY_A)) rectanglePosition.x -= 5; // Mover rectángulo a la izquierda
        if (IsKeyDown(KEY_D)) rectanglePosition.x += 5; // Mover rectángulo a la derecha

        // Comenzar a dibujar
        BeginDrawing();

        // Limpiar la pantalla con el color de fondo
        ClearBackground(backgroundColor);

        // Dibujar el círculo
        DrawCircleV(circlePosition, 50, RED);

        // Dibujar el rectángulo
        DrawRectangleV(rectanglePosition, (Vector2){ 100, 50 }, GREEN);

        // Dibujar la línea
        DrawLineV(lineStart, lineEnd, BLUE);

        // Finalizar el dibujo
        EndDrawing();
    }

    // Cerrar la ventana y liberar recursos
    CloseWindow();

    return 0;
}

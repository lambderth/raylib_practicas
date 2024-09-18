#include "raylib.h"

// Definir constantes
#define ANCHO_PANTALLA 800
#define ALTO_PANTALLA 600
#define TAMANO_JUGADOR 50
#define TAMANO_OBJETO 30
#define VELOCIDAD_JUGADOR 5

//------------------------------------------------------------------------------------
// Punto de entrada principal del programa
//------------------------------------------------------------------------------------
int main(void)
{
    // Inicialización
    //--------------------------------------------------------------------------------------
    // Función para inicializar la ventana (ancho, alto, titulo)
    InitWindow(ANCHO_PANTALLA, ALTO_PANTALLA, "raylib Practica #4 - Colisiones y Física Básica.");

    // Configurar la posición del jugador y del objeto
    Rectangle jugador = { ANCHO_PANTALLA / 2 - TAMANO_JUGADOR / 2, ALTO_PANTALLA - TAMANO_JUGADOR - 10, TAMANO_JUGADOR, TAMANO_JUGADOR };
    Rectangle objeto = { ANCHO_PANTALLA / 2 - TAMANO_OBJETO / 2, 0, TAMANO_OBJETO, TAMANO_OBJETO };

    // Velocidad del objeto
    Vector2 velocidadObjeto = { 0, 2 };

    SetTargetFPS(60);               // Establecer que el juego corra a 60 cuadros por segundo
    //--------------------------------------------------------------------------------------

    // Bucle principal del juego
    while (!WindowShouldClose())    // Detecta cuando se presiona la tecla ESC o el botón de cerrar ventana
    {
        // Actualizar
        //----------------------------------------------------------------------------------
        // Mover el jugador con las teclas de flecha
        if (IsKeyDown(KEY_D) && jugador.x < ANCHO_PANTALLA - TAMANO_JUGADOR) jugador.x += VELOCIDAD_JUGADOR;
        if (IsKeyDown(KEY_A) && jugador.x > 0) jugador.x -= VELOCIDAD_JUGADOR;
        if (IsKeyDown(KEY_W) && jugador.y > 0) jugador.y -= VELOCIDAD_JUGADOR;
        if (IsKeyDown(KEY_S) && jugador.y < ALTO_PANTALLA - TAMANO_JUGADOR) jugador.y += VELOCIDAD_JUGADOR;

        // Mover el objeto hacia abajo
        objeto.y += velocidadObjeto.y;

        // Reiniciar la posición del objeto si toca el borde inferior
        if (objeto.y > ALTO_PANTALLA)
        {
            objeto.y = -TAMANO_OBJETO;
            objeto.x = GetRandomValue(0, ANCHO_PANTALLA - TAMANO_OBJETO);
        }

        // Detectar colisión entre el jugador y el objeto
        bool colision = CheckCollisionRecs(jugador, objeto);
        //----------------------------------------------------------------------------------

        // Dibujar
        //----------------------------------------------------------------------------------
        BeginDrawing();             // Comienza a "dibujar"

            // Limpiar la pantalla con un color sólido
            ClearBackground(RAYWHITE);

            // Dibujar el jugador y el objeto
            DrawRectangleRec(jugador, BLUE);
            DrawRectangleRec(objeto, RED);

            // Mostrar un mensaje si hay colisión
            if (colision)
            {
                DrawText("Se detecto colision", ANCHO_PANTALLA / 2 - MeasureText("Se detecto colision", 20) / 2, ALTO_PANTALLA / 2 - 10, 20, BLACK);
            }

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

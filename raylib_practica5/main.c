#include "raylib.h"

// Definir constantes
#define ANCHO_PANTALLA 800
#define ALTO_PANTALLA 600
#define TAMANO_JUGADOR 50
#define TAMANO_OBJETO 30
#define VELOCIDAD_JUGADOR 5
#define GRAVEDAD 0.5f
#define FUERZA_SALTO -10.0f

//------------------------------------------------------------------------------------
// Punto de entrada principal del programa
//------------------------------------------------------------------------------------
int main(void)
{
    // Inicialización
    //--------------------------------------------------------------------------------------
    // Función para inicializar la ventana (ancho, alto, titulo)
    InitWindow(ANCHO_PANTALLA, ALTO_PANTALLA, "raylib Practica #5 - Gravedad y salto.");

    // Configurar la posición del jugador y del objeto
    Rectangle jugador = { ANCHO_PANTALLA / 2 - TAMANO_JUGADOR / 2, ALTO_PANTALLA - TAMANO_JUGADOR, TAMANO_JUGADOR, TAMANO_JUGADOR };
    Rectangle objeto = { ANCHO_PANTALLA / 2 - TAMANO_OBJETO / 2, ALTO_PANTALLA - TAMANO_OBJETO - 10, TAMANO_OBJETO, TAMANO_OBJETO };

    // RETO Definir las plataformas
//    Rectangle plataformas[] = {
//        // X    Y  ANCHO ALTO
//        { 150, 450, 200, 20 },
//        { 400, 300, 250, 20 },
//        { 100, 150, 150, 20 }
//    };
//    int numeroPlataformas = sizeof(plataformas) / sizeof(plataformas[0]);

    // Variables de física
    float velocidadY = 0.0f;
    bool estaSaltando = false;

    bool enPlataforma = false; // RETO

    SetTargetFPS(60);               // Establecer que el juego corra a 60 cuadros por segundo
    //--------------------------------------------------------------------------------------

    // Bucle principal del juego
    while (!WindowShouldClose())    // Detecta cuando se presiona la tecla ESC o el botón de cerrar ventana
    {
        // Actualizar
        //----------------------------------------------------------------------------------
        // Mover el jugador con las teclas de flecha (izquierda y derecha)
        if (IsKeyDown(KEY_D) && jugador.x < ANCHO_PANTALLA - TAMANO_JUGADOR) jugador.x += VELOCIDAD_JUGADOR;
        if (IsKeyDown(KEY_A) && jugador.x > 0) jugador.x -= VELOCIDAD_JUGADOR;

        // Manejar el salto
        if (IsKeyPressed(KEY_SPACE) && !estaSaltando)
        {
            velocidadY = FUERZA_SALTO;
            estaSaltando = true;

//            enPlataforma = false; // RETO
        }

        // Aplicar la gravedad
        velocidadY += GRAVEDAD;
        jugador.y += velocidadY;

        // RETO Verificar colisiones con las plataformas
//        enPlataforma = false;
//        for (int i = 0; i < numeroPlataformas; i++)
//        {
//            if (CheckCollisionRecs(jugador, plataformas[i]) && velocidadY >= 0)
//            {
//                jugador.y = plataformas[i].y - TAMANO_JUGADOR;
//                velocidadY = 0;
//                estaSaltando = false;
//                enPlataforma = true;
//            }
//        }

        // Limitar al jugador al suelo
        if (jugador.y >= ALTO_PANTALLA - TAMANO_JUGADOR)
        {
            jugador.y = ALTO_PANTALLA - TAMANO_JUGADOR;
            velocidadY = 0;
            estaSaltando = false;
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

            // RETO Dibujar las plataformas
//            for (int i = 0; i < numeroPlataformas; i++)
//            {
//                DrawRectangleRec(plataformas[i], DARKGRAY);
//            }

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
    -Ajustar fisicas al gusto
    -Añadir fricción (reducir gradualmente la velocidad del jugador cuando no se presionan las teclas de movimiento)

    -DIFICIL:
    Añadir plataformas
    Añadir multiples objetos
    Contador de puntos
*/

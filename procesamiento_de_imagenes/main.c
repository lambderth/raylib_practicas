#include "raylib.h"
#include <stdlib.h>             // Requerido para: free()

#define NUM_PROCESOS 9

typedef enum {
    NINGUNO = 0,
    COLOR_ESCALA_DE_GRISES,
    COLOR_TONO,
    COLOR_INVERTIR,
    COLOR_CONTRASTE,
    COLOR_BRILLO,
    DESENFOQUE_GAUSSIANO,
    VOLTEAR_VERTICAL,
    VOLTEAR_HORIZONTAL
} ProcesamientoImagen;

static const char *textoProceso[] = {
    "SIN PROCESAMIENTO",
    "ESCALA DE GRISES",
    "TINTE",
    "INVERTIR COLORES",
    "CONTRASTE",
    "BRILLO",
    "DESENFOQUE GAUSSIANO",
    "VOLTEAR VERTICAL",
    "VOLTEAR HORIZONTAL"
};

//------------------------------------------------------------------------------------
// Punto de entrada principal del programa
//------------------------------------------------------------------------------------
int main(void)
{
    // Inicialización
    //--------------------------------------------------------------------------------------
    int anchoPantalla = 800;
    int altoPantalla = 450;

    InitWindow(anchoPantalla, altoPantalla, "Procesamiento de imagen.");

    // NOTA: Las texturas DEBEN ser cargadas después de la inicialización de la ventana (se requiere contexto OpenGL)

    Image imagenOriginal = LoadImage("image.png");   // Cargada en la memoria de la CPU (RAM)
    ImageResize(&imagenOriginal, 512, 384);
    ImageFormat(&imagenOriginal, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8); // Formatear imagen a RGBA 32bit (requerido para la actualización de textura)
    Texture2D textura = LoadTextureFromImage(imagenOriginal);  // Imagen convertida a textura, memoria GPU (VRAM)

    Image imagenCopia = ImageCopy(imagenOriginal);

    int procesoActual = NINGUNO;
    bool recargarTextura = false;

    float tamanoBotonesX = 150.0f;
    float tamanoBotonesY = 30.0f;
    float posBotonesX = 50.0f;

    Rectangle rectangulosProceso[NUM_PROCESOS] = { 0 };
    int rectanguloRatonSobre = -1;

    for (int i = 0; i < NUM_PROCESOS; i++) {
        rectangulosProceso[i] = (Rectangle){ posBotonesX, (float)(50 + 32 * i), tamanoBotonesX, tamanoBotonesY };
    }

    Rectangle rectangulosDecremento[NUM_PROCESOS] = { 0 };
    int rectanguloRatonSobreDecremento = -1;

    for (int i = 0; i < NUM_PROCESOS; i++) {
        rectangulosDecremento[i] = (Rectangle){ posBotonesX - tamanoBotonesY - 2.0f, (float)(50 + 32 * i), tamanoBotonesY, tamanoBotonesY };
    }

    Rectangle rectangulosIncremento[NUM_PROCESOS] = { 0 };
    int rectanguloRatonSobreIncremento = -1;

    for (int i = 0; i < NUM_PROCESOS; i++) {
        rectangulosIncremento[i] = (Rectangle){ posBotonesX + tamanoBotonesX + 2.0f, (float)(50 + 32 * i), tamanoBotonesY, tamanoBotonesY };
    }

    int valorContraste = -40;
    int valorBrillo = -80;
    int valorDesenfoque = 10;
    int valorNumero = 0;

    SetTargetFPS(60);
    //---------------------------------------------------------------------------------------

    // Bucle principal del programa
    while (!WindowShouldClose())    // Detecta cierre de ventana o tecla ESC
    {
        // Actualización
        //----------------------------------------------------------------------------------
        // Ajuste de resolución de la imagen al tamaño de la ventana

        // Lógica de grupo de alternancia del ratón
        for (int i = 0; i < NUM_PROCESOS; i++)
        {
            if (CheckCollisionPointRec(GetMousePosition(), rectangulosProceso[i]))
            {
                rectanguloRatonSobre = i;

                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                {
                    procesoActual = i;
                    recargarTextura = true;
                }
                break;
            }
            else rectanguloRatonSobre = -1;

            if (CheckCollisionPointRec(GetMousePosition(), rectangulosDecremento[i]))
            {
                rectanguloRatonSobreDecremento = i;

                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                {
                    procesoActual = i;
                    recargarTextura = true;

                    switch(i)
                    {
                        case 4: valorContraste--; break;
                        case 5: valorBrillo--; break;
                        case 6:
                            if(valorDesenfoque == 1) valorDesenfoque = 1;
                            else valorDesenfoque--;
                        break;
                    }
                }
                break;
            }
            else rectanguloRatonSobreDecremento = -1;

            if (CheckCollisionPointRec(GetMousePosition(), rectangulosIncremento[i]))
            {
                rectanguloRatonSobreIncremento = i;

                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                {
                    procesoActual = i;
                    recargarTextura = true;

                    switch(i)
                    {
                        case 4: valorContraste++; break;
                        case 5: valorBrillo++; break;
                        case 6: valorDesenfoque++; break;
                    }
                }
                break;
            }
            else rectanguloRatonSobreIncremento = -1;
        }

        // Lógica de grupo de alternancia del teclado
        if (IsKeyPressed(KEY_DOWN))
        {
            procesoActual++;
            if (procesoActual > (NUM_PROCESOS - 1)) procesoActual = 0;
            recargarTextura = true;
        }
        else if (IsKeyPressed(KEY_UP))
        {
            procesoActual--;
            if (procesoActual < 0) procesoActual = 7;
            recargarTextura = true;
        }

        if (IsKeyPressed(KEY_LEFT))
        {
            switch(procesoActual)
            {
                case 4: valorContraste--; break;
                case 5: valorBrillo--; break;
                case 6:
                    if(valorDesenfoque == 1) valorDesenfoque = 1;
                    else valorDesenfoque--;
                break;
            }
            recargarTextura = true;
        }
        else if (IsKeyPressed(KEY_RIGHT))
        {
            switch(procesoActual)
            {
                case 4: valorContraste++; break;
                case 5: valorBrillo++; break;
                case 6: valorDesenfoque++; break;
            }
            recargarTextura = true;
        }

        // Recargar textura cuando sea necesario
        if (recargarTextura)
        {
            UnloadImage(imagenCopia);                // Descargar datos de imagen-copia
            imagenCopia = ImageCopy(imagenOriginal); // Restaurar imagen-copia de la imagen original

            switch (procesoActual)
            {
                case COLOR_ESCALA_DE_GRISES: ImageColorGrayscale(&imagenCopia); break;
                case COLOR_TONO: ImageColorTint(&imagenCopia, GREEN); break;
                case COLOR_INVERTIR: ImageColorInvert(&imagenCopia); break;
                case COLOR_CONTRASTE:
                    ImageColorContrast(&imagenCopia, valorContraste);
                    valorNumero = valorContraste;
                break;
                case COLOR_BRILLO:
                    ImageColorBrightness(&imagenCopia, valorBrillo);
                    valorNumero = valorBrillo;
                break;
                case DESENFOQUE_GAUSSIANO:
                    ImageBlurGaussian(&imagenCopia, valorDesenfoque);
                    valorNumero = valorDesenfoque;
                break;
                case VOLTEAR_VERTICAL: ImageFlipVertical(&imagenCopia); break;
                case VOLTEAR_HORIZONTAL: ImageFlipHorizontal(&imagenCopia); break;
                default: break;
            }

            Color *pixeles = LoadImageColors(imagenCopia);  // Cargar datos de píxeles de la imagen (RGBA 32bit)
            UpdateTexture(textura, pixeles);               // Actualizar textura con los nuevos datos de imagen
            UnloadImageColors(pixeles);                    // Descargar datos de píxeles de la RAM

            recargarTextura = false;
        }
        //----------------------------------------------------------------------------------

        // Dibujo
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("PROCESAMIENTO DE IMAGEN:", (int)posBotonesX, (int)tamanoBotonesY, 10, DARKGRAY);

        // Dibujar rectángulos
        for (int i = 0; i < NUM_PROCESOS; i++)
        {
            DrawRectangleRec(rectangulosProceso[i], ((i == procesoActual) || (i == rectanguloRatonSobre)) ? SKYBLUE : LIGHTGRAY);
            DrawRectangleLines((int)rectangulosProceso[i].x, (int)rectangulosProceso[i].y, (int)rectangulosProceso[i].width, (int)rectangulosProceso[i].height, ((i == procesoActual) || (i == rectanguloRatonSobre)) ? BLUE : GRAY);
            DrawText(textoProceso[i], (int)(rectangulosProceso[i].x + rectangulosProceso[i].width / 2 - MeasureText(textoProceso[i], 10) / 2), (int)rectangulosProceso[i].y + 11, 10, ((i == procesoActual) || (i == rectanguloRatonSobre)) ? DARKBLUE : DARKGRAY);

            if(i >= 4 && i <= 6)
            {
                DrawRectangleRec(rectangulosDecremento[i], (i == rectanguloRatonSobreDecremento) ? SKYBLUE : LIGHTGRAY);
                DrawRectangleLines((int)rectangulosDecremento[i].x, (int)rectangulosDecremento[i].y, (int)rectangulosDecremento[i].width, (int)rectangulosDecremento[i].height, (i == rectanguloRatonSobreDecremento) ? BLUE : GRAY);
                DrawText("<", (int)(rectangulosDecremento[i].x + rectangulosDecremento[i].width / 2 - MeasureText("1", 10) / 2), (int)rectangulosDecremento[i].y + 11, 10, (i == rectanguloRatonSobreDecremento) ? DARKBLUE : DARKGRAY);

                DrawRectangleRec(rectangulosIncremento[i], (i == rectanguloRatonSobreIncremento) ? SKYBLUE : LIGHTGRAY);
                DrawRectangleLines((int)rectangulosIncremento[i].x, (int)rectangulosIncremento[i].y, (int)rectangulosIncremento[i].width, (int)rectangulosIncremento[i].height, (i == rectanguloRatonSobreIncremento) ? BLUE : GRAY);
                DrawText(">", (int)(rectangulosIncremento[i].x + rectangulosIncremento[i].width / 2 - MeasureText("1", 10) / 2), (int)rectangulosIncremento[i].y + 11, 10, (i == rectanguloRatonSobreIncremento) ? DARKBLUE : DARKGRAY);

            }

            if(procesoActual >= 4 && procesoActual <= 6)
            {
                char valorTexto[10];
                sprintf(valorTexto, "VALOR: %i", valorNumero);
                DrawText(valorTexto, anchoPantalla - textura.width - 30, altoPantalla / 2 - textura.height / 2 - 20, 20, DARKGRAY);
            }
        }

        DrawTexture(textura, anchoPantalla - textura.width - 30, altoPantalla / 2 - textura.height / 2, WHITE);
        DrawRectangleLines(anchoPantalla - textura.width - 30, altoPantalla / 2 - textura.height / 2, textura.width, textura.height, BLACK);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // Desinicialización
    //--------------------------------------------------------------------------------------
    UnloadTexture(textura);       // Descargar textura de la VRAM
    UnloadImage(imagenOriginal);  // Descargar imagen original de la RAM
    UnloadImage(imagenCopia);     // Descargar imagen-copia de la RAM

    CloseWindow();                // Cerrar ventana y contexto OpenGL
    //--------------------------------------------------------------------------------------

    return 0;
}

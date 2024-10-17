#include "Colores.h"

// Implementación de la función para obtener los valores RGB
void obtenerColorRGB(Color color, float& r, float& g, float& b) {
    switch (color) {
    case ROJO:
        r = 1.0f; g = 0.0f; b = 0.0f;
        break;
    case VERDE:
        r = 0.0f; g = 1.0f; b = 0.0f;
        break;
    case AZUL:
        r = 0.0f; g = 0.0f; b = 1.0f;
        break;
    case AMARILLO:
        r = 1.0f; g = 1.0f; b = 0.0f;
        break;
    case MAGENTA:
        r = 1.0f; g = 0.0f; b = 1.0f;
        break;
    case CIAN:
        r = 0.0f; g = 1.0f; b = 1.0f;
        break;
    case BLANCO:
        r = 1.0f; g = 1.0f; b = 1.0f;
        break;
    case NEGRO:
        r = 0.0f; g = 0.0f; b = 0.0f;
        break;
    case GRIS:
        r = 0.5f; g = 0.5f; b = 0.5f;
        break;
    case NARANJA:
        r = 1.0f; g = 0.65f; b = 0.0f;
        break;
    case MORADO:
        r = 0.5f; g = 0.0f; b = 0.5f;
        break;
    case MARRON:
        r = 0.6f; g = 0.4f; b = 0.2f;
        break;
    default:
        r = 0.7f; g = 0.7f; b = 0.7f; // Color por defecto (gris claro)
        break;
    }
}

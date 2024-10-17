#ifndef COLORES_H
#define COLORES_H

// Definici�n del enum para los colores
enum Color {
    ROJO,
    VERDE,
    AZUL,
    AMARILLO,
    MAGENTA,
    CIAN,
    BLANCO,
    NEGRO,
    GRIS,
    NARANJA,
    MORADO,
    MARRON
};

// Declaraci�n de la funci�n para obtener los valores RGB de un color
void obtenerColorRGB(Color color, float& r, float& g, float& b);

#endif // COLORES_H

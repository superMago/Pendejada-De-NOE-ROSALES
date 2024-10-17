#ifndef COLORES_H
#define COLORES_H

// Definición del enum para los colores
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

// Declaración de la función para obtener los valores RGB de un color
void obtenerColorRGB(Color color, float& r, float& g, float& b);

#endif // COLORES_H

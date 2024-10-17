#ifndef PISO_H
#define PISO_H

#include <GL/glut.h>

class Piso {
public:
    // Atributos del piso
    float x, y, z; // Posici�n inicial (esquina inferior izquierda)
    float ancho, largo; // Dimensiones del piso
    float nivel; // Altura del piso (nivel en Y)

    // Constructor de la clase Piso
    Piso(float x, float y, float z, float ancho, float largo);

    // M�todo para dibujar el piso
    void dibujar();
};

#endif // PISO_H



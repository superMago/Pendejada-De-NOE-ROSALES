#include "Piso.h"

// Constructor de Piso
Piso::Piso(float x, float y, float z, float ancho, float largo)
    : x(x), y(y), z(z), ancho(ancho), largo(largo), nivel(y) {}

// Método para dibujar el piso
void Piso::dibujar() {
    glColor3f(0.99, 0.92, 0.78); // Color gris para el piso

    glBegin(GL_QUADS);
    glVertex3f(x, nivel, z);
    glVertex3f(x + ancho, nivel, z);
    glVertex3f(x + ancho, nivel, z + largo);
    glVertex3f(x, nivel, z + largo);
    glEnd();
}
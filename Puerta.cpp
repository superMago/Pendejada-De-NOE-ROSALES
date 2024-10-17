#include "Puerta.h"
#include <GL/glut.h>  // Biblioteca para usar OpenGL

// Constructor de Puerta, que llama al constructor de Pared
Puerta::Puerta(float x1, float y1, float z1, float x2, float y2, float z2, float altura, float grosor)
    : Pared(x1, y1, z1, x2, y2, z2, altura, grosor) {}

// Sobrescribir el método dibujar
void Puerta::dibujar() {
    // Color marrón para la puerta
    glColor3f(0.545f, 0.271f, 0.075f);

    // Llamar al método dibujar de la clase Pared
    Pared::dibujar();
}
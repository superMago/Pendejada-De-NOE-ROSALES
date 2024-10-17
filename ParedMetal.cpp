#include "ParedMetal.h"
#include <GL/glut.h>  // Biblioteca para usar OpenGL

// Constructor de ParedMetal, que llama al constructor de Pared
ParedMetal::ParedMetal(float x1, float y1, float z1, float x2, float y2, float z2, float altura, float grosor)
    : Pared(x1, y1, z1, x2, y2, z2, altura, grosor) {}

// Sobrescribir el método dibujar
void ParedMetal::dibujar() {
    // Color plateado para la pared de metal
    glColor3f(0.752f, 0.752f, 0.752f);

    // Llamar al método dibujar de la clase Pared
    Pared::dibujar();
}
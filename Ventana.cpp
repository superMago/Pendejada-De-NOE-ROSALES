#include "Ventana.h"
#include <GL/glut.h>  // Biblioteca para usar OpenGL

// Constructor de Ventana, que llama al constructor de Pared con "esTransparente" como true
Ventana::Ventana(float x1, float y1, float z1, float x2, float y2, float z2, float altura, float grosor)
    : Pared(x1, y1, z1, x2, y2, z2, altura, grosor, true) {}

// Sobrescribir el método dibujar
void Ventana::dibujar() {
    // Habilitar transparencia
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Color azul claro semitransparente para la ventana
    glColor4f(0.529f, 0.808f, 0.922f, 0.5f);

    // Llamar al método dibujar de la clase Pared
    Pared::dibujar();

    // Deshabilitar la transparencia
    glDisable(GL_BLEND);
}
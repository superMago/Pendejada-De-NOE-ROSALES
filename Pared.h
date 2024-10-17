#pragma once

#include <GL/glut.h>  // Incluir la biblioteca de OpenGL (modifica según tu entorno)
#include <cmath>      // Para usar sqrtf

class Pared {
public:
    // Atributos
    float x1, y1, z1; // Punto inicial
    float x2, y2, z2; // Punto final
    float altura;
    float grosor;
    bool esTransparente;

    // Constructor
    Pared(float x1, float y1, float z1, float x2, float y2, float z2, float altura, float grosor = 0.1f, bool esTransparente = false);

    // Método para dibujar la pared
    virtual void dibujar();
};
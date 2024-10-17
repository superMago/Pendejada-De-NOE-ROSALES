// Pared.h

#ifndef PARED_H
#define PARED_H

#include <GL/glut.h>

class Pared {
public:
    float x1, y1, z1; // Punto inicial
    float x2, y2, z2; // Punto final
    float altura;
    float grosor;
    bool esTransparente;

    // Atributos de color
    float r, g, b; // Componentes RGB del color

    Pared(float x1, float y1, float z1, float x2, float y2, float z2, float altura,
          float grosor = 0.1f, bool esTransparente = false,
          float r = 0.7f, float g = 0.7f, float b = 0.7f)
        : x1(x1), y1(y1), z1(z1), x2(x2), y2(y2), z2(z2),
          altura(altura), grosor(grosor), esTransparente(esTransparente),
          r(r), g(g), b(b) {}

    virtual void dibujar() {
        if (esTransparente) {
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glColor4f(r, g, b, 0.5f); // Color con transparencia
        } else {
            glColor3f(r, g, b); // Color sólido
        }

        // Código para dibujar la pared...
    }
};

#endif // PARED_H

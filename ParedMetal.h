#pragma once
#include "Pared.h"  // Incluir el encabezado de la clase base

class ParedMetal : public Pared {
public:
    // Constructor de ParedMetal que llama al constructor de Pared
    ParedMetal(float x1, float y1, float z1, float x2, float y2, float z2, float altura, float grosor = 0.1f);

    // Sobrescribir el m�todo dibujar de Pared
    void dibujar() override;
};

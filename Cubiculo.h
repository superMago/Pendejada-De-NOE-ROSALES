#pragma once
#include "Habitacion.h"
#include "ParedMetal.h"
#include "Ventana.h"

class Cubiculo : public Habitacion {
public:
    // Constructor de Cubiculo que llama al constructor de Habitacion
    Cubiculo(float x, float y, float z, float ancho, float largo, float altura);

    // Sobrescribir el m�todo para crear paredes espec�ficas del cub�culo
    void crearParedes() override;
};
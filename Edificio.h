#pragma once
#include "Habitacion.h"
#include <vector>

class Edificio {
public:
    // Vector que almacena punteros a Habitacion
    std::vector<Habitacion*> habitaciones;

    // M�todo para agregar una nueva habitaci�n al edificio
    void agregarHabitacion(Habitacion* habitacion);

    // M�todo para dibujar todas las habitaciones del edificio
    void dibujar();

    // Destructor para liberar la memoria de las habitaciones
    ~Edificio();
};


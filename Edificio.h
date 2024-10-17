#pragma once
#include "Habitacion.h"
#include <vector>

class Edificio {
public:
    // Vector que almacena punteros a Habitacion
    std::vector<Habitacion*> habitaciones;

    // Método para agregar una nueva habitación al edificio
    void agregarHabitacion(Habitacion* habitacion);

    // Método para dibujar todas las habitaciones del edificio
    void dibujar();

    // Destructor para liberar la memoria de las habitaciones
    ~Edificio();
};


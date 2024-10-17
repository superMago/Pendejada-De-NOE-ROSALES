#include "Edificio.h"

// Agregar una habitación al edificio
void Edificio::agregarHabitacion(Habitacion* habitacion) {
    habitaciones.push_back(habitacion);
}

// Dibujar todas las habitaciones del edificio
void Edificio::dibujar() {
    for (auto& habitacion : habitaciones) {
        glColor3f(1,0,0);
        habitacion->dibujar();
    }
}

// Destructor para liberar la memoria de las habitaciones
Edificio::~Edificio() {
    for (auto& habitacion : habitaciones) {
        delete habitacion;  // Liberar memoria de cada habitación
    }
}
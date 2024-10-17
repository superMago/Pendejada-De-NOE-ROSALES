#include "Habitacion.h"

// Constructor de Habitacion
Habitacion::Habitacion(float x, float y, float z, float ancho, float largo, float altura)
    : x(x), y(y), z(z), ancho(ancho), largo(largo), altura(altura), piso(nullptr) {
    crearParedes();
    crearPiso();
}

// Destructor para liberar la memoria de las paredes y el piso
Habitacion::~Habitacion() {
    for (auto& pared : paredes) {
        delete pared;  // Liberar memoria de las paredes
    }
    delete piso;  // Liberar memoria del piso
}

// Crear las paredes de la habitación
void Habitacion::crearParedes() {
    // Pared frontal
    paredes.push_back(new Pared(x, y, z, x + ancho, y, z, altura));
    // Pared trasera
    paredes.push_back(new Pared(x, y, z + largo, x + ancho, y, z + largo, altura));
    // Pared izquierda
    paredes.push_back(new Pared(x, y, z, x, y, z + largo, altura));
    // Pared derecha
    paredes.push_back(new Pared(x + ancho, y, z, x + ancho, y, z + largo, altura));
}

// Crear el piso de la habitación
void Habitacion::crearPiso() {
    piso = new Piso(x, y, z, ancho, largo);  // Crear un nuevo objeto Piso
}

// Dibujar la habitación (paredes y piso)
void Habitacion::dibujar() {
    for (auto& pared : paredes) {
        pared->dibujar();  // Dibujar cada pared
    }
    if (piso) {
        piso->dibujar();  // Dibujar el piso si existe
    }
}

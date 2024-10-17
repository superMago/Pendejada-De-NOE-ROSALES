#ifndef HABITACION_H
#define HABITACION_H

#include "Pared.h"
#include "Piso.h"
#include <vector>

class Habitacion {
public:
    // Atributos de la habitación
    float x, y, z; // Posición
    float ancho, largo, altura;
    std::vector<Pared*> paredes;
    Piso* piso;

    // Constructor
    Habitacion(float x, float y, float z, float ancho, float largo, float altura);

    // Destructor para liberar la memoria
    virtual ~Habitacion();

    // Métodos para crear las paredes y el piso
    virtual void crearParedes();
    virtual void crearPiso();

    // Método para dibujar la habitación
    virtual void dibujar();
};

#endif // HABITACION_H

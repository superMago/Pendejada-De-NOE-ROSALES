#ifndef HABITACION_H
#define HABITACION_H

#include "Pared.h"
#include "Piso.h"
#include <vector>

class Habitacion {
public:
    // Atributos de la habitaci�n
    float x, y, z; // Posici�n
    float ancho, largo, altura;
    std::vector<Pared*> paredes;
    Piso* piso;

    // Constructor
    Habitacion(float x, float y, float z, float ancho, float largo, float altura);

    // Destructor para liberar la memoria
    virtual ~Habitacion();

    // M�todos para crear las paredes y el piso
    virtual void crearParedes();
    virtual void crearPiso();

    // M�todo para dibujar la habitaci�n
    virtual void dibujar();
};

#endif // HABITACION_H

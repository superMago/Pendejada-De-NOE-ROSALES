#include "Cubiculo.h"

// Constructor de Cubiculo
Cubiculo::Cubiculo(float x, float y, float z, float ancho, float largo, float altura)
    : Habitacion(x, y, z, ancho, largo, altura) {}

// Crear las paredes del cubículo
void Cubiculo::crearParedes() {
    float alturaMetal = altura * 0.7f;  // 70% de la pared es metal
    float alturaVentana = altura - alturaMetal;  // 30% de la pared es ventana

    // Pared frontal
    paredes.push_back(new ParedMetal(x, y, z, x + ancho, y, z, alturaMetal));
    paredes.push_back(new Ventana(x, y, z + alturaMetal, x + ancho, y, z + alturaMetal, alturaVentana));

    // Pared trasera
    paredes.push_back(new ParedMetal(x, y + largo, z, x + ancho, y + largo, z, alturaMetal));
    paredes.push_back(new Ventana(x, y + largo, z + alturaMetal, x + ancho, y + largo, z + alturaMetal, alturaVentana));

    // Pared izquierda
    paredes.push_back(new ParedMetal(x, y, z, x, y + largo, z, alturaMetal));
    paredes.push_back(new Ventana(x, y, z + alturaMetal, x, y + largo, z + alturaMetal, alturaVentana));

    // Pared derecha
    paredes.push_back(new ParedMetal(x + ancho, y, z, x + ancho, y + largo, z, alturaMetal));
    paredes.push_back(new Ventana(x + ancho, y, z + alturaMetal, x + ancho, y + largo, z + alturaMetal, alturaVentana));
}

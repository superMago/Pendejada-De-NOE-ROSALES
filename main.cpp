// main.cpp

#include <GL/glut.h>
#include <cmath>

// Incluye las cabeceras de tus clases
#include "Edificio.h"
#include "Habitacion.h"
#include "Cubiculo.h"
// ... otros includes según sea necesario

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Variables globales para la cámara
float cameraX = 0.0f, cameraY = 1.75f, cameraZ = 10.0f;
float angleX = 0.0f, angleY = 0.0f;

// Variables constantes para los valores iniciales de la cámara
const float CAMERA_X_INIT = 0.0f;
const float CAMERA_Y_INIT = 1.75f;
const float CAMERA_Z_INIT = 10.0f;
const float ANGLE_X_INIT = 0.0f;
const float ANGLE_Y_INIT = 0.0f;

// Instancia del edificio
Edificio edificio;

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Fondo blanco
    glEnable(GL_DEPTH_TEST);

    // Crear habitaciones y cubículos
    Habitacion* habitacion1 = new Habitacion(0, 0.1, 0, 15, 10, 3);
    Habitacion* BanoH = new Habitacion(0.1, 0.1, 6.9, 2, 3, 3);
    //Pixeles

    edificio.agregarHabitacion(habitacion1);
    edificio.agregarHabitacion(BanoH);
    Cubiculo* cubiculo1 = new Cubiculo(6, 0, 0, 2, 2, 2.5);
    edificio.agregarHabitacion(cubiculo1);

    // Agrega más habitaciones o cubículos según tus necesidades
}

void dibujarEjes() {
    glLineWidth(2.0f); // Ancho de las líneas de los ejes

    glBegin(GL_LINES);
    // Eje X en rojo
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(5.0f, 0.0f, 0.0f);

    // Eje Y en verde
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 5.0f, 0.0f);

    // Eje Z en azul
    glColor3f(0.0f, 0.0f, 1.0f); // Azul
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 5.0f);
    glEnd();

    glLineWidth(1.0f); // Restablecer el ancho de línea predeterminado
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Aplicar rotaciones y traslaciones de la cámara
    glRotatef(-angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(-angleY, 0.0f, 1.0f, 0.0f);
    glTranslatef(-cameraX, -cameraY, -cameraZ);

    // Dibujar los ejes XYZ
    dibujarEjes();

    // Dibujar el edificio
    edificio.dibujar();

    // Dibujar el piso
    glColor3f(0.6f, 0.6f, 0.6f); // Color gris para el piso
    glBegin(GL_QUADS);
    glVertex3f(-50.0f, -0.1f, -50.0f);
    glVertex3f(-50.0f, -0.1f, 50.0f);
    glVertex3f(50.0f, -0.1f, 50.0f);
    glVertex3f(50.0f, -0.1f, -50.0f);
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    if (h == 0) h = 1; // Evitar división por cero
    float ratio = 1.0f * w / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    float cameraSpeed = 0.5f;
    float angleSpeed = 2.0f;

    switch (key) {
        // Rotaciones
    case 'R': case 'r':
        angleY += angleSpeed;
        break;
    case 'T': case 't':
        angleY -= angleSpeed;
        break;
    case 'Y': case 'y':
        angleX += angleSpeed;
        break;
    case 'U': case 'u':
        angleX -= angleSpeed;
        break;

        // Movimiento de la cámara
    case 'W': case 'w':
        cameraX += cameraSpeed * sinf(angleY * M_PI / 180.0f);
        cameraZ -= cameraSpeed * cosf(angleY * M_PI / 180.0f);
        break;
    case 'S': case 's':
        cameraX -= cameraSpeed * sinf(angleY * M_PI / 180.0f);
        cameraZ += cameraSpeed * cosf(angleY * M_PI / 180.0f);
        break;
    case 'A': case 'a':
        cameraX -= cameraSpeed * cosf(angleY * M_PI / 180.0f);
        cameraZ -= cameraSpeed * sinf(angleY * M_PI / 180.0f);
        break;
    case 'D': case 'd':
        cameraX += cameraSpeed * cosf(angleY * M_PI / 180.0f);
        cameraZ += cameraSpeed * sinf(angleY * M_PI / 180.0f);
        break;

        // Movimiento vertical
    case 'Q': case 'q':
        cameraY += cameraSpeed; // Mover hacia arriba
        break;
    case 'E': case 'e':
        cameraY -= cameraSpeed; // Mover hacia abajo
        break;

        // Resetear la vista
    case 'X': case 'x':
        cameraX = CAMERA_X_INIT;
        cameraY = CAMERA_Y_INIT;
        cameraZ = CAMERA_Z_INIT;
        angleX = ANGLE_X_INIT;
        angleY = ANGLE_Y_INIT;
        break;

        // Salir del programa
    case 27: // Tecla 'Esc'
        exit(0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Edificio con OpenGL");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

#ifndef CONTROLADORMOTOR_H
#define CONTROLADORMOTOR_H

#include <Arduino.h>

// =================================================================
// CLASE: Motor
// Responsabilidad: Controlar los motores del robot usando un L298N.
// =================================================================
class Motor {
public:

    // Configuracion de pines IN1, IN2 al lado izquierdo y IN3, IN4 al derecho.
    static const byte PIN_MOTOR_IZQ_1 = 8; // IN1  motores izquierdo +positivo
    static const byte PIN_MOTOR_IZQ_2 = 7; // IN2  motores izquierdo -negativo
    static const byte PIN_MOTOR_DER_1 = 6; // IN3  motores derecho   +positivo
    static const byte PIN_MOTOR_DER_2 = 5; // IN4  motores derecho   -negativo
 
    // Constructor: Inicializa los pines de los motores como salidas.
    Motor();

    // Mueve el robot hacia adelante.
    void moverAdelante();
    
    // Mueve el robot en reversa.
    void moverReversa();

    // Detiene completamente el movimiento del robot.
    void detener();

    // Gira el robot hacia la izquierda (ruedas derechas adelante, izquierdas atrás).
    void girarIzquierda(int duracion);

    // Gira el robot hacia la derecha (ruedas izquierdas adelante, derechas atrás).
    void girarDerecha(int duracion);
};

#endif 

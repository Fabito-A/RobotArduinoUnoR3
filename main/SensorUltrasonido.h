// =================================================================
// CLASE: UltrasonicSensor
// Responsabilidad: Manejar el sensor ultrasónico HC-SR04.
// =================================================================
#ifndef SENSORULTRASONIDO_H
#define SENSORULTRASONIDO_H

#include <Arduino.h>
#include <NewPing.h>
#define MAX_DISTANCIA 400 //4metros maximo permitido 400

class UltrasonicSensor {
public:
    // --- Configuración de Pines ---
    static const byte TRIG_PIN = A0; //A0;
    static const byte ECHO_PIN = A1; //A1;
    
private:
    NewPing sonar;

public:
    // Constructor: Inicializa los pines y calcula el timeout.
    UltrasonicSensor();

    void inicializarUltrasonido();

    // Mide y devuelve la distancia a un objeto en centímetros.
    int obtenerDistancia();
};

#endif 
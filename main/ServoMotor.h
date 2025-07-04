// =================================================================
// CLASE: ServoMotor
// Responsabilidad: Controlar el servo motor para "girar el ultrasonido".
// =================================================================
#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Arduino.h>
#include <Servo.h>
#include "SensorUltrasonido.h"


class ServoMotor {
public:
    // --- Configuración de Pines ---
    static const byte SERVO_PIN = 3;

private:
    Servo servo; // Objeto de la librería Servo
    UltrasonicSensor sensorSR04;

public:
    // Constructor: Asocia el servo al pin especificado.
    ServoMotor();

    // Apunta el servo a un ángulo específico.
    void inicializarServo();
    void mirarHacia(int angulo);
    int chequearDirecciones(int distanciaP);
};

#endif

// =================================================================
// CLASE: Motor 
// Responsabilidad: Implementacion de la clase Motor  robot usando 
// el chip L298N.
// ================================================================
#include "ControladorMotor.h"

Motor::Motor() {
    pinMode(PIN_MOTOR_IZQ_1, OUTPUT);
    pinMode(PIN_MOTOR_IZQ_2, OUTPUT);
    pinMode(PIN_MOTOR_DER_1, OUTPUT);
    pinMode(PIN_MOTOR_DER_2, OUTPUT);
}

// Mueve ambos lados hacia adelante.
void Motor::moverAdelante() {
    // Motores izquierdos hacia adelante
    digitalWrite(PIN_MOTOR_IZQ_1, HIGH);
    digitalWrite(PIN_MOTOR_DER_1, HIGH);

}

// Mueve ambos lados en reversa.
void Motor::moverReversa() {
    // Motores izquierdos en reversa
    digitalWrite(PIN_MOTOR_IZQ_1, LOW);
    digitalWrite(PIN_MOTOR_IZQ_2, HIGH);
    // Motores derechos en reversa
    digitalWrite(PIN_MOTOR_DER_1, LOW);
    digitalWrite(PIN_MOTOR_DER_2, HIGH);
}

// Detiene todos los motores.
void Motor::detener() {
    digitalWrite(PIN_MOTOR_IZQ_1, LOW);
    digitalWrite(PIN_MOTOR_IZQ_2, LOW);
    digitalWrite(PIN_MOTOR_DER_1, LOW);
    digitalWrite(PIN_MOTOR_DER_2, LOW);
}

// Gira a la izquierda: Mueve las ruedas derechas adelante y las izquierdas en reversa.
void Motor::girarIzquierda(int duracion) {
    // Motores izquierdos en reversa
    digitalWrite(PIN_MOTOR_IZQ_1, LOW);
    digitalWrite(PIN_MOTOR_IZQ_2, HIGH);
    // Motores derechos hacia adelante
    digitalWrite(PIN_MOTOR_DER_1, HIGH);
    digitalWrite(PIN_MOTOR_DER_2, LOW);
    
    delay(duracion);
    detener(); // Detiene el giro después de la duración.
}

// Gira a la derecha: Mueve las ruedas izquierdas adelante y las derechas en reversa.
void Motor::girarDerecha(int duracion) {
    // Motores izquierdos hacia adelante
    digitalWrite(PIN_MOTOR_IZQ_1, HIGH);
    digitalWrite(PIN_MOTOR_IZQ_2, LOW);
    // Motores derechos en reversa
    digitalWrite(PIN_MOTOR_DER_1, LOW);
    digitalWrite(PIN_MOTOR_DER_2, HIGH);

    delay(duracion);
    detener(); // Detiene el giro después de la duración.
}

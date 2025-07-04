// =================================================================
// CLASE: UltrasonicSensor
// Responsabilidad: implementacion de la clase UltrasonicSensor
// =================================================================
#include "SensorUltrasonido.h"


UltrasonicSensor::UltrasonicSensor():sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCIA) {}


void UltrasonicSensor::inicializarUltrasonido()
{
        pinMode(TRIG_PIN, OUTPUT);  // El pin Trigger es salida
        pinMode(ECHO_PIN, INPUT);   // El pin Echo es entrada
}
// Mide y devuelve la distancia en centímetros
int UltrasonicSensor::obtenerDistancia() {
    int repeticiones = 5;
    int distancia = sonar.ping_cm(MAX_DISTANCIA);
    return distancia;
}

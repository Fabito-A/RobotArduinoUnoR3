// =================================================================
// CLASE: implementacion de la clase ServoMotor
// Responsabilidad: Controlar el servo motor para "girar el ultrasonido".
// =================================================================
#include "ServoMotor.h"

// Constructor: Asocia el servo al pin de control.
ServoMotor::ServoMotor() {
 //  servo.attach(SERVO_PIN);
}
void ServoMotor::inicializarServo()
{
   servo.attach(SERVO_PIN);
}
// Apunta el servo a un ángulo específico (0-180).
void ServoMotor::mirarHacia(int angulo) {
    servo.write(angulo);
}

// =================================================================
// --- FUNCIONES AUXILIARES DE LÓGICA ---
// =================================================================

// Revisa las distancias a la izquierda y derecha para decidir la mejor ruta.
// Devuelve: 0 (izquierda), 1 (dar la vuelta), 2 (derecha).
int ServoMotor :: chequearDirecciones(int distanciaP) {
  int distanciaParada = distanciaP;  
  int distancias[2] = { 0, 0 };  // [0] = Izquierda, [1] = Derecha
  int direccionGiro = -1;        // Por defecto: dar la vuelta

  // Mirar a la izquierda (180 grados) y medir distancia
  mirarHacia(180);
  delay(500);  // Espera a que el servo se mueva
  distancias[0] = sensorSR04.obtenerDistancia();

  // Mirar a la derecha (0 grados) y medir distancia
  mirarHacia(0);
  delay(1000);  // Más tiempo para el servo recorrer 180 grados
  distancias[1] = sensorSR04.obtenerDistancia();
  delay(500);  // Pequeña pausa para permitir la lectura en el OLED

  // Regresar el servo al frente después de las mediciones
  mirarHacia(90);
  delay(500);  // Pequeña pausa para que el servo se estabilice

  // Lógica de decisión
  if (distancias[0] >= MAX_DISTANCIA && distancias[1] >= MAX_DISTANCIA) {
    direccionGiro = 0;  // Ambos lados muy despejados, elige izquierda por defecto.

  } else if (distancias[0] <= distanciaParada && distancias[1] <= distanciaParada) {
    direccionGiro = 1;  // Ambos lados bloqueados, da la vuelta.
    Serial.println("Ambos lados bloqueados. Dando la vuelta.");
  } else if (distancias[0] >= distancias[1]) {
    direccionGiro = 0;  // Izquierda tiene más espacio.
  } else {              // distancias[0] < distancias[1]
    direccionGiro = 2;  // Derecha tiene más espacio.
  }

  return direccionGiro;
}

// =================================================================
//  ROBOT  RobotEvita Obstaculos
// =================================================================
// Este archivo contiene la lógica principal y coordina los diferentes
// componentes del robot (motores, sensor, servo).

#include "ControladorMotor.h"
#include "SensorUltrasonido.h"
#include "ServoMotor.h"
#include "MiniDisplay.h"


// --- OBJETOS GLOBALES INSTANCIACION DE CLASES---

Motor motores;
ServoMotor servoObservador;
UltrasonicSensor sensorSR04;
MiniDisplay miniDisplay;


// --- CONSTANTES DE COMPORTAMIENTO ---
// Distancia mínima para detenerse en cm (a full carga de bateria  incrementar la distancia)
// debido a la limitada velocidad de respuesta del sensor del Ultrasonido
const int DISTANCIA_PARADA = 20;  

// =================================================================
// --- PROGRAMA PRINCIPAL ---
// =================================================================

void setup() {
  Serial.begin(9600);
  miniDisplay.begin();
  miniDisplay.showText("Arrancando...");
  servoObservador.inicializarServo();
  sensorSR04.inicializarUltrasonido();
  delay(1000);
}

void loop() {
  // 1. Apuntar el servo al frente y esperar a que se estabilice
  servoObservador.mirarHacia(90);
  delay(750);
  // 2. Medir la distancia al frente
  int distancia = sensorSR04.obtenerDistancia();

  String text = "Distancia:\n" + String(distancia) + " cm";
  miniDisplay.showText(text, 0, 0, 2);

  if (distancia >= DISTANCIA_PARADA) {
    // El camino está despejado, avanzamos
    miniDisplay.showCheckIcon(80, 16);
    motores.moverAdelante();
  } else if (distancia < DISTANCIA_PARADA) {
    miniDisplay.showWarningIcon(80, 16);
    motores.detener();
    delay(200);
    // Decidir a dónde girar
    int direccionGiro = servoObservador.chequearDirecciones(DISTANCIA_PARADA);

    switch (direccionGiro) {
      case 0:
        motores.girarIzquierda(1000);
        break;
      case 1:                          // Dar la vuelta
        motores.girarIzquierda(2000);  // O girarDerecha(2000) para un giro completo
        break;
      case 2:
        motores.girarDerecha(1500);
        break;
    }
  }
}

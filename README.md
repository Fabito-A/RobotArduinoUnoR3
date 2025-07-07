# 🤖 Robot Evita Obstáculos con Arduino

Este proyecto consiste en un robot autónomo que utiliza un sensor ultrasónico, un servomotor, un mini display y motores para detectar obstáculos, mostrar información y tomar decisiones de movimiento de forma automática.

![image](imagenes/20250706_015404_.png)

## 📋 Caracteristicas

El robot realiza las siguientes tareas:
1. **Escanea el frente** con un servomotor que mueve el sensor ultrasónico.
2. **Mide la distancia** al obstáculo más cercano.
3. **Muestra la distancia** en un mini display.
4. **Decide si avanza o gira**:
   - Si la distancia es segura, avanza.
   - Si detecta un obstáculo cerca, se detiene y analiza otras direcciones (izquierda y derecha) antes de decidir hacia dónde girar.

---

## 🚦 Componentes Principales

| Componente         | Referencia                                  |
|--------------------|---------------------------------------------|
|   Motor DC                   |  Motoreductor de doble eje        |
| ServoMotor                   | SG-90                             |
| Sensor Ultrasonido           | HC-SR04                           |
| MiniDisplay                  | OLED I2C SSD1306                  |
| Modulo Controlador de motor  |L298N                              |
|Baterias                      | AA 1.5v                           |
|Baterias                      |9v                                 |

---

## ⚙️ Variables de Configuración

Es aconsejable segun la velocidad de los motores calibrar su medicion, entre mas rapido es el desplazamiento del vehiculo  mayor deberia ser su valor  

`const int DISTANCIA_PARADA = 20;`

## 📦 Dependencias del Proyecto (Librerías de Arduino)

| Librería                 | Licencia | Descripción                                            | Enlace Oficial                                                         |
| ------------------------ | -------- | ------------------------------------------------------ | ---------------------------------------------------------------------- |
| **Adafruit BusIO**       | BSD      | Librería de comunicación para dispositivos Adafruit    | [Enlace](https://github.com/adafruit/Adafruit_BusIO)       |
| **Adafruit GFX Library** | BSD      | Librería base para pantallas gráficas Adafruit         | [Enlace](https://github.com/adafruit/Adafruit-GFX-Library) |
| **Adafruit SSD1306**     | BSD      | Librería para pantallas OLED SSD1306                   | [Enlace](https://github.com/adafruit/Adafruit_SSD1306)     |
| **NewPing**              | GPL v3   | Librería optimizada para sensores ultrasónicos HC-SR04 | [Enlace](https://bitbucket.org/teckel12/arduino-new-ping/src/master)       |
| **Servo**                | LGPL 2.1 | Librería estándar para control de servomotores         | [Enlace](https://github.com/arduino-libraries/Servo)       |

## 🧑‍💻 Agradecimientos:
Este proyecto es basado en este repositorio de Electronica De Una:
| Repositoro               |
|-------------------------------------------------------------------|
| https://github.com/electrodeuna/avoid-obstacles-arduino |
---

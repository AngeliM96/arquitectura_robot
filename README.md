# Estructura del repositorio

## Carpeta robotFT
En la carpeta robotFT se puede encontrar el desarrollo principal del robot, está dividido en tres archivos:
* robotFT.ino: El programa central de Arduino, el cual ejecuta la función general.
* tatubot.h: Archivo de tipo header que contiene el modelado del robot.
* tatubot.cpp: Archivo de c++ que desarrolla las funciones declaradas en el archivo header.

## Carpeta pruebas_componentes
En esta carpeta se pueden encontrar distintos sketch para probar los distintos componentes, las carpetas tienen nombres bastante intuitivos, son:

* led_RGB
* motores
* matriz

# Librerias utilizadas
Se están utilizando las librerias ArduinoQueue y LedControl, para el uso de la estructura colas y el control de las matrices de led, respectivamente.

# Pinout de la placa utilizada
![Arduino Uno Pinout](/assets/uno_pinout.png)

# Pins utilizados:

## Motor 1: 

IN1 2

IN2 3

ENA 5

## Motor 2:

IN3 7

IN4 8

ENB 9

## Matriz de Leds:

DIN 11 

CLK 13 

CS 10

## Pulsadores

Escuchar ordenes A0 

Avanzar          A1  Carita feliz

Retroceder       A2  Carita entusiasmada

Giro Derecha     A3  Carita enojada

Giro Izquierda   A4  Carita sorprendida

Fin Ordenes      A5  Carita triste

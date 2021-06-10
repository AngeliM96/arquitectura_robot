# Modelado del robot
En la carpeta Kotlin se puede encontrar un primer modelado de la estructura del programa, por un tema de familiaridad con el lenguaje preferí desarrollarlo de esa manera y luego pasarlo a Arduino y C++. El programa principal del Robot se puede encontrar dentro de la carpeta arduino

## Los distintos archivos dentro de la carpeta Kotlin
* **Arduino.kt** es un **Singleton** que simula el programa de Arduino, contiene las clásicas funciones **setup()** y **loop()**.
* **Robot.kt** es todo el modelado principal del funcionamiento del robot
* **Orden.kt** contiene una interfaz **Orden** que es heredada por las distintas acciones, esto permite modelar los botones que va a tener el robot para ejecutar las distintas ordenes que se quiera hacer.
* **Motor.kt** permite modelar los dos motores y encargarse de la funcionalidad básica de estos mediante el patrón de diseño **Strategy**.

## Los distintos archivos dentro de la carpeta Arduino

#TODO
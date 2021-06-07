# Modelado del robot
Por un tema de familiaridad con Kotlin, prefiero modelar toda la estructura del robot en este lenguaje y una vez finalizado traspasarlo a Arduino y C++ para su correcto funcionamiento.

## Los distintos archivos
* **Arduino.kt** es un **Singleton** que simula el programa de Arduino, contiene las clásicas funciones **setup()** y **loop()**.
* **Robot.kt** es todo el modelado principal del funcionamiento del robot
* **Orden.kt** contiene una interfaz **Orden** que es heredada por las distintas acciones, esto permite modelar los botones que va a tener el robot para ejecutar las distintas ordenes que se quiera hacer.
* **Motor.kt** permite modelar los dos motores y encargarse de la funcionalidad básica de estos mediante el patrón de diseño **Strategy**.

#include <ArduinoQueue.h>
#include "tatubot.h"

Motor motor0(IN1, IN2);
Motor motor1(IN4, IN3);
ArduinoQueue<int> colaOrdenes(CANTIDAD_ORDENES);


void Robot::iniciar() {
  pinMode(pinEscucharOrdenes, INPUT_PULLUP);
  pinMode(pinAvanzar, INPUT_PULLUP);
  pinMode(pinReversa, INPUT_PULLUP);
  pinMode(pinGiroDerecha, INPUT_PULLUP);
  pinMode(pinGiroIzquierda, INPUT_PULLUP);
  pinMode(pinGiroLoco, INPUT_PULLUP);
  motor0.iniciar();
  motor1.iniciar();
}

void Robot::avanzar(int tiempo) {
  motor0.adelante();
  motor1.adelante();
  delay(tiempo);
  pararRobot();
}

void Robot::retroceder(int tiempo) {
  motor0.atras();
  motor1.atras();
  delay(tiempo);
  pararRobot();
}

void Robot::girarDerecha(int tiempo) {
  motor0.parar();
  motor1.adelante();
  delay(tiempo);
  pararRobot();
}

void Robot::girarIzquierda(int tiempo) {
  motor0.adelante();
  motor1.parar();
  delay(tiempo);
  pararRobot();
}

void Robot::pararRobot() {
  motor0.parar();
  motor1.parar();
}

void Robot::giroLoco(){
  motor0.adelante();
  motor1.atras();
  delay(1000);
  pararRobot();
}

void Robot::escucharOrdenes() {
  while(colaOrdenes.itemCount() < CANTIDAD_ORDENES) {
    if (pinAvanzar == LOW) {          
      colaOrdenes.enqueue(1);
    }
    if (pinReversa == LOW) {          
      colaOrdenes.enqueue(2);
    }
    if (pinGiroDerecha == LOW) {          
      colaOrdenes.enqueue(3);
    }
    if (pinGiroIzquierda == LOW) {          
      colaOrdenes.enqueue(4);
    }
    if (pinGiroLoco == LOW) {          
      colaOrdenes.enqueue(5);
    }
  }
  ejecutarTodasLasOrdenes();
}

void Robot::ejecutarTodasLasOrdenes() {
  for(int i=0; i<colaOrdenes.itemCount(); i++) {
    ejecutarOrden(colaOrdenes.dequeue());
  }
}

void Robot::ejecutarOrden(byte caso) {
  switch(caso) {
    case 1:
      avanzar(2000);
      break;
    case 2:
      retroceder(2000);
      break;
    case 3:
      girarDerecha(500);
      break;
    case 4:
      girarIzquierda(500);
      break;
    case 5:
      giroLoco();
      break;
  }
}


//---------------------------------------------
Motor::Motor(byte pinAtras, byte pinAdelante) {
  this->pinAtras = pinAtras;
  this->pinAdelante = pinAdelante;
}

void Motor::iniciar() {
  pinMode(pinAtras, OUTPUT);
  pinMode(pinAdelante, OUTPUT);
  this->parar();
}

void Motor::adelante() {
  analogWrite(pinAtras, 0);
  analogWrite(pinAdelante, 255);
}

void Motor::atras() {
  analogWrite(pinAdelante, 255);
  analogWrite(pinAtras, 0);
}

void Motor::parar() {
  analogWrite(pinAdelante, 0);
  analogWrite(pinAtras, 0);
}

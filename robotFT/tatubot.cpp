#include <ArduinoQueue.h>
#include "tatubot.h"
#include "LedControl.h"     

Motor motor0(IN1, IN2, ENA);
Motor motor1(IN4, IN3, ENB);
ArduinoQueue<int> colaOrdenes(CANTIDAD_ORDENES);
LedControl matrizLeds=LedControl(DIN,CLK,CS,MATRICES);

void Robot::iniciar() {
  pinMode(pinEscucharOrdenes, INPUT_PULLUP);
  pinMode(pinAvanzar, INPUT_PULLUP);
  pinMode(pinReversa, INPUT_PULLUP);
  pinMode(pinGiroDerecha, INPUT_PULLUP);
  pinMode(pinGiroIzquierda, INPUT_PULLUP);
  pinMode(pinFinOrdenes, INPUT_PULLUP);
  motor0.iniciar();
  motor1.iniciar();
  matrizLeds.shutdown(0,false);     
  matrizLeds.setIntensity(0,4);    
  matrizLeds.clearDisplay(0);    
  matrizLeds.shutdown(1,false);    
  matrizLeds.setIntensity(1,4);    
  matrizLeds.clearDisplay(1);    
}

void Robot::avanzar(int velocidad) {
  motor0.adelante(velocidad);
  motor1.adelante(velocidad);
  delay(1000);
  pararRobot();
}

void Robot::retroceder(int velocidad) {
  motor0.atras(velocidad);
  motor1.atras(velocidad);
  delay(1000);
  pararRobot();
}

void Robot::girarDerecha(int velocidad) {
  motor0.parar();
  motor1.adelante(velocidad);
  delay(1000);
  pararRobot();
}

void Robot::girarIzquierda(int velocidad) {
  motor0.adelante(velocidad);
  motor1.parar();
  delay(1000);
  pararRobot();
}

void Robot::pararRobot() {
  motor0.parar();
  motor1.parar();
}

void Robot::escucharOrdenes() {
  while(colaOrdenes.itemCount() < CANTIDAD_ORDENES || pinFinOrdenes == LOW) {
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
      avanzar(VELOCIDAD_MOTOR);
      break;
    case 2:
      retroceder(VELOCIDAD_MOTOR);
      break;
    case 3:
      girarDerecha(VELOCIDAD_MOTOR);
      break;
    case 4:
      girarIzquierda(VELOCIDAD_MOTOR);
      break;
  }
}

void Robot::dibujarCarita(byte ojos[8], byte boca[8]) {     
  for (int i = 0; i < 8; i++)     
  {
    matrizLeds.setRow(0,i,ojos[i]);   
  }
  for (int i = 0; i < 8; i++)     
  {
    matrizLeds.setRow(1,i,boca[i]);    
  }
}

//---------------------------------------------
Motor::Motor(byte pinAtras, byte pinAdelante, byte pinVelocidad) {
  this->pinAtras = pinAtras;
  this->pinAdelante = pinAdelante;
  this->pinVelocidad = pinVelocidad;
}

void Motor::iniciar() {
  pinMode(pinAtras, OUTPUT);
  pinMode(pinAdelante, OUTPUT);
  pinMode(pinVelocidad, OUTPUT);
  this->parar();
}

void Motor::adelante(int velocidad) {
  analogWrite(pinVelocidad, velocidad);
  digitalWrite(pinAtras, LOW);
  digitalWrite(pinAdelante, HIGH);
}

void Motor::atras(int velocidad) {
  analogWrite(pinVelocidad, velocidad);
  digitalWrite(pinAdelante, HIGH);
  digitalWrite(pinAtras, LOW);
}

void Motor::parar() {
  analogWrite(pinVelocidad, 0);
}

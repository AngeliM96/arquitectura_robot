#include <ArduinoQueue.h>
#include "tatubot.h"
#include "LedControl.h"     
#include "caritas.h"

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
  Serial.begin(115200);
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
  Serial.print("Avanzando \n");
  delay(1000);
  pararRobot();
}

void Robot::retroceder(int velocidad) {
  motor0.atras(velocidad);
  motor1.atras(velocidad);
  Serial.print("Retrocediendo \n");
  delay(1000);
  pararRobot();
}

void Robot::girarDerecha(int velocidad) {
  motor0.parar();
  motor1.adelante(velocidad);
  Serial.print("Girando a la derecha \n");
  delay(1000);
  pararRobot();
}

void Robot::girarIzquierda(int velocidad) {
  motor0.adelante(velocidad);
  motor1.parar();
  Serial.print("Girando a la izquierda \n");
  delay(1000);
  pararRobot();
}

void Robot::pararRobot() {
  motor0.parar();
  motor1.parar();
}

void Robot::escucharOrdenes() {
  while(colaOrdenes.itemCount() < CANTIDAD_ORDENES && digitalRead(pinFinOrdenes) != LOW) {
    if (digitalRead(pinAvanzar) == LOW) {
      dibujarCaritaSorprendida();          
      colaOrdenes.enqueue(1);
      Serial.print("Orden para avanzar en cola \n");
      delay(500);
      dibujarCaritaFeliz();      
    }
    if (digitalRead(pinReversa) == LOW) {
      dibujarCaritaSorprendida();           
      colaOrdenes.enqueue(2);
      Serial.print("Orden para retroceder en cola \n");
      delay(500);
      dibujarCaritaFeliz(); 
    }
    if (digitalRead(pinGiroDerecha) == LOW) {  
      dibujarCaritaSorprendida();         
      colaOrdenes.enqueue(3);
      Serial.print("Orden para girar a la derecha en cola \n");
      delay(500);
      dibujarCaritaFeliz(); 
    }
    if (digitalRead(pinGiroIzquierda) == LOW) {    
      dibujarCaritaSorprendida();       
      colaOrdenes.enqueue(4);
      Serial.print("Orden para girar a la izquierda en cola \n");
      delay(500);
      dibujarCaritaFeliz(); 
    }
  }
  if(colaOrdenes.itemCount() < CANTIDAD_ORDENES) {
    Serial.print("Se enoja por cancelar antes de las 10 ordenes");
    dibujarCaritaEnojada();
    delay(500);
  }
  Serial.print("Se ejecutan las ordenes \n");
  Serial.print(colaOrdenes.itemCount());
  ejecutarTodasLasOrdenes();
}

void Robot::ejecutarTodasLasOrdenes() {
  int cantidadOrdenes = colaOrdenes.itemCount();
  for(int i=0; i<cantidadOrdenes; i++) {
    Serial.print(colaOrdenes.itemCount());
    dibujarCaritaEntusiasmada();
    ejecutarOrden(colaOrdenes.dequeue());
    dibujarCaritaFeliz();
    delay(1000);
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

void Robot::dibujarCaritaFeliz() { dibujarCarita(felizOjos,  felizBoca); }
void Robot::dibujarCaritaSorprendida() { dibujarCarita(sorprendidoOjos,  sorprendidoBoca); }
void Robot::dibujarCaritaEntusiasmada() { dibujarCarita(entusiasmadoOjos,  entusiasmadoBoca); }
void Robot::dibujarCaritaTriste() { dibujarCarita(tristeOjos,  tristeBoca); }
void Robot::dibujarCaritaEnojada() { dibujarCarita(enojadoOjos,  enojadoBoca); }
void Robot::despertar() {
  dibujarCarita(cerradosOjos,  cerradosBoca);
  delay(300);
  dibujarCarita(felizOjos,  cerradosBoca);
  delay(500);
  dibujarCarita(cerradosOjos,  cerradosBoca);
  delay(300);
  dibujarCarita(felizOjos,  cerradosBoca);
  delay(500);
  dibujarCaritaEntusiasmada();
  delay(500);
  dibujarCaritaFeliz();
  delay(500);
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

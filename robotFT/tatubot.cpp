#include <ArduinoQueue.h>
#include "tatubot.h"
#include "LedControl.h"     
#include "caritas.h"

Motor motor0(IN1, IN2, ENA);
Motor motor1(IN4, IN3, ENB);
Led led1(PIN_R_A,PIN_G_A,PIN_B_A);
Led led2(PIN_R_B,PIN_G_B,PIN_B_B);
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
  led1.iniciar();
  led2.iniciar();
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
  led1.rgb('g');
  led2.rgb('g');
  Serial.print("Avanzando \n");
  delay(1800);
  pararRobot();
  led1.rgb('a');
  led2.rgb('a');
}

void Robot::retroceder(int velocidad) {
  motor0.atras(velocidad);
  motor1.atras(velocidad);
  led1.rgb('r');
  led2.rgb('r');
  Serial.print("Retrocediendo \n");
  delay(1600);
  pararRobot();
  led1.rgb('a');
  led2.rgb('a');
}

void Robot::girarDerecha(int velocidad) {
  motor0.parar();
  motor1.adelante(velocidad);
  led2.rgb('b');
  Serial.print("Girando a la derecha \n");
  delay(3000);
  pararRobot();
  led2.rgb('a');
}

void Robot::girarIzquierda(int velocidad) {
  motor0.adelante(velocidad);
  motor1.parar();
  led1.rgb('b');
  Serial.print("Girando a la izquierda \n");
  delay(3000);
  pararRobot();
  led1.rgb('a');
  }

void Robot::pararRobot() {
  motor0.parar();
  motor1.parar();
  led1.rgb('a');
  led2.rgb('a');
}

void Robot::escucharOrdenes() {
  while(colaOrdenes.itemCount() < CANTIDAD_ORDENES && digitalRead(pinFinOrdenes) != LOW) {
    if (digitalRead(pinAvanzar) == LOW) {
      dibujarCaritaSorprendida();          
      colaOrdenes.enqueue(1);
      led1.rgb('g');
      led2.rgb('g');
      Serial.print("Orden para avanzar en cola \n");
      delay(500);
      led1.rgb('a');
      led2.rgb('a');
      dibujarCaritaFeliz();      
    }
    if (digitalRead(pinReversa) == LOW) {
      dibujarCaritaSorprendida();           
      colaOrdenes.enqueue(2);
      led1.rgb('r');
      led2.rgb('r');
      Serial.print("Orden para retroceder en cola \n");
      delay(500);
      led1.rgb('a');
      led2.rgb('a');
      dibujarCaritaFeliz(); 
    }
    if (digitalRead(pinGiroDerecha) == LOW) {  
      dibujarCaritaSorprendida();         
      colaOrdenes.enqueue(3);
      led2.rgb('b');
      Serial.print("Orden para girar a la derecha en cola \n");
      delay(500);
      led2.rgb('a');
      dibujarCaritaFeliz(); 
    }
    if (digitalRead(pinGiroIzquierda) == LOW) {    
      dibujarCaritaSorprendida();       
      colaOrdenes.enqueue(4);
      led1.rgb('b');
      Serial.print("Orden para girar a la izquierda en cola \n");
      delay(500);
      led1.rgb('a');
      dibujarCaritaFeliz(); 
    }
  }
  if(colaOrdenes.itemCount() < 3) {
    Serial.print("Se enoja por cancelar antes de las 3 ordenes");
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


void Robot::dibujarCaritaFeliz() { dibujarCarita(ojoFeliz,  ojoFeliz); }
void Robot::dibujarCaritaSorprendida() { dibujarCarita(ojoDefault,  ojoDefault); }
void Robot::dibujarCaritaEntusiasmada() { dibujarCarita(ojoCorazonCabeza,  ojoCorazonCabeza); }
void Robot::dibujarCaritaTriste() { dibujarCarita(ojoCerrado,  ojoCerrado); }
void Robot::dibujarCaritaEnojada() { dibujarCarita(ojoEnojadoIzqCabeza,  ojoEnojadoDerCabeza); }
void Robot::dibujarCaritaGuiniando() { dibujarCarita(ojoFeliz,  ojoCerrado); }
void Robot::despertar() {
  dibujarCarita(ojoCerrado,  ojoCerrado);
  delay(300);
  dibujarCarita(ojoDefault,  ojoDefault);
  delay(500);
  dibujarCarita(ojoCerrado,  ojoCerrado);
  delay(300);
  dibujarCarita(ojoFeliz,  ojoFeliz);
  delay(1000);
  dibujarCaritaGuiniando();
  delay(250);
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
  digitalWrite(pinAdelante, LOW);
  digitalWrite(pinAtras, HIGH);
}

void Motor::parar() {
  analogWrite(pinVelocidad, 0);
}


//-------------------------------------------------------
Led::Led(byte ledR, byte ledG, byte ledB) {
  this->ledR = ledR;
  this->ledG = ledG;
  this->ledB = ledB;
}

void Led::iniciar() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  this->rgb('a');
}


void Led::rgb(char color) {
  switch (color) {
    case 'r': //red
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledB, HIGH);
      break;
    case 'g': //green
      digitalWrite(ledR, HIGH);
      digitalWrite(ledG, LOW);
      digitalWrite(ledB, HIGH);
      break;
    case 'y': //yellow
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, LOW);
      digitalWrite(ledB, HIGH);
      break;
    case 'b': //blue
      digitalWrite(ledR, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledB, LOW);
      break;
    case 'a': //apagado
      digitalWrite(ledR, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledB, HIGH);
      break;
  }
}

/*----------------------------------------------------------
    Librería para crear robot Tatu-bot
  ----------------------------------------------------------*/
#ifndef TATUBOT_H
#define TATUBOT_H
#include <Arduino.h>

// Motor 1
#define IN1 2
#define IN2 3
#define ENA 5
// Motor 2
#define IN3 7
#define IN4 8
#define ENB 9
// Matriz de Leds
#define DIN 11 
#define CLK 13 
#define CS 10
#define MATRICES 2
// Pulsadores
#define PIN_INICIO_ORDENES A0
#define PIN_ORDEN_AVANZAR A1
#define PIN_ORDEN_REVERSA A2
#define PIN_ORDEN_GIRO_DERECHA A3
#define PIN_ORDEN_GIRO_IZQUIERDA A4
#define PIN_FIN_ORDENES A5


#define CANTIDAD_ORDENES 10
#define VELOCIDAD_MOTOR 100

class Motor {
  private:
    byte pinAtras;
    byte pinAdelante;
    byte pinVelocidad;
    
  public:
    Motor(byte pinAtras, byte pinAdelante, byte pinVelocidad);
    void iniciar();
    void adelante(int velocidad);
    void atras(int velocidad);
    void parar();
};


class Robot {
  private:
    int listaOrdenes[10];
  public:
    byte pinEscucharOrdenes = PIN_INICIO_ORDENES;
    byte pinAvanzar = PIN_ORDEN_AVANZAR;
    byte pinReversa = PIN_ORDEN_REVERSA;
    byte pinGiroDerecha = PIN_ORDEN_GIRO_DERECHA;
    byte pinGiroIzquierda = PIN_ORDEN_GIRO_IZQUIERDA;
    byte pinFinOrdenes = PIN_FIN_ORDENES;
    
    void iniciar();
    void avanzar(int velocidad);
    void retroceder(int velocidad);
    void girarDerecha(int velocidad);
    void girarIzquierda(int velocidad);
    void pararRobot();
    void escucharOrdenes();
    void ejecutarTodasLasOrdenes();
    void ejecutarOrden(byte caso);
    void dibujarCarita(byte ojos[8], byte boca[8]);
};

#endif

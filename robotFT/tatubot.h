/*----------------------------------------------------------
    Librería para crear robot Tatu-bot
  ----------------------------------------------------------*/
#ifndef TATUBOT_H
#define TATUBOT_H
#include <Arduino.h>

#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 9
#define PULSADOR_ORDENES 0 //La idea es que este sea el botón con el que se escuchan las ordenes
#define CANTIDAD_ORDENES 10
#define PIN_ORDEN_AVANZAR 1
#define PIN_ORDEN_REVERSA 2
#define PIN_ORDEN_GIRO_DERECHA 3
#define PIN_ORDEN_GIRO_IZQUIERDA 4
#define PIN_ORDEN_GIRO_LOCO 5

class Motor {
  private:
    byte pinAtras;
    byte pinAdelante;
    
  public:
    Motor(byte pinAtras, byte pinAdelante);
    void iniciar();
    void adelante();
    void atras();
    void parar();
};


class Robot {
  private:
    int listaOrdenes[10];  
  public:
    byte pinEscucharOrdenes = PULSADOR_ORDENES;
    byte pinAvanzar = PIN_ORDEN_AVANZAR;
    byte pinReversa = PIN_ORDEN_REVERSA;
    byte pinGiroDerecha = PIN_ORDEN_GIRO_DERECHA;
    byte pinGiroIzquierda = PIN_ORDEN_GIRO_IZQUIERDA;
    byte pinGiroLoco = PIN_ORDEN_GIRO_LOCO;
    
    void iniciar();
    void avanzar(int tiempo);
    void retroceder(int tiempo);
    void girarDerecha(int tiempo);
    void girarIzquierda(int tiempo);
    void pararRobot();
    void giroLoco();
    void escucharOrdenes();
    void ejecutarTodasLasOrdenes();
    void ejecutarOrden(byte caso);
};

#endif

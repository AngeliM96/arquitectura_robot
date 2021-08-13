/*----------------------------------------------------------
    Librería para crear robot Tatu-bot
  ----------------------------------------------------------*/
#ifndef TATUBOT_H
#define TATUBOT_H
#include <Arduino.h>

#define IN1 2
#define IN2 3
#define ENA 5
#define IN3 7
#define IN4 8
#define ENB 9
#define PIN_INICIO_ORDENES 66 //La idea es que este sea el botón con el que se escuchan las ordenes
#define PIN_FIN_ORDENES 66
#define PIN_ORDEN_AVANZAR 66
#define PIN_ORDEN_REVERSA 66
#define PIN_ORDEN_GIRO_DERECHA 66
#define PIN_ORDEN_GIRO_IZQUIERDA 66
#define PIN_ORDEN_GIRO_LOCO 66

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
    byte pinGiroLoco = PIN_ORDEN_GIRO_LOCO;
    byte pinFinOrdenes = PIN_FIN_ORDENES;
    
    void iniciar();
    void avanzar(int velocidad);
    void retroceder(int velocidad);
    void girarDerecha(int velocidad);
    void girarIzquierda(int velocidad);
    void pararRobot();
    void giroLoco();
    void escucharOrdenes();
    void ejecutarTodasLasOrdenes();
    void ejecutarOrden(byte caso);
};

#endif

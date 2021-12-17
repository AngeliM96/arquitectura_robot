/*----------------------------------------------------------
    Librería para crear robot Tatu-bot
  ----------------------------------------------------------*/
#ifndef TATUBOT_H
#define TATUBOT_H
#include <Arduino.h>

// Motor 1
#define IN1 4 // 3 
#define IN2 22 // 2
#define ENA 5 // 5
// Motor 2
#define IN3 6 // 8 
#define IN4 23 // 7
#define ENB 7 // 9
// Matriz de Leds
#define DIN 44 // 11 
#define CLK 47 // 13 
#define CS 45 // 10
#define MATRICES 2
// Pulsadores
#define PIN_INICIO_ORDENES A0
#define PIN_FIN_ORDENES A1
#define PIN_ORDEN_AVANZAR A2
#define PIN_ORDEN_REVERSA A3
#define PIN_ORDEN_GIRO_DERECHA A5
#define PIN_ORDEN_GIRO_IZQUIERDA A4
//Led 1
#define PIN_R_A 8
#define PIN_G_A 9
#define PIN_B_A 10
//Led 2
#define PIN_R_B 11
#define PIN_G_B 12
#define PIN_B_B 13


#define CANTIDAD_ORDENES 10
#define VELOCIDAD_MOTOR 4000

class Led {
  private:
    byte ledR;
    byte ledG;
    byte ledB;

   public:
    Led(byte ledR, byte ledG, byte ledB);
    void iniciar();
    void rgb(char color);
      };


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
    void dibujarCaritaFeliz();
    void dibujarCaritaSorprendida();
    void dibujarCaritaEntusiasmada();
    void dibujarCaritaGuiniando();
    void dibujarCaritaTriste();
    void dibujarCaritaEnojada();
    void despertar();
};

#endif

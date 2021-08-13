#include "LedControl.h"     // incluye libreria LedControl

LedControl lc=LedControl(11,13,10,2); // crea objeto

#define demora 1000     // constante demora con valor de 1000

byte cero[8]= {       // array que contiene todos los elementos de las
  B00111000,        // filas necesarias por mostrar el digito cero
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B00111000
};

byte uno[8]= {        // array que contiene todos los elementos de las
  B00010000,        // filas necesarias por mostrar el digito uno
  B00110000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00111000
};


void setup() {
  lc.shutdown(0,false);     // enciende la matriz
  lc.setIntensity(0,4);     // establece brillo
  lc.clearDisplay(0);     // blanquea matriz
  lc.shutdown(1,false);     // enciende la matriz
  lc.setIntensity(1,4);     // establece brillo
  lc.clearDisplay(1);     // blanquea matriz
}

void loop(){
  mostrar_0();        // llama funcion mostrar_0
  delay(demora);      // demora
  mostrar_1();        // llama funcion mostrar_1
  delay(demora);      // demora
}

void mostrar_0(){     // funcion mostrar_0
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
    lc.setRow(0,i,cero[i]);   // establece fila con valor de array cero en misma posicion
  }
}

void mostrar_1(){      // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array 
  {
    lc.setRow(1,i,uno[i]);    // establece fila con valor de array uno en misma posicion
  }
}

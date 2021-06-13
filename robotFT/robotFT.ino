/*
  Programa para manejar el robot Tatu-bot de Futhur Tech
 */
#include "tatubot.h"
Robot tatubot;

void setup(){
  tatubot.iniciar();
}

void loop(){
  if (PULSADOR_ORDENES == LOW) {          
    tatubot.escucharOrdenes();
  }
}

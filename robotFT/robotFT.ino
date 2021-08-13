/*
  Programa para manejar el robot Tatu-bot de Futhur Tech
 */
#include "tatubot.h"
#include "caritas.h"
Robot tatubot;

void setup(){
  tatubot.iniciar();
}

void loop(){
  if (PIN_INICIO_ORDENES == LOW) {          
    tatubot.escucharOrdenes();
  }
  if (PIN_ORDEN_AVANZAR == LOW) {          
    tatubot.dibujarCarita(felizOjos, felizBoca);
  }
  if (PIN_ORDEN_REVERSA == LOW) {          
    tatubot.dibujarCarita(entusiasmadoOjos,  entusiasmadoBoca); 
  }
  if (PIN_ORDEN_GIRO_DERECHA == LOW) {          
    tatubot.dibujarCarita(enojadoOjos, enojadoBoca);  
  }
  if (PIN_ORDEN_GIRO_IZQUIERDA == LOW) {          
    tatubot.dibujarCarita(sorprendidoOjos, sorprendidoBoca);
  }
  if (PIN_FIN_ORDENES == LOW) {          
    tatubot.dibujarCarita(tristeOjos, tristeBoca);
  }
}

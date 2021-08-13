#include "LedControl.h"     
LedControl lc=LedControl(11,13,10,2);

byte felizOjos[8]= {       
  B00000000,       
  B01100110,
  B10000001,
  B01100110,
  B10011001,
  B10011001,
  B01100110,
  B00000000
};

byte felizBoca[8]= {        
  B00000000,        
  B11111111,
  B10000001,
  B10000001,
  B01000010,
  B00111100,
  B00000000,
  B00000000
};


void setup() {
  lc.shutdown(0,false);     
  lc.setIntensity(0,4);    
  lc.clearDisplay(0);    
  lc.shutdown(1,false);    
  lc.setIntensity(1,4);    
  lc.clearDisplay(1);     
}

void loop(){
  carita_feliz();    
  delay(1000);
}

void carita_feliz(){     // funcion mostrar_0
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
    lc.setRow(0,i,felizOjos[i]);   // establece fila con valor de array cero en misma posicion
  }
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array 
  {
    lc.setRow(1,i,felizBoca[i]);    // establece fila con valor de array uno en misma posicion
  }
}

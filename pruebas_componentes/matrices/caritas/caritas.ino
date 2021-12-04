#include "LedControl.h"     
LedControl lc=LedControl(44,47,45,2);

byte felizOjos[8]= {       
  B00000000,       
  B00000000,
  B00000000,
  B01100110,
  B10011001,
  B10011001,
  B01100110,
  B00000000
};

byte felizBoca[8]= {        
  B00000000,        
  B00000000,
  B10000001,
  B10000001,
  B01000010,
  B00111100,
  B00000000,
  B00000000
};

byte entusiasmadoOjos[8]= {       
  B00000000,       
  B01100110,
  B10000001,
  B01100110,
  B10011001,
  B10011001,
  B01100110,
  B00000000
};

byte entusiasmadoBoca[8]= {        
  B00000000,        
  B11111111,
  B10000001,
  B10000001,
  B01000010,
  B00111100,
  B00000000,
  B00000000
};

byte enojadoOjos[8]= {       
  B00000000,       
  B01000010,
  B00100100,
  B01011010,
  B10100101,
  B10011001,
  B01100110,
  B00000000
};

byte enojadoBoca[8]= {        
  B00000000,        
  B00111100,
  B01000010,
  B10000001,
  B10000001,
  B00000000,
  B00000000,
  B00000000
};

byte sorprendidoOjos[8]= {       
  B01100110,        
  B10011001,
  B00000000,
  B01100110,
  B10011001,
  B10011001,
  B01100110,
  B00000000
};

byte sorprendidoBoca[8]= {        
  B00000000,        
  B00011000,
  B00100100,
  B01000010,
  B01000010,
  B00100100,
  B00011000,
  B00000000
};

byte tristeOjos[8]= {       
  B00000000,       
  B00000000,
  B00000000,
  B01100110,
  B10011001,
  B10011001,
  B01100110,
  B00000000
};

byte tristeBoca[8]= {        
  B00000000,        
  B00000000,
  B00111100,
  B01000010,
  B10000001,
  B10000001,
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
  dibujarCarita(felizOjos, felizOjos);    
  delay(1000);
  dibujarCarita(entusiasmadoOjos,  felizOjos);    
  delay(1000);
  dibujarCarita(enojadoOjos, felizOjos);    
  delay(1000);
  dibujarCarita(sorprendidoOjos, felizOjos);
  delay(1000);
  dibujarCarita(tristeOjos, felizOjos);
  delay(1000);
}

void dibujarCarita(byte ojos[8], byte boca[8]){     // funcion mostrar_0
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
    lc.setRow(0,i,ojos[i]);   // establece fila con valor de array cero en misma posicion
  }
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array 
  {
    lc.setRow(1,i,boca[i]);    // establece fila con valor de array uno en misma posicion
  }
}

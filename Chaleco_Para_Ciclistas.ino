/*Mayra Alejandra Diaz Romero
  Curso de Arduino 
  Modulo 2
  Lección 4 - Chaleco Para Ciclistas*/

//Declaración de Variables 

int bot[]={1,2,3};
int led[]={4,5,6,7,8,9,10,11,12,13};
int numLeds=10;
int numBot=3;
int tiempoRet=400;
int tiempoRetOcioso=200;
int estePin;
int cuenta_der=0;
int cuenta_izq=0;
int cuenta_ocio=0;
boolean bot_alto=LOW;
boolean bot_der=LOW;
boolean bot_izq=LOW;

//Instrucciones
void setup() {
  for(estePin=0;estePin<numBot;estePin++){
    pinMode(bot[estePin],INPUT);
  }
  for(estePin=0;estePin<numLeds;estePin++){
    pinMode(led[estePin],OUTPUT);
  }
}

void loop() {

  //Botones
  bot_der=digitalRead(bot[0]);
  bot_alto=digitalRead(bot[1]);
  bot_izq=digitalRead(bot[2]);

  //Incialización de Leds

  for(estePin=0;estePin<numLeds;estePin++){
    digitalWrite(led[estePin],LOW);
  }

  //Llamado De Funciones

  if(bot_izq==HIGH){
    Izquierda();
  }
  else if(bot_alto==HIGH){
    Alto();
  }
  else if(bot_der==HIGH){
    Derecha();
  }
  else {
    Ociosa();
  }
    for(estePin=0;estePin<numLeds;estePin++){
    digitalWrite(led[estePin],LOW);
  }
}
//Izquierda

void Izquierda(){
  switch(cuenta_izq){
    case 0:
          digitalWrite(led[2],HIGH);
          digitalWrite(led[9],HIGH);
          digitalWrite(led[4],HIGH);
          break;
    case 1:
          digitalWrite(led[1],HIGH);
          digitalWrite(led[8],HIGH);
          digitalWrite(led[5],HIGH);
          break;
    case 2:
          digitalWrite(led[0],HIGH);
          digitalWrite(led[7],HIGH);
          digitalWrite(led[6],HIGH);
          break;
          default:;
  }
  delay(tiempoRet);
  cuenta_izq++;
  if(cuenta_izq>3){
    cuenta_izq=0;
  }
}

//Alto

void Alto(){
    for(estePin=0; estePin<10; estePin++){
      digitalWrite(led[estePin],HIGH);
    }
    delay(tiempoRet);
    for(estePin=0;estePin<10;estePin++){
      digitalWrite(led[estePin],LOW);
    }
    delay(tiempoRet);
}

//Derecha

void Derecha(){
  switch(cuenta_der){
    case 0:
          digitalWrite(led[0],HIGH);
          digitalWrite(led[8],HIGH);
          digitalWrite(led[6],HIGH);
          break;
    case 1:
          digitalWrite(led[1],HIGH);
          digitalWrite(led[9],HIGH);
          digitalWrite(led[5],HIGH);
          break;
    case 2:
          digitalWrite(led[2],HIGH);
          digitalWrite(led[3],HIGH);
          digitalWrite(led[4],HIGH);
          break;
          default:;
  }
  delay(tiempoRet);
  cuenta_der++;
  if(cuenta_der>3){
    cuenta_der=0;
  }
}
//Ociosa

void Ociosa(){
 digitalWrite (led[cuenta_ocio],HIGH);
 digitalWrite (led[cuenta_ocio+4],HIGH);
 delay (tiempoRetOcioso);
 digitalWrite (led[cuenta_ocio],LOW);
 digitalWrite (led[cuenta_ocio+4],LOW);
 cuenta_ocio++;
 if (cuenta_ocio > 3)
 {
 cuenta_ocio = 0;
 }
}


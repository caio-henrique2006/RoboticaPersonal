#include <Ultrasonic.h>

Ultrasonic ultrassomA(8, 9); // trig, Echo respectivamente
Ultrasonic ultrassomB(11, 10); // trig, Echo respectivamente

long distanciaA;
long distanciaB;

const int DISTANCIA_DETECCAO = 100;
const int altoFalante = 12;

void setup() {
  pinMode(altoFalante, OUTPUT);
  Serial.begin(9600);
} 

void loop() {
  distanciaA = ultrassomA.read(CM);
  distanciaB = ultrassomB.read(CM);
  // Serial.println(millis());
  // Serial.println(distanciaB);
  // Serial.println(distanciaA);
  if (distanciaB <= DISTANCIA_DETECCAO) { 
    int tempoRestante = millis();
    int tempoAtual = 0;
    do {
      tempoAtual = millis();
      Serial.println("Entrando");
      distanciaA = ultrassomA.read(CM);
      // Serial.println(distanciaA);
      if(distanciaA <= DISTANCIA_DETECCAO) {
        entrouNaSala();
        delay(2500);
        break;
      }
    } while(tempoAtual-tempoRestante < 10000);
  }
  else if (distanciaA <= DISTANCIA_DETECCAO) {
    int tempoRestante = millis();
    int tempoAtual = 0;
    do {
      tempoAtual = millis();
      Serial.println("Saindo");
      distanciaB = ultrassomB.read(CM);
      // Serial.println(distanciaB);
      if(distanciaB <= DISTANCIA_DETECCAO) {
        saiuDaSala();
        delay(2500);
        break;
      }
    } while(tempoAtual-tempoRestante < 10000);
  }
  // if (distanciaA <= DISTANCIA_DETECCAO) { 
  //   int tempoRestante = millis();
  //   int tempoAtual = 0;
  //   do {
  //     tempoAtual = millis();
  //     Serial.println("Saindo");
  //     distanciaB = ultrassomB.read(CM);
  //     Serial.println(distanciaB);
  //     if(distanciaB <= DISTANCIA_DETECCAO) {
  //       saiuDaSala();
  //       delay(1000);
  //       break;
  //     }
  //   } while(tempoAtual-tempoRestante < 5000);
  // }
  // else if (distanciaB <= DISTANCIA_DETECCAO) {
  //   int tempoRestante = millis();
  //   int tempoAtual = 0;
  //   do {
  //     tempoAtual = millis();
  //     Serial.println("Entrando");
  //     distanciaA = ultrassomA.read(CM);
  //     Serial.println(distanciaA);
  //     if(distanciaA <= DISTANCIA_DETECCAO) {
  //       entrouNaSala();
  //       delay(1000);
  //       break;
  //     }
  //   } while(tempoAtual-tempoRestante < 5000);
  // }
  // if (distanciaA <= DISTANCIA_DETECCAO) { 
  //   saiuDaSala();
  //   delay(10000);
  // } if (distanciaB <= DISTANCIA_DETECCAO) {
  //   entrouNaSala();
  //   delay(10000);
  // }
}

void saiuDaSala() {
  tone(altoFalante, 220.5);
  delay(120);
  tone(altoFalante, 174.3);
  delay(120);
  tone(altoFalante, 165);
  delay(120);
  noTone(altoFalante);
}
void entrouNaSala() {
  tone(altoFalante, 261);
  delay(190);
  tone(altoFalante, 220.5);
  delay(120);
  tone(altoFalante, 174.4);
  delay(120);
  tone(altoFalante, 330.3);
  delay(120);
  noTone(altoFalante);
}

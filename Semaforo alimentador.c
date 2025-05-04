#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define btRed 12
#define btGreen 11
#define buzzer 10

char *boasPraticas[] = {
  "Coma frutas diariamente", 
  "Beba muita agua", 
  "Varie os alimentos",
  "Faca lanches saudaveis",
  "Priorize alimentos in natura"
};

char *masPraticas[] = {
  "Agua sim, refrigerante nao", 
  "Mais frutas, menos doces", 
  "Cozinhe em casa, evite fast food",
  "Evite sal e gordura",
  "Evite alimentos ultraprocessados"
};


Adafruit_SSD1306 tela(128,64, &Wire,-1);


void setup() {
  tela.begin(SSD1306_SWITCHCAPVCC, 0X3C);
  pinMode(btRed, INPUT_PULLUP);
  pinMode(btGreen, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  tela.setTextColor(1);
  tela.setCursor(0,0);
  tela.clearDisplay();
}

void loop() {
  tela.setCursor(18,0); // coluna - linha
  tela.setTextSize(2);
  tela.setTextWrap(true);
  if(!digitalRead(btRed)){
    tela.clearDisplay();
    tela.print(masPraticas[random(0,5)]);
    tela.display();
    somRed();
  }
  if(!digitalRead(btGreen)){
    tela.clearDisplay();
    tela.print(boasPraticas[random(0,5)]);
    tela.display();
    somGreen();
  }
  delay(30);
}

void somRed(){
  tone(buzzer,415,400);
  delay(400);
  tone(buzzer,391,400);
  delay(400);
  tone(buzzer,369,400);
  delay(400);
  tone(buzzer,349,700);
  delay(700);
}

void somGreen(){
  tone(buzzer,1046,250);
  delay(250);
  tone(buzzer,1318,250);
  delay(250);
  tone(buzzer,1567,250);
  delay(250);
  tone(buzzer,1046,250);
  delay(250);
  tone(buzzer,1567,500);
  delay(500);
}
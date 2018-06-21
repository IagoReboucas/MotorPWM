#include <Arduino.h>
#include <LiquidCrystal.h>
const int porta = 0;
float valorderotacao = 0;
float valordopotenciometro = 0;
int valornolcd = 0;
float valorderotacao2 = 0;

LiquidCrystal lcd (12,11,5,4,3,2);

void setup() {
     lcd.begin(16,2);
}

void loop() {
    valordopotenciometro = analogRead(porta);
    valornolcd = 100*valordopotenciometro/1023;
    valorderotacao = 255*valordopotenciometro/1023;
    valorderotacao2 = 255-valorderotacao;
    //lcd.clear();
    //lcd.setCursor(7,0);
    //lcd.print(valornolcd);
    //lcd.print("%");
    delay(1000);
    if(valornolcd > 50){
        analogWrite (9, valorderotacao);
        analogWrite (10,0);
        delay(10);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(2*valornolcd-100);
        lcd.println("% de potencia ");
        lcd.setCursor(4,1);
        lcd.print("Direita");
        delay(10);

    }
    if(valornolcd == 50){
        analogWrite (9, 0);
        analogWrite (10, 0);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(0);
        lcd.print("% de potencia ");
        lcd.setCursor(5,1);
        lcd.print("Parado");
        delay(10);
    }
    if(valornolcd < 50){
        analogWrite (9,0);
        analogWrite (10,valorderotacao2);
        delay(10);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(100-2*valornolcd);
        lcd.println("% de potencia ");
        lcd.setCursor(4,1);
        lcd.print("Esquerda");
        delay(10);
    }
    
}
#include <Arduino.h>
#include <string.h>
#include "Passwordlock.h"

void passwordlocksetup() {
    Serial.begin(115200);
}
void passwordlockloop() {
    static String password[]={"AA","BB","CC","DD"};    
    static int passwordstatus=0;
    if(Serial.available()>0){
        String input=Serial.readStringUntil('\n');
        input.trim();
        if(input==password[passwordstatus]){
            Serial.print("Correct password,state ");
            Serial.println(passwordstatus);
            passwordstatus++;
            if(passwordstatus==4){
                Serial.println("All passwords correct, unlocking...");
                passwordstatus=0;
            }
        }else{
            Serial.println("Wrong password, try again");
            passwordstatus=0;
        }
    }
}
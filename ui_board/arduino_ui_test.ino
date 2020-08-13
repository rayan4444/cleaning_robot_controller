/*
Code to test the Robodeck UI board using an arduino
*/
#include <Wire.h>
//make sure you download the Adafruit_MCP23008 library: you can clone it from github or 
//get it from the Arduino Library manager
#include "Adafruit_MCP23008.h"

#define button1 2
#define button2 3 
//The Arduino Uno board I used to test the boards only has 2 interrupt pins. 
//To test the third one, just swap the connections.  

volatile bool flag1, flag2;

//Create and instance of the MCP23008 instance
Adafruit_MCP23008 mcp;

void setup(){
    Serial.begin(9600);
    // init I/O expander
    mcp.begin();
    // init pins 
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    mcp.pinMode(0, INPUT); // we need to set this one as input to make sure both RED and GREEN LED stay off
    mcp.pinMode(1, OUTPUT);
    mcp.pinMode(2, OUTPUT);
    mcp.pinMode(3, OUTPUT);
    mcp.pinMode(4, OUTPUT);
    mcp.pinMode(5, OUTPUT);
    mcp.pinMode(6, OUTPUT);
    mcp.pinMode(7, OUTPUT);

    mcp.digitalWrite(1, LOW); // turning the BLUE LED OFF
    mcp.digitalWrite(2, HIGH); // making sure the RGB LEDs stay off
    mcp.digitalWrite(3, HIGH);
    mcp.digitalWrite(4, HIGH);
    mcp.digitalWrite(5, HIGH);
    mcp.digitalWrite(6, HIGH);
    mcp.digitalWrite(7, HIGH);

    // interrupts for two of the buttons 
    attachInterrupt(digitalPinToInterrupt(button1), button1_isr, FALLING);
    attachInterrupt(digitalPinToInterrupt(button2), button2_isr, FALLING);
}

void loop(){

    toggle_all();
}

void button1_isr(){
    Serial.println("Button1 pressed!");
}

void button2_isr(){
    Serial.println("Button2 pressed!");
}

void toggle_all(){

    //Green/Red LED
    mcp.pinMode(0, OUTPUT);
    mcp.digitalWrite(0, HIGH);
    delay(500);
    mcp.digitalWrite(0, LOW);
    delay(500);
    mcp.pinMode(0, INPUT);

    //Blue LED
    mcp.digitalWrite(1, HIGH);
    delay(500);
    mcp.digitalWrite(1, LOW);
    delay(500);
    
    //RGB LED1
    mcp.digitalWrite(2, LOW);
    delay(500);
    mcp.digitalWrite(2, HIGH);
    delay(500);
    mcp.digitalWrite(3, LOW);
    delay(500);
    mcp.digitalWrite(3, HIGH);
    delay(500);
    mcp.digitalWrite(4, LOW);
    delay(500);
    mcp.digitalWrite(4, HIGH);
    delay(500);

    //RGB LED2
    mcp.digitalWrite(5, LOW);
    delay(500);
    mcp.digitalWrite(5, HIGH);
    delay(500);
    mcp.digitalWrite(6, LOW);
    delay(500);
    mcp.digitalWrite(6, HIGH);
    delay(500);
    mcp.digitalWrite(7, LOW);
    delay(500);
    mcp.digitalWrite(7, HIGH);
    delay(500); 
}
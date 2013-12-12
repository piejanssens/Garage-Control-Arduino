//  Garage Control
//
//  Created by Pieter Janssens on 09/12/13.
//  Copyright (c) 2013 Pieter Janssens. All rights reserved.
//

#include <math.h>
#include <SPI.h>
#include <boards.h>
#include <ble_shield.h>
#include <services.h>
#include "Boards.h"

//To add some form of authentication:
//Change the BLE_PINCODE bytes to any random combination of valid unsigned bytes (0-255)
//Use Google e.g. "76 to hex" will result in "0x4C"
//Define the same 4 pincode bytes in the iOS project

const byte BLE_PINCODE[4] = {0x01, 0x01, 0x01, 0x01};

const int lightSensorPin = 3;   //Connect the LED Grove module to Pin12, Digital 12
const int tempSensorPin = 2;
const int relayPin = 4;   //the Grove port No. you attached a button to
const int reedSwitchPin = 6;

const int thresholdvalue=10;         //The treshold for which the LED should turn on. 
float RlightSensor;         //Resistance of sensor in K
float Rtempsensor;
const int B=3975; 
long previousMillis = 0;        // serial
const long interval = 1000;           // interval at which to blink (milliseconds)
boolean DEBUG_ENABLED = false;
boolean BT_CONNECTED = false;

void setup() {
  Serial.begin(9600);                //Start the Serial connection
  pinMode(relayPin, OUTPUT);            //Set the LED on Digital 12 as an OUTPUT
  pinMode(reedSwitchPin, INPUT_PULLUP);
  pinMode(lightSensorPin, INPUT);
  pinMode(tempSensorPin, INPUT);

  // Init. and start BLE library.
  ble_begin();
}

void loop(){
  // send data only when you receive data:
  if (Serial.available() > 0) {
    if(Serial.read() == 'd') {
      DEBUG_ENABLED = !DEBUG_ENABLED;
      if(DEBUG_ENABLED) {
        Serial.println("-- Debug Enabled");
        previousMillis = 0;
      }
      else {
        Serial.println("-- Debug Disabled");
      }
    }
  }

  // If data is ready
  while(ble_available())
  {
    // read out command and data
    byte data0 = ble_read(); //Relay command
    byte data1 = ble_read(); //Pin 1
    byte data2 = ble_read(); //Pin 2
    byte data3 = ble_read(); //Pin 3
    byte data4 = ble_read(); //Pin 4
   
    if (data0 == 0x01 && data1 == BLE_PINCODE[0] && data2 == BLE_PINCODE[1] && data3 == BLE_PINCODE[2] && data4 == BLE_PINCODE[3])  // Command is to control digital out pin
    {
      digitalWrite(relayPin, HIGH);
      delay(200);
      digitalWrite(relayPin, LOW);
    }
  }

  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    
    // Read light and send out
    uint16_t lightSensorValue = analogRead(lightSensorPin); 
    RlightSensor=(float)(1023-lightSensorValue)*10/lightSensorValue;

    // Read temperature and send out
    uint16_t tempSensorValue = analogRead(tempSensorPin);

    // Read garage door switch and send out
    int reedSwitchValue = digitalRead(reedSwitchPin);
    if (ble_connected()) {
      ble_write(0x0A);
      ble_write(lightSensorValue >> 8);
      ble_write(lightSensorValue);

      ble_write(0x0B);
      ble_write(tempSensorValue >> 8);
      ble_write(tempSensorValue);

      if(reedSwitchValue == HIGH)
      {
        ble_write(0x0C);
        ble_write(0x01);
        ble_write(0x00);
      }
      else
      {
        ble_write(0x0C);
        ble_write(0x00);
        ble_write(0x00);
      }
    }  

    if(DEBUG_ENABLED) {
      if(ble_connected() && !BT_CONNECTED) {
        Serial.println("-- BT Device Connected");
        BT_CONNECTED = true;
      }
      else if (!ble_connected() && BT_CONNECTED) {
        Serial.println("-- BT Device Disconnected");
        BT_CONNECTED = false;
      }

      // save the last time you blinked the LED 
      Serial.print("Light analog read value: ");
      Serial.println(lightSensorValue);
      Serial.print("Light resistance value: ");
      Serial.println(RlightSensor,DEC);//show the ligth intensity on the serial monitor;

      Rtempsensor=(float)(1023-tempSensorValue)*10000/tempSensorValue;
      double celcius=1/(log(Rtempsensor/10000)/B+1/298.15)-273.15;
      Serial.print("Temperature: ");
      Serial.print(celcius);
      Serial.println(" C"); 

      if(reedSwitchValue == HIGH)
      {
        Serial.println("Garage is OPEN");
      }
      else
      {
        Serial.println("Garage is CLOSED");
      }

      Serial.println();      
    }
  }

  // Allow BLE Shield to send/receive data
  ble_do_events();  
} 












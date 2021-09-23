/* Code created by Carlos Gellida, contact me at my email: gellidao@gmail.com */

#include <Arduino.h>
#include <Mathfunctions.h> // This library must be the second to do this program works
#include <WifiFunctions.h>
#include <SPI.h>
#include "printf.h"
#include <RadioGamepad2.h>

Matrix<4, 1> qDeseado = {1.0, 0.0, 0.0, 0.0}; 

Matrix<4, 1> qCurrent = {1.0, 0.0, 0.0, 0.0}; 

bool internetconection = true ;  // Do you want to use PC server? true = yes
bool availableModem = true ; // Do you want to use ESP32 as an access point? true = No


void setup() {
  Serial.begin(115200);

  delay(500) ; 

  // Inicializar WiFi y WebSocket

  if(internetconection){
    if(availableModem){
      taskWifiWithModem(); 
    } else{
      taskWifiNoModem() ; 
    }
  }

  delay(500) ; 

  InitialiceRadio();

}


void loop() {

  recieved = recieve(qCurrent); 

  sended = send(qDeseado) ; 

  if(internetconection){
    // If you activate internect conection option: 
    if(recieved){
      // If messaje was recieved and sended correctly: 
      webSocket.loop(); // Requested to run before to use web socket functions
      getAndSendInfo(qCurrent, qDeseado) ; // Send all the info via Wifi to the computer
  }
  }
  
}
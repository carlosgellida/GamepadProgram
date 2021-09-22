/* Code created by Carlos Gellida, contact me at my email: gellidao@gmail.com */

#include <Arduino.h>
#include <Mathfunctions.h> 
#include <WifiFunctions.h>
#include <SPI.h>
#include "printf.h"
#include <RadioGamepad.h>

Matrix<4, 1> qDeseado = {3.0, 3.0, 3.0, 3.0}; 

Matrix<4, 1> qCurrent = {3.0, 3.0, 3.0, 3.0}; 

void setup() {
  Serial.begin(115200);

  delay(500) ; 

  // Inicializar WiFi y WebSocket
  //Descomentar lineas de abajo en relación a si se tiene o no un modem disponible
  //taskWifiNoModem() ; 
  taskWifiWithModem(); 

  delay(500) ; 

  InitialiceRadio();

}


void loop() {

  recieved = recieve(qCurrent); 

  sended = send(qDeseado) ; 

  if(sended){
    CurrQuaternion = {1, 0, 0, 0}; 

    DesiQuaternion = {1, 0, 0, 0}; 

    webSocket.loop();

    getAndSendInfo() ; // Send all the info to the computer
  }

  
}
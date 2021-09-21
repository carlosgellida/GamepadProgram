/* Code created by Carlos Gellida, contact me at my email: gellidao@gmail.com */

#include <Arduino.h>
#include <Mathfunctions.h> 
#include <WifiFunctions.h>



void setup() {
  Serial.begin(115200);
  delay(1000);

  // Inicializar I2C
  //Wire.begin(); 

  delay(500) ; 

  // Inicializar WiFi y WebSocket

  // Descomentar lineas de abajo en relación a si se tiene o no un modem disponible
  //taskWifiNoModem() ; 
  taskWifiWithModem(); 

}


void loop() {

  CurrQuaternion = {1, 0, 0, 0}; 

  DesiQuaternion = {1, 0, 0, 0}; 

  webSocket.loop();

  getAndSendInfo() ; // Send all the info to the computer

  delay(100); 
}
/*
   Ulatwienie :) dziala z modyfikowanym plikiem elecxxx.h
   Tu sobie wpisujesz zamiast jebac sie z plikiem .cpp

   Jak narazie podstawowe funkcje, ale work in progress co jest    
   porzebne ...
*/

#include <ELECHOUSE_CC1101.h>
#define size 60
byte TX_buffer[size]={0};
byte i;

void setup()
{
  Serial.begin(9600);
  ELECHOUSE_cc1101.Init();
  //                           Standardowe cfg CC1101
  //                           ADR  DATA          OPIS
  ELECHOUSE_cc1101.SpiWriteReg(0x0D,0x10),HEX;  //FREQ 
  ELECHOUSE_cc1101.SpiWriteReg(0x0E,0xA7),HEX;  //FREQ1
  ELECHOUSE_cc1101.SpiWriteReg(0x0F,0x62),HEX;  //FREQ
  ELECHOUSE_cc1101.SpiWriteReg(0x10,0x5B),HEX;  //MDMCFG4
  ELECHOUSE_cc1101.SpiWriteReg(0x11,0xF8),HEX;  //MDMCFG3
  ELECHOUSE_cc1101.SpiWriteReg(0x12,0x03),HEX;  //MDMCFG2
  ELECHOUSE_cc1101.SpiWriteReg(0x13,0x22),HEX;  //MDMCFG1
  ELECHOUSE_cc1101.SpiWriteReg(0x22,0x10),HEX;  //FREND0 
  ELECHOUSE_cc1101.SpiWriteReg(0x3E,0x60),HEX;  //PATABLE
  ELECHOUSE_cc1101.SpiWriteReg(0x15,0x62),HEX;  //DEVIATIAN
  ELECHOUSE_cc1101.SpiWriteReg(0x06,0x3D),HEX;  //PACKET LEN
  delay(500);


 for(i=0;i<size;i++)
  {
     TX_buffer[i]=i;
  }
}

void loop()
{
  ELECHOUSE_cc1101.SendData(TX_buffer,size);
  
}

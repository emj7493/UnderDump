// Programa Jorge v1 //

#include <SoftwareSerial.h>
#include <stdlib.h>

int     pinRele1s                 = 2      ;
int     pinRele2s                 = 4      ;
int     pinRele3s                 = 6      ;

int     pinRele1b                 = 3      ;
int     pinRele2b                 = 5      ;
int     pinRele3b                 = 7      ;

String  inputString_Serial        = ""     ;
String  ultimoBT                  = ""     ;
String  inputString_BT            = ""     ;
String  codigoRele1subir          = "r1s"   ;
String  codigoRele2subir          = "r2s"   ;
String  codigoRele3subir          = "r3s"   ;
String  codigoRele1bajar          = "r1b"   ;
String  codigoRele2bajar          = "r2b"   ;
String  codigoRele3bajar          = "r3b"   ;
String  codigoStop                = "st"   ;

boolean BTstring_Complete         = 0      ; 
boolean Serialstring_Complete     = 0      ;
boolean rele1on                   = 0      ;
boolean rele2on                   = 0      ;
boolean rele3on                   = 0      ;

boolean soterrado1abierto         = 0      ;
boolean soterrado2abierto         = 0      ;
boolean soterrado3abierto         = 0      ;

SoftwareSerial BT(9,10); // RX, TX

void setup() {
// Definición de los pins usados para los relés
  pinMode(pinRele1s, OUTPUT);
  pinMode(pinRele2s, OUTPUT);
  pinMode(pinRele3s , OUTPUT);
  pinMode(pinRele1b, OUTPUT);
  pinMode(pinRele2b, OUTPUT);
  pinMode(pinRele3b , OUTPUT);
  
  digitalWrite(pinRele1s, HIGH);
  digitalWrite(pinRele2s,HIGH);
  digitalWrite(pinRele3s , HIGH);
  digitalWrite(pinRele1b , HIGH);
  digitalWrite(pinRele2b, HIGH);
  digitalWrite(pinRele3b , HIGH);
  
  // Comienzo de comunicaciones serie
  Serial.begin(9600);
  BT.begin(9600);
}

void loop() 
{

 BTEvent();
 
 if (BTstring_Complete == 1)
  { 
    Serial.print(inputString_BT);
    BTstring_Complete = 0; 
    RLcode();
    ultimoBT = inputString_BT;
    inputString_BT = ""; 
  }
  
}

void BTEvent()
{ 
  while (BT.available())
  { 
    char inChar = (char)BT.read();
    inputString_BT += inChar;  
    if ( inChar == 10 )
    { 
      BTstring_Complete = 1;
    }
  }
}

void RLcode()
{
    if(inputString_BT == codigoStop + '\n')
    {     
      digitalWrite(pinRele1s, HIGH);
      digitalWrite(pinRele2s, HIGH);
      digitalWrite(pinRele3s, HIGH);
      digitalWrite(pinRele1b, HIGH);
      digitalWrite(pinRele2b, HIGH);
      digitalWrite(pinRele3b, HIGH);
     
    }
    
    if(inputString_BT == codigoRele1subir + '\n')
    {     
     digitalWrite(pinRele1s,LOW);
    
    }
    
     if(inputString_BT == codigoRele2subir + '\n')
    {     
     digitalWrite(pinRele2s, LOW);
   
    }

     if(inputString_BT == codigoRele3subir + '\n')
    {     
     digitalWrite(pinRele3s, LOW);
   
    }

    if(inputString_BT == codigoRele1bajar + '\n')
    {     
     digitalWrite(pinRele1b, LOW); 
   
    }
    
     if(inputString_BT == codigoRele2bajar + '\n')
    {     
     digitalWrite(pinRele2b, LOW);
     
    }

     if(inputString_BT == codigoRele3bajar + '\n')
    {     
     digitalWrite(pinRele3b, LOW);
     
    }
}


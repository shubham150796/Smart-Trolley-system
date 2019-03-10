
#include "MFRC522.h"
#include "SPI.h"
#include <VirtualWire.h>

#define SS_PIN 10


#define RST_PIN 9
#define LED_PIN 6
const int transmit_pin = 3;
const int receive_pin = 0;

MFRC522 rfid(SS_PIN, RST_PIN);
int count=0;
int count1=0;
int count2=0;
int count3=0;

int sum=0;

MFRC522::MIFARE_Key key;



void setup() {
    Serial.begin(9600);
    SPI.begin();
    rfid.PCD_Init();
    pinMode(LED_PIN, OUTPUT);
    vw_set_tx_pin(transmit_pin);
  vw_set_rx_pin(receive_pin);
  vw_setup(2000);
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  // Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }
Serial.println("done");
  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  strID.toUpperCase();
  Serial.println(strID);
  int n = strID.length(); 
     
    // declaring character array
    char array[n+1]; 
     
    // copying the contents of the 
    // string to char array
    strcpy(array, strID.c_str()); 
 // char envioXY[]="";
//for(int i=0;i<12;i++){
  //  envioXY[i]=strID[i];
//}
  //sprintf(envioXY,"%d,%d",envioX,envioY); 
  
 // vw_send((uint8_t *)envioXY, strlen(envioXY)); //vw_send(message, length)
  
 vw_send(( uint8_t *)array, 12);
 vw_wait_tx(); 
 Serial.println("done");

  Serial.print("Tap card key: ");
  Serial.println(strID);

   if(strID == "53:67:AC:75") //price =40
 {
  count++;
  
  if(count%2 == 0)
  {
    Serial.println("Biscuit removed");
    sum=sum-40;
  Serial.print("Total Bill = " );
   Serial.println(sum);
  
        digitalWrite(LED_PIN, HIGH);
    delay(200); 
    digitalWrite(LED_PIN, LOW);
    
  }
  else
  {Serial.println("Biscuit added of rupees 40..");
     sum=sum+40;
  Serial.print("Total Bill = " );
   Serial.println(sum);
      digitalWrite(LED_PIN, HIGH);
    delay(2000); 
    digitalWrite(LED_PIN, LOW);
  }
  }
    else if(strID == "E5:04:D1:65")
{
  count1++;
  
  if(count1%2 == 0)
  {
    Serial.println("Soap removed");
       sum=sum-20;
  Serial.print("Total Bill = " );
   Serial.println(sum);
        digitalWrite(LED_PIN, HIGH);
    delay(200); 
    digitalWrite(LED_PIN, LOW);
    
  }
  else
  {Serial.println("Soap added of rupees 20");
     sum=sum+20;
  Serial.print("Total Bill = " );
   Serial.println(sum);
      digitalWrite(LED_PIN, HIGH);
    delay(2000); 
    digitalWrite(LED_PIN, LOW);
  }
}
      else if(strID == "EE:44:37:62")
{
  count2++;
  
  if(count2%2 == 0)
  {
    Serial.println("Soap removed");
       sum=sum-20;
  Serial.print("Total Bill = " );
   Serial.println(sum);
        digitalWrite(LED_PIN, HIGH);
    delay(200); 
    digitalWrite(LED_PIN, LOW);
    
  }
  else
  {Serial.println("Soap added of rupees 20");
     sum=sum+20;
  Serial.print("Total Bill = " );
   Serial.println(sum);
      digitalWrite(LED_PIN, HIGH);
    delay(2000); 
    digitalWrite(LED_PIN, LOW);
  }
}
    else if(strID == "E3:00:C3:E9")
{
  count3++;
  
  if(count3%2 == 0)
  {
    Serial.println("shampoo removed");
       sum=sum-10;
  Serial.print("Total Bill = " );
   Serial.println(sum);
        digitalWrite(LED_PIN, HIGH);
    delay(200); 
    digitalWrite(LED_PIN, LOW);
    
  }
  else
  {Serial.println("Shampoo added of rupees 10");
     sum=sum+10;
  Serial.print("Total Bill = " );
   Serial.println(sum);
      digitalWrite(LED_PIN, HIGH);
    delay(2000); 
    digitalWrite(LED_PIN, LOW);
  }
}
   


  


  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

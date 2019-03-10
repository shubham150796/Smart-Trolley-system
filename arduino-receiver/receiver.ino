

#include "MFRC522.h"
#include <VirtualWire.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_PIN A0


int count=0;
int count1=0;
int count2=0;
int count3=0;

int sum=0;

MFRC522::MIFARE_Key key;
const int transmit_pin = 3;
const int receive_pin = 0;

void setup() {
  Serial.begin(9600);

   vw_set_tx_pin(transmit_pin);
    vw_set_rx_pin(receive_pin);

     vw_setup(2000);   // Bits per sec

    vw_rx_start(); 

}

void loop() {

   uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

  
if (vw_get_message(buf, &buflen))
{

//   String strID = buf;
//Serial.print(buf);
//String strID(buf);


   //String strID(buf, buf + sizeof(buf));
   char w[12];
for (int i = 0; i < buflen; i++)
  {
      //Serial.print(buf[i]);
      //Serial.print(' ');
      w[i] = static_cast<char>(buf[i]);
  }
  String strID(w);
  
  //Serial.print("Tap card key: ");
  //Serial.print(strID);
  //Serial.print("\n");

   if(strID == "53:67:AC:75") //price =40
 {
  count++;
  
  if(count%2 == 0)
  {
   /* Serial.println("Biscuit removed");
    sum=sum-40;
  Serial.print("Total Bill = " );
   Serial.println(sum);
  
        digitalWrite(LED_PIN, HIGH);
    delay(200); 
    digitalWrite(LED_PIN, LOW); */
    Serial.println("1");
    
  }
  else
  {/*Serial.println("Biscuit added of rupees 40..");
     sum=sum+40;
  Serial.print("Total Bill = " );
   Serial.println(sum);
      digitalWrite(LED_PIN, HIGH);
    delay(2000); 
    digitalWrite(LED_PIN, LOW);*/
    Serial.println("1");
  }
  }
    else if(strID == "E5:04:D1:65")
{
  count1++;
  
  if(count1%2 == 0)
  {
    /*Serial.println("Soap removed");
       sum=sum-20;
  Serial.print("Total Bill = " );
   Serial.println(sum);
        digitalWrite(LED_PIN, HIGH);
    delay(200); 
    digitalWrite(LED_PIN, LOW);*/
    Serial.println("2");
    
  }
  else
  {/*Serial.println("Soap added of rupees 20");
     sum=sum+20;
  Serial.print("Total Bill = " );
   Serial.println(sum);
      digitalWrite(LED_PIN, HIGH);
    delay(2000); 
    digitalWrite(LED_PIN, LOW);*/
     Serial.println("2");
  }
}
      else if(strID == "EE:44:37:62")
{
  count2++;
  
  if(count2%2 == 0)
  { Serial.println("3");
    /*Serial.println("Soap removed");
       sum=sum-20;
  Serial.print("Total Bill = " );
   Serial.println(sum);
        digitalWrite(LED_PIN, HIGH);
    delay(200); 
    digitalWrite(LED_PIN, LOW);*/
    
  }
  else
  {/*Serial.println("Soap added of rupees 20");
     sum=sum+20;
  Serial.print("Total Bill = " );
   Serial.println(sum);
      digitalWrite(LED_PIN, HIGH);
    delay(2000); 
    digitalWrite(LED_PIN, LOW);*/
     Serial.println("3");
  }
}
    else if(strID == "E3:00:C3:E9")
{
  count3++;
  
  if(count3%2 == 0)
  { Serial.println("4");
    /*Serial.println("shampoo removed");
       sum=sum-10;
  Serial.print("Total Bill = " );
   Serial.println(sum);
        digitalWrite(LED_PIN, HIGH);
    delay(200); 
    digitalWrite(LED_PIN, LOW);*/
    
  }
  else
  {/*Serial.println("Shampoo added of rupees 10");
     sum=sum+10;
  Serial.print("Total Bill = " );
   Serial.println(sum);
      digitalWrite(LED_PIN, HIGH);
    delay(2000); 
    digitalWrite(LED_PIN, LOW);*/
    Serial.println("4");
  }
}

}
}

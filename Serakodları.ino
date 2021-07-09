#include "DHT.h"



/*sensör##########*/

#define DHTType DHT22
#define dataPin 8

DHT dht =DHT(dataPin,DHTType);

/*###############*/

/*pinler##########*/

int role1=13;

int buton=3;
int durum=0;

/*################*/



void setup() {
 Serial.begin(9600);
 dht.begin();
 pinMode(role1,OUTPUT);
 pinMode(buton,INPUT);
 


}

void loop() {
if(digitalRead(buton)==1){
  if(durum==0){
    durum=1;
    }

   else{
    durum=0;
    }
  }

  if(durum==1){
    Serial.println("kuluçka dönemi çalışıyor");
    }

   else{
        Serial.println("hasat hazırlık dönemi çalışıyor");

    }
    delay(1000);

 

   



float nem =dht.readHumidity();
float sicak=dht.readTemperature();
Serial.print("Nem : ");
Serial.print(nem,2); //Nem Verisi
Serial.print(",");
Serial.print("Sıcaklık: ");
Serial.print(sicak,2);//Sıcaklık Verisi
Serial.println();
delay(1000);

/*##############*/

/*sistem########*/

sistem(nem);

/*#############*/

}

/*fonksiyonlar ############*/


void sislemekapat(){
  digitalWrite(role1,LOW);


  delay(3000);
  
  digitalWrite(role1,HIGH);
  delay(10000);
  }



void sistem(int nem){

 
 if(nem<70){//şuanda role kapalıyken açık açıkken kapalı çalışıyor yani değilleme mevcut ancak doğru olup olmadığını henüz belirleyemedim.
    
 sislemekapat();
    
    Serial.println("nemlendirme cihazı çalıştırılıyor..");
    
  }

  else if(nem>85){
  
    Serial.println("havalandırma açıldı");

    Serial.println("nemlendirme cihazı çalıştırılmıyor..");
    
    }
    delay(1000);
  }

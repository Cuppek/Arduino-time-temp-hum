#include <DS1302RTC.h>
#include <Time.h>
#include <dht.h>

DS1302RTC RTC(2, 3, 4);
dht DHT;

#define DHT11_PIN 5
#define SIGNAL_PIN A8

int checkMinute;
int value = 0;

void setup() 
{
  Serial.begin(9600);
  setSyncProvider(RTC.get);
  if (timeStatus() == timeSet)
  {
    Serial.println("Ok!");
  } else {
    Serial.println("Fail");
  } 

//  setTime(11, 13, 00, 29, 3, 2021);
  RTC.set(now());

  checkMinute = minute();
  delay(2000);
}

void loop() 
{
  int chk = DHT.read11(DHT11_PIN);
  value = analogRead(SIGNAL_PIN);
  
  Serial.print(hour());
  Serial.print(":");
  if (minute() < 10)
  {
    Serial.print("0");
  }
  Serial.print(minute());
  Serial.print(":");
  if (second() < 10)
  {
    Serial.print("0");
  }
  Serial.print(second());
  Serial.print(" ");
  
  Serial.print(dayShortStr(weekday()));
  Serial.print(" ");
 
  Serial.print(day());
  Serial.print("/");
  Serial.print(month());
  Serial.print("/");
  Serial.print(year());
  Serial.print(" ");


  Serial.print(" Temperatura: ");
  Serial.print(DHT.temperature);
  Serial.print(" st.C ");
  Serial.print(" Wilgotność: ");
  Serial.print(DHT.humidity);
  Serial.print("%");
  
  Serial.print(" Poziom wody: ");
  if (value < 100)
  {
    Serial.print("0");
    if (value < 10)
    {
    Serial.print("0");
    }
  }
  Serial.print(value);

  if (checkMinute != minute())
  {
    Serial.print(" zapis");
    checkMinute = minute();
  }
  
  Serial.print("\n");
  
  delay(1000);
}

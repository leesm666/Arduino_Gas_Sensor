#include <SoftwareSerial.h>
#include "Arduino.h"
// #include "DHT.h"

int BT_RXD = 3;
int BT_TXD = 4;

// #define DHTPIN 2     
#define MQ135_5V_PIN_AOUT  A1
// #define DHTTYPE DHT11   // DHT 11
SoftwareSerial SerialBLE(BT_RXD,BT_TXD);
int airquality = 0;
int freshnessSensor = 0;

String BT_input;
float h =0.0;
// Read temperature as Celsius (the default)
float t =0.0;
// Read temperature as Fahrenheit (isFahrenheit = true)
float f =0.0;
// DHT dht(DHTPIN, DHTTYPE);

String device_id ="Freshness-I-001";


void setup() {
  
// Serial1.begin(115200);
Serial.begin(9600);
SerialBLE.begin(9600);
// dht.begin();

}

void read_data (){
    // h = dht.readHumidity();
    // // Read temperature as Celsius (the default)
    // t = dht.readTemperature();
    // // Read temperature as Fahrenheit (isFahrenheit = true)
    // f = dht.readTemperature(true);
    freshnessSensor = analogRead(MQ135_5V_PIN_AOUT);
    // String JSON = "{\"device_id\":\"" + device_id+ "\",\"humidity_in_rh\":" + String(h)+ ",\"temperature_in_celsius\":" + String(t)+ ",\"ppm_level\":" + String(freshnessSensor) + "}";
    // String JSON = "{\"ppm_level\":" + String(freshnessSensor) + "}";
    String JSON = String(freshnessSensor);
    Serial.println(JSON);

    SerialBLE.println(JSON);
    delay(2000);
}
void loop(){
    read_data();
    if(Serial.available()){
      SerialBLE.write(Serial.read());
    }



}

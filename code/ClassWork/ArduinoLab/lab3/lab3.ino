#include <ESP8266WiFi.h>                 
#include <FirebaseArduino.h>      
#include <DHT.h>              
 
#define FIREBASE_HOST "dht11withnodemcu-7f899-default-rtdb.firebaseio.com"      
#define FIREBASE_AUTH "c7lrcHouW4yBh1nRqgrqbZjfaI97ITJN6962jhOD"            
#define WIFI_SSID "IOT LAB"                                  
#define WIFI_PASSWORD "iotlab@507"            
 
#define DHTPIN D2                                            // Digital pin connected to DHT11
#define DHTTYPE DHT11                                        // Initialize dht type as DHT 11
DHT dht(DHTPIN, DHTTYPE);                                                    
int vi = 0;
void setup() 
{
  Serial.begin(115200);
  dht.begin();                                                  //reads dht sensor data 
               
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
 
  Serial.println();
  Serial.print("Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());                               //prints local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                 // connect to the firebase
  vi=0;
 
}
 
void loop() 
{
  float h = dht.readHumidity();                                 // Read Humidity
  float t = dht.readTemperature();                              // Read temperature
  
  if (isnan(h) || isnan(t))                                     // Checking sensor working
  {                                   
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  } 
  Serial.print("Humidity: ");  
  Serial.print(h);
  String fireHumid = String(h) + String("%");                   //Humidity integer to string conversion
  
  Serial.print("%  Temperature: ");  
  Serial.print(t);  
  Serial.println("°C ");
  String fireTemp = String(t) + String("°C");                  //Temperature integer to string conversion
  delay(5000);
  String hm="",tm="";
  for(int i=0;i<=vi;i++){
    String sthm = Firebase.getString("/DHT11/Humidity/hm"+String(i)); 
    hm = hm+sthm;
    String stTm = Firebase.getString("/DHT11/Temperature/tm"+String(i));
    tm = tm+stTm;
    }
    Serial.println("Read from Firebase: ");
    Serial.print("Humidity = ");
    Serial.println(hm);
    Serial.print("Temperature = ");
    Serial.println(tm);
     
Firebase.setString("/DHT11/Humidity/hm"+String(vi), fireHumid); 
 Firebase.setString("/DHT11/Temperature/tm"+String(vi), fireTemp);
  //Firebase.pushString("/DHT11/Humidity", fireHumid);            //setup path to send Humidity readings
 
  //Firebase.pushString("/DHT11/Temperature", fireTemp);         //setup path to send Temperature readings

 vi++; 
 
    if (Firebase.failed()) 
    {
 
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error()); 
      return;
  }
}

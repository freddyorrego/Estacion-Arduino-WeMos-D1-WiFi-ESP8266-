/*  ultima modificacion 24/abril/2025 */
/*  Librerias */
#include <Arduino.h>
/*wifi*/
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
ESP8266WiFiMulti WiFiMulti;

#include <Wire.h>

/* Sensor DTH22 Temperatura y humedad */
#include "DHT.h"
#define DHTPIN 12
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

/*Sensor BH1750 LUX*/ 
#include <BH1750.h>
BH1750 lightMeter(0x23);

/*Sensor BMP180 presion y temperatura*/
#include <BMP180I2C.h>
#define I2C_ADDRESS 0x77
BMP180I2C bmp180(I2C_ADDRESS);

void setup() {

  Serial.begin(9600);

  /*Inicializamos IC*/
  Wire.begin();

  /* inicializamos sensores */
  dht.begin();/*Temperatura-humedad*/
  /*LUX*/
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE_2)) {
    //Serial.println(F("BH1750 medicion avanzada"));
  }
  else {
    Serial.println(F("fallo en BH1750"));
  }

  for (uint8_t time = 4; time > 0; time--) {
    Serial.printf("[SETUP] En espera %d...\n", time);
    Serial.flush();
    delay(1000);
  }
  /*presion*/
  if (!bmp180.begin())
	{
		Serial.println("begin() fallo en BMP180.");
		while (1);
	}

	bmp180.resetToDefaults();

	bmp180.setSamplingMode(BMP180MI::MODE_UHR);
  /********************/

  WiFi.mode(WIFI_STA);
  // Aca ingresa los datos de tu red wifi 
  WiFiMulti.addAP("nombre de tu red wifi", "contraseña");

  wifi_set_sleep_type(MODEM_SLEEP_T);
  Serial.println("Modo Modem-Sleep activado.");

}

void loop() {
  /*Temperatura-humedad*/
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true); 
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("fallo en DHT!"));
    delay(20000);
    return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  /*LUX*/
  float lux = lightMeter.readLightLevel();
  /*UV*/
  int uv = analogRead(A0);
  // Mapea el valor del sensor de 0 a 1023 a un rango de 0 a 240
  int uv2 = map(uv, 0, 1023, 0, 240);

	delay(2000);
  /*presion*/
	if (!bmp180.measureTemperature())
	{
		Serial.println("could not start temperature measurement, is a measurement already running?");
		return;
	}

	do
	{
		delay(100);
	} while (!bmp180.hasValue());
/*******************/
  if (!bmp180.measurePressure())
	{
		Serial.println("could not start perssure measurement, is a measurement already running?");
		return;
	}
 
	do
	{
		delay(100);
	} while (!bmp180.hasValue());

  Serial.print("Temperature: "); 
	Serial.print(bmp180.getTemperature()); 
	Serial.println(" degC");

	Serial.print("Pressure: "); 
	Serial.print(bmp180.getPressure());
	Serial.println(" Pa");

  // esperando la conexion con wifi
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    /***** si la conexion esta ok creamos la direccion de subida ****/
    WiFiClient client;
    HTTPClient http;
    Serial.print("Iniciando protocolo [HTTP] ...\n");
    Serial.println(WiFi.localIP()); 
    // ingresa del archivo sube la informacion a la base de datos web 
    String url = "http://tudominio.cl/data_upload.php?temp="; 
    url += t;
    url += "&hum=";
    url += h;
    url += "&indc=";
    url += hic;
    url += "&lux=1";
    url += lux;
    url += "&dv=";
    url += uv2;
    url += "&pres=";
    url += bmp180.getPressure();
    url += "&temp2=";
    url += bmp180.getTemperature();
   
    if (http.begin(client, url)) 
      {  // HTTP
        Serial.println("Conexion ok ");
        Serial.println("version : Estacion con subida de datos v5 24/04/2025");
        // inicia conexion y envio HTTP header
        int httpCode = http.GET();

        if (httpCode > 0) {
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
          Serial.println("-----");
        }
        } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
      } else {
      Serial.printf("[HTTP} error al conectar\n");
      }  
  }
 
  delay(900000);/* 15 minutos */ 
}



#ifndef WIFI_INFO_H_
#define WIFI_INFO_H_

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif
#include <LiquidCrystal_I2C.h>

const char *ssid = "telenet-7930146";
const char *password = "jehh6ubcjhnZ";
LiquidCrystal_I2C lcd(0x27, 16, 2);  

void wifi_connect() {

  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.clear();
  
	WiFi.persistent(false);
	WiFi.mode(WIFI_STA);
	WiFi.setAutoReconnect(true);
	WiFi.begin(ssid, password);

    lcd.setCursor(0,0);
    lcd.print("Connecting Wifi");
    delay(4000);
    lcd.clear();
 
	Serial.println("WiFi connecting...");
	while (!WiFi.isConnected()) {
		delay(100);
		Serial.print(".");
    lcd.print("Wifi ERROR-101");
	}
	Serial.print("\n");
	Serial.printf("WiFi connected, IP: %s\n", WiFi.localIP().toString().c_str());
 lcd.print("Wifi Connected"); 
 lcd.setCursor(0,1);
 lcd.print("telenet-7930146");
}

#endif /* WIFI_INFO_H_ */

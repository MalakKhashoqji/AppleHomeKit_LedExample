

#ifndef WIFI_INFO_H_
#define WIFI_INFO_H_

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32) 
#include <WiFi.h>
#endif

char ssid[] = "Wifiname4g";
// the SSID is the Network name ( your Wi-fi name)
char password[] = "123456789";
// This the network password (your Wi-fi Password)
// Add your Wi-fi name and it is password here so the ESP8266 cam connect to it.


void wifi_connect() {
	WiFi.persistent(false);
	WiFi.mode(WIFI_STA);
	WiFi.setAutoReconnect(true);
	WiFi.begin(ssid, password);
	Serial.println("WiFi connecting...");
	while (!WiFi.isConnected()) {
		delay(100);
		Serial.print(".");
	}
	Serial.print("\n");
	Serial.printf("WiFi connected, IP: %s\n", WiFi.localIP().toString().c_str());
}

#endif /* WIFI_INFO_H_ */

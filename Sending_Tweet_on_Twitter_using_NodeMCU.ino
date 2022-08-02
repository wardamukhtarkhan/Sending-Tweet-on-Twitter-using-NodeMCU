#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

String host = "api.thingspeak.com";
int httpPort = 80;
String url = "/apps/thingtweet/1/statuses/update";

HTTPClient http;
WiFiClient client;

void setup()
{
  Serial.begin(115200);
  WiFi.begin("Mooazam", "mooazam123");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  http.begin(client, host, httpPort, url);
  String RequestBody = "api_key=VQR5G9UWYZO2GR7A&status=Shukar Alhumdulillah!";
  int httpCode = http.POST(RequestBody);
  Serial.println(httpCode);
  delay(2000);
}

void loop()
{

}

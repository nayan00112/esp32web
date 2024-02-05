#include <WiFi.h>
#include <WebServer.h>

/* Put your SSID & Password */
const char *ssid = "ESP32";        // Enter SSID here
const char *password = "12345678"; // Enter Password here

/* Put IP Address details */
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80);

void setup()
{
    Serial.begin(115200);

    WiFi.softAP(ssid, password);
    WiFi.softAPConfig(local_ip, gateway, subnet);
    delay(100);

    server.on("/", handle_OnConnect);
    server.onNotFound(handle_NotFound);

    server.begin();
    Serial.println("HTTP server started");
}
void loop()
{
    server.handleClient();
}

void handle_OnConnect()
{
    
    server.send(200, "text/html", SendHTML());
}

void handle_NotFound()
{
    server.send(404, "text/plain", "Not found");
}

String SendHTML()
{
    String ptr = "<!DOCTYPE html>\n";
    ptr += "<html lang=' en '>\n";
    ptr += "<head>\n";
    ptr += "    <meta charset=' UTF - 8 '>\n";
    ptr += "    <meta name=' viewport ' content=' width = device - width, initial - scale = 1.0 '>\n";
    ptr += "    <title>Nayan ESP32 First Server</title>\n";
    ptr += "    <style>\n";
    ptr += "        body{\n";
    ptr += "            color: rgb(227, 224, 255);\n";
    ptr += "            background-color: #0f131f;\n";
    ptr += "            font-family: sans-serif;\n";
    ptr += "            word-spacing: 1px;\n";
    ptr += "        }\n";
    ptr += "    </style>\n";
    ptr += "</head>\n";
    ptr += "<body>\n";
    ptr += "    <div>\n";
    ptr += "        <h1>Hello Nayan!</h1>\n";
    ptr += "        <p>Welcome to ESP32</p>\n";
    ptr += "        <p>Here is the first demo of ESP32 Server (AP).</p>\n";
    ptr += "        <hr>\n";
    ptr += "        <h5>04 Jan, 2024</h5>\n";
    ptr += "    </div>\n";
    ptr += "</body>\n";
    ptr += "</html>\n";
    return ptr;
}
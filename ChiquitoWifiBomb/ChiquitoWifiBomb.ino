#include <ESP8266WiFi.h>

extern "C" {
  #include "user_interface.h"
}

String alfa = "1234567890qwertyuiopasdfghjkklzxcvbnm QWERTYUIOPASDFGHJKLZXCVBNM_";
byte channel;

char *ssids[15] ={"Amatomaa  ","sexuarl   ","fistro    ","negroorl  ","diodenoo  ","Rodrigor  "," quietooor ","papaar    ","condemor  ","Pecador   ","gramenawer","jarlpupita","Pecador  ","sircoo    ","musho     "};

// Beacon Packet buffer
uint8_t packet[128] = { 0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,     0xff, 0xff, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
                        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0xc0, 0x6c,     0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00,
                        0x64, 0x00, 0x01, 0x04, 0x00, 0x14, 0x72, 0x72,     0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 
                        0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x72,     0x72, 0x72, 0x01, 0x08, 0x82, 0x84, 0x8b, 0x96, 
                        0x24, 0x30, 0x48, 0x6c, 0x03, 0x01, 0x04};       

void setup() {
  delay(500);
  Serial.begin(115200);
  wifi_set_opmode(STATION_MODE);
  wifi_promiscuous_enable(1); 
  Serial.println("Setup done");
}

void loop() {
    // random channel //
   
    channel = random(1,12); 
    wifi_set_channel(channel);

    // random mac
    packet[10] = packet[16] = random(256);
    packet[11] = packet[17] = random(256);
    packet[12] = packet[18] = random(256);
    packet[13] = packet[19] = random(256);
    packet[14] = packet[20] = random(256);
    packet[15] = packet[21] = random(256);
  
    // Frases chiquito random
    memcpy( packet + 38, ssids[random(15)], 10 );
    packet[46] = alfa[random(65)];
    packet[47] = alfa[random(65)];
    memcpy( packet + 48, ssids[random(15)], 10 );
    packet[57] = alfa[random(65)];
    /*packet[38] = alfa[random(65)];
    packet[39] = alfa[random(65)];
    packet[40] = alfa[random(65)];
    packet[41] = alfa[random(65)];
    packet[42] = alfa[random(65)];
    packet[43] = alfa[random(65)];
    */
    packet[70] = channel;
    
    wifi_send_pkt_freedom(packet, 71, 0);
    wifi_send_pkt_freedom(packet, 71, 0);
    wifi_send_pkt_freedom(packet, 71, 0);
    delay(1);
}



#include <Arduino.h>
#include "display.hpp"
#include <WiFi.h>
#include <esp_now.h>
#define LED 2
#define question_pin 23

void LED_Flash(int time);
void callback_func(const uint8_t *mac, const uint8_t *incomingData, int len);
uint8_t check_num = 0;
uint8_t send_data = 0;

uint8_t add_data = 1;
void callback_func2(const uint8_t *mac, const uint8_t *incomingData, int len);

void setup() {
  pinMode(question_pin, INPUT);

  Serial.begin(115200);
  initDisplay();
  pinMode(LED, OUTPUT);
  String macAddress = WiFi.macAddress();
  Serial.println("macAddress:"+macAddress);
  WiFi.mode(WIFI_STA);
  WiFi.channel(0);
  if(esp_now_init() == ESP_OK){
    Serial.println("ESPNow Init Success");
  }else{
    Serial.println("ESPNow Init Failed");
    display(70,20,"wrong");
    while(1){
      delay(500);//延时500毫秒
    }
  }
  //
  // tft.setCursor(40,00);//第一个值是横坐标绘制起始点（最大值是160px），第二个值是纵坐标绘制起始点（最大值是128px）
  // tft.print("start......");
  int question_val = digitalRead(question_pin);
  if(question_val == 0){
    esp_now_register_recv_cb(callback_func2);
  }
  if(question_val == 1){
    esp_now_register_recv_cb(callback_func);
  }
}


void loop() {
  
}



//led闪烁
void LED_Flash(int time) {
  digitalWrite(LED, HIGH); 
  delay(time); 
  digitalWrite(LED, LOW);
  delay(time); 
}


void callback_func(const uint8_t *mac, const uint8_t *incomingData, int len) {
  // display_clear();
  char buffer[50];
  snprintf(buffer, sizeof(buffer), "数据长度: %d", len);
  Serial.println(buffer);
  String data = "";
  Serial.print("接收到数据: ");
  for (int i = 0; i < len; i++) {
    Serial.print((char)incomingData[i]);
    data += (char)incomingData[i];
  }
  // tft.setCursor(00,00);
  // tft.print("A1");
  //该字体的大小为12*16
  // display(70,70,data);
  uint8_t num_data = data.toInt();
  if(check_num != num_data){
    LED_Flash(1000);
    // display_clear();
    check_num = num_data;
    switch(add_data){
      case 12:
        tft.setCursor(106,96);
        tft.print("D1");
        tft.setCursor(130,96);
        tft.print(num_data);
      case 11:
        if(add_data>=12){
          break;
        }
        tft.setCursor(53,96);
        tft.print("D2");
        tft.setCursor(77,96);
        tft.print(num_data);
      case 10:
        if(add_data>=11){
          break;
        }
        tft.setCursor(00,96);
        tft.print("D3");
        tft.setCursor(28,96);
        tft.print(num_data);
      case 9:
        if(add_data>=10){
          break;
        }
        tft.setCursor(106,64);
        tft.print("C3");
        tft.setCursor(130,64);
        tft.print(num_data);
      case 8:
        if(add_data>=9){
          break;
        }
        tft.setCursor(53,64);
        tft.print("C2");
        tft.setCursor(77,64);
        tft.print(num_data);
      case 7:
        if(add_data>=8){
          break;
        }
        tft.setCursor(00,64);
        tft.print("C1");
        tft.setCursor(28,64);
        tft.print(num_data);
      case 6:
        if(add_data >= 7){
          break;
        }
        tft.setCursor(106,32);
        tft.print("B1");      
        tft.setCursor(130,32);
        tft.print(num_data);
      case 5:
        if(add_data>=6){
          break;
        }
        tft.setCursor(53,32);
        tft.print("B2");
        tft.setCursor(77,32);
        tft.print(num_data);
      case 4:
        if(add_data>=5){
          break;
        }
        tft.setCursor(00,32);
        tft.print("B3");
        tft.setCursor(28,32);
        tft.print(num_data);
      case 3:
        if(add_data>=4){
          break;
        }
        tft.setCursor(106,00);
        tft.print("A3");
        tft.setCursor(130,00);
        tft.print(num_data);
      case 2:
        if(add_data>=3){
          break;
        }
        tft.setCursor(53,00);
        tft.print("A2");
        tft.setCursor(77,00);
        tft.print(num_data);
      case 1:
        if(add_data>=2){
          break;
        }
        tft.setCursor(00,00);
        tft.print("A1");
        tft.setCursor(28,00);
        tft.print(num_data);
      break;
    }
    add_data = add_data+1;
  }
} 


void callback_func2(const uint8_t *mac, const uint8_t *incomingData, int len) {
  // display_clear();
  char buffer[50];
  snprintf(buffer, sizeof(buffer), "数据长度: %d", len);
  Serial.println(buffer);
  String data = "";
  Serial.print("接收到数据: ");
  for (int i = 0; i < len; i++) {
    Serial.print((char)incomingData[i]);
    data += (char)incomingData[i];
  }
  // tft.setCursor(00,00);
  // tft.print("A1");
  //该字体的大小为12*16
  // display(70,70,data);
  uint8_t num_data = data.toInt();
  if(check_num != num_data){
    LED_Flash(1000);
    // display_clear();
    check_num = num_data;
    switch(add_data){
      case 12:
        tft.setCursor(106,96);
        tft.print("D1");
        tft.setCursor(130,96);
        tft.print(num_data);
      case 11:
        if(add_data>=12){
          break;
        }
        tft.setCursor(53,96);
        tft.print("D2");
        tft.setCursor(77,96);
        tft.print(num_data);
      case 10:
        if(add_data>=11){
          break;
        }
        tft.setCursor(00,96);
        tft.print("D3");
        tft.setCursor(28,96);
        tft.print(num_data);
      case 9:
        if(add_data>=10){
          break;
        }
        tft.setCursor(106,64);
        tft.print("C3");
        tft.setCursor(130,64);
        tft.print(num_data);
      case 8:
        if(add_data>=9){
          break;
        }
        tft.setCursor(53,64);
        tft.print("C2");
        tft.setCursor(77,64);
        tft.print(num_data);
      case 7:
        if(add_data>=8){
          break;
        }
        tft.setCursor(00,64);
        tft.print("C1");
        tft.setCursor(28,64);
        tft.print(num_data);
      case 6:
        if(add_data >= 7){
          break;
        }
        tft.setCursor(106,32);
        tft.print("B1");      
        tft.setCursor(130,32);
        tft.print(num_data);
      case 5:
        if(add_data>=6){
          break;
        }
        tft.setCursor(53,32);
        tft.print("B2");
        tft.setCursor(77,32);
        tft.print(num_data);
      case 4:
        if(add_data>=5){
          break;
        }
        tft.setCursor(00,32);
        tft.print("B3");
        tft.setCursor(28,32);
        tft.print(num_data);
      case 3:
        if(add_data>=4){
          break;
        }
        tft.setCursor(106,00);
        tft.print("A3");
        tft.setCursor(130,00);
        tft.print(num_data);
      case 2:
        if(add_data>=3){
          break;
        }
        tft.setCursor(53,00);
        tft.print("A2");
        tft.setCursor(77,00);
        tft.print(num_data);
      case 1:
        if(add_data>=2){
          break;
        }
        tft.setCursor(00,00);
        tft.print("A1");
        tft.setCursor(28,00);
        tft.print(num_data);
      break;
    }
    add_data = add_data+1;
  }
} 
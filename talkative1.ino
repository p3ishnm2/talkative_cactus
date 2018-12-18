//talkative1
//水やりのお礼を言ってくれる。
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
#include <Metro.h>
SoftwareSerial mySerial(10, 11); // RX, TX

int val = 0;
int l_val = 0;
Metro metro1 = Metro(600000);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin (9600);
  mp3_set_serial (mySerial);  //set softwareSerial for DFPlayer-mini mp3 module 
  mp3_set_volume (25);  // 音量の設定(0～30)
}

void loop() {
  // put your main code here, to run repeatedly:
    val = analogRead(1);
  
  //thirsty metroで一定時間ごとに喋らせる。
  if(metro1.check() == 1){
    if(abs(val) < 400){
      mp3_play (1);
      delay(6000);
    }
    //satisfy
    else{
      mp3_play (4);
      delay(6000);
    }  
  }

  //wasdying
  if(val - l_val >= 200){
    mp3_play (3);
    delay(6000);
  }
  //thanks
  else if(val - l_val >= 100){
    mp3_play (2);
    delay(6000);
  }

  l_val = val;
  Serial.println(val);
  delay(500);
}

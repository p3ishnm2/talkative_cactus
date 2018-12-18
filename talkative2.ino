//talkative2
//タッチセンサの方
//できれば、距離センサも付け足したい
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
SoftwareSerial mySerial(10, 11); // RX, TX

float time;
volatile float t = 1000*60*1000;
volatile float i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin (9600);
  mp3_set_serial (mySerial);  //set softwareSerial for DFPlayer-mini mp3 module 
  mp3_set_volume (15);  // 音量の設定(0～30)
  attachInterrupt(0, blink, RISING);


}

void loop() {
  // put your main code here, to run repeatedly:
  time = millis();
  i = sin(time/t);
  Serial.println(i);
  //Serial.println(touch);
  delay(1000);
}

void blink(){
  if(i < -0.6){
    //拒否
    mp3_play(random(9, 15));
  }else if(i > 0.6){
    //満更でもない
    mp3_play(random(15,21));
  }else{
    //痛がる
    mp3_play(random(5, 9));
  }
}

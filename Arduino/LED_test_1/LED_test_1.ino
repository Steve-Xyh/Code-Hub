//LED呼吸灯

/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

int led = 11;           // the PWM pin the LED is attached to
int brightness = 0;     // how bright the LED is
int fade =5 ;           // how many points to fade the LED by
int breathSpeed=20;
int interval=300;
int MAX=255;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  for(brightness=0;brightness<=MAX;brightness+=fade){
      analogWrite(led,brightness);
      delay(breathSpeed);
  }

  for(brightness=MAX;brightness>=0;brightness-=fade){
      analogWrite(led,brightness);
      delay(breathSpeed);  
  }
  delay(interval);
}

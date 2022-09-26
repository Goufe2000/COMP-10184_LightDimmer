// I Johannes Berbee 000788567 verifiy this is all my work
#include <Arduino.h>

byte LastButtonStatus = HIGH;
byte LEDstatus = HIGH;

void setup()
{
  // put your setup code here, to run once:
  // configure pin D5 as digital input - this is the pushbutton
  pinMode(D5, INPUT_PULLUP);

  pinMode(D4, OUTPUT);

  analogWriteRange(1023);
  // configure the USB serial monitor
  Serial.begin(115200);
}

void loop()
{
  int iVal;
  int iButton;
  iButton = digitalRead(D5);
  digitalWrite(D4, LEDstatus);

  if (iButton != LastButtonStatus)
  {

    LastButtonStatus = iButton;

    if (iButton == LOW)
    {
      LEDstatus = LEDstatus == HIGH ? LOW : HIGH;
      Serial.println(LEDstatus);
      digitalWrite(D4, LEDstatus);
    }
  }

  // put your main code here, to run repeatedly:
  if (LEDstatus == LOW)
  {
    // Adjusts the brightness
    iVal = analogRead(A0);
    // set the PWM pulse width
    analogWrite(D4, iVal);
  }
}
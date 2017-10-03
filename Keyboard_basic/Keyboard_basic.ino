#include <Keyboard.h>

void setup()
{
  // put your setup code here, to run once:
  Keyboard.begin();
  Serial.begin(38400);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  TypeString("Mail");
  delay(1000);
}

void TypeString(String string)
{
  // find the length of the input string
  int length = string.length();

  // print out the string length
  Serial.println("");
  Serial.println("the length is : " + String(length));

  // send in the keystrokes
  for (int i = 0; i < length; i++)
  {
    KeyPress(string[i]);
    Serial.print(string[i]);
  }
}

// simulates a keystroke
void KeyPress(char key)
{
  Keyboard.press(key);
  delayMicroseconds(2);
  Keyboard.release(key);
}

void KeyPressWithModifier(int modifier, int key)
{
  Keyboard.press(modifier);
  Keyboard.press(key);
  delayMicroseconds(2);
  Keyboard.release(key);
  Keyboard.release(modifier);
}

//CODIGO


int rele1= 9;

uint32_t old_millis = 0;
uint32_t interval = 0;
uint8_t stage = 0;

// button variables
int buttonPin = 2;
int ledState = HIGH;        // the current state of the output pin
int buttonState  = LOW;            // the current reading from the input pin
int lastButtonState = LOW;  // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers


void setup()
{
  pinMode(rele1, OUTPUT);
 
}

void loop()
{

  digitalWrite(rele1, LOW);
  delay(5000);
     digitalWrite(rele1, HIGH);
delay(5000);

}

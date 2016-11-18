/**
 * Send a sound on 25kHz to (try) mute dogs
 * 
 * @author Thiago Paes <mrprompt@gmail.com>
 */
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int buzzerPin = 12;  // conectar um buzzer ao pino 12
const int tom = 25000; // frequência para cães

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);

  // initialize the buzzer pin as an output:
  pinMode(buzzerPin, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed, if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);

    // play buzzer
    tone(buzzerPin, tom);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);

    noTone(buzzerPin);
  }
}

/**
 * Send a sound on 25kHz to (try) mute dogs
 * 
 * Need IRremote library - https://github.com/z3t0/Arduino-IRremote
 * 
 * @author Thiago Paes <mrprompt@gmail.com>
 */
#include <IRremote.h>

const int buttonPin = 2; // the number of the pushbutton pin
const int ledPin =  10; // the number of the LED pin
const int irPin = 11; // the number of IR Receiver pin
const int buzzerPin = 12; // the number of de Buzzer pin
const int toneFrequence = 25000; // dog frequence
volatile int buttonState = 0; // pushbutton status

IRrecv irrecv(irPin);

decode_results results;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);

  // initialize the buzzer pin as an output:
  pinMode(buzzerPin, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  // initialize serial
  Serial.begin(9600);

  // start IR receiver
  irrecv.enableIRIn();
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // if receive any value from IR, change buttonState value
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

    buttonState = HIGH;
  }

  // check if the pushbutton is pressed, if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);

    // play buzzer
    tone(buzzerPin, toneFrequence);

    // IR needs a delay to buzzer works
    delay(1500);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);

    noTone(buzzerPin);
  }

  if (irrecv.decode(&results)) {
    // Receive the next value
    irrecv.resume();
  }
}

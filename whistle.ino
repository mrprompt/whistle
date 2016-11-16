/**
 * Send a sound on 25kHz to (try) mute dogs
 * 
 * @author Thiago Paes <mrprompt@gmail.com>
 */
int buzzer = 9;  // conectar um buzzer ao pino 9
unsigned int tom = 25000; // frequência
unsigned long tempo = 500; // tempo

void setup()
{
  Serial.begin(9600);
  Serial.println("Iniciando");
}

void loop()
{
  // play buzzer
  tone(buzzer, tom, tempo);
  delay(tempo);
  noTone(buzzer);

  // send status to serial
  Serial.println(".");
}

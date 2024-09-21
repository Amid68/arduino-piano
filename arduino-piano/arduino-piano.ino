const int NUM_BUTTONS = 4;
const int buttonPins[NUM_BUTTONS] = {7, 6, 5, 4};
const unsigned int frequencies[NUM_BUTTONS] = {523, 659, 784, 880};
const char* noteNames[NUM_BUTTONS] = {"C5", "E5", "G5", "A5"};
const int speakerPin = 2;
const unsigned int toneDuration = 100;

void setup() {
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
  for(int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttonPins[i], INPUT);
  }
}

void loop() {
  bool tonePlayed = false;
  
  for(int i = 0; i < NUM_BUTTONS; i++) {
    if(digitalRead(buttonPins[i]) == HIGH) {
      tone(speakerPin, frequencies[i], toneDuration);
      Serial.print("Button on pin ");
      Serial.print(buttonPins[i]);
      Serial.print(" pressed. Playing note ");
      Serial.println(noteNames[i]);
      tonePlayed = true;
      break;
    }
  }
  
  if(!tonePlayed) {
    noTone(speakerPin);
  }
  
  delay(10);
}

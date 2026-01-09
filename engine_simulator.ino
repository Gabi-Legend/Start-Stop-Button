int start_stop_button = 2;
int start_stop_led = 8;
bool start = false;
bool lastState = HIGH;

void setup() {
  pinMode(start_stop_button, INPUT_PULLUP);
  pinMode(start_stop_led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool currentState = digitalRead(start_stop_button);

  if (lastState == HIGH && currentState == LOW) {  
    start = !start;
    Serial.println(start ? "START" : "STOP");
    digitalWrite(start_stop_led, start);
  }
  lastState = currentState;
  delay(50); 
}
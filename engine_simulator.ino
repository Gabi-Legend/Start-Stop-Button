int start_stop_button = 2;
int start_stop_led = 8;
int increase_speed = 7;  // CLK
int decrease_speed = 6;  // DT
bool start = false;
bool lastState = HIGH;
bool lastClkState = HIGH;
int speed = 0;

void setup() {
  pinMode(start_stop_button, INPUT_PULLUP);
  pinMode(start_stop_led, OUTPUT);
  pinMode(increase_speed, INPUT_PULLUP);
  pinMode(decrease_speed, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Ready!");
}

void loop() {
  // Buton start/stop
  bool currentState = digitalRead(start_stop_button);
  //verifying if we pressed the button
  if (lastState == HIGH && currentState == LOW) {
    start = !start;
    digitalWrite(start_stop_led, start);
    Serial.println(start ? "START" : "STOP");  
  }
  lastState = currentState;
  bool clkState = digitalRead(increase_speed); 
  
  if (lastClkState == HIGH && clkState == LOW) {  //If we used the rotary
    if (start) { 
      //If the car is turned on
      if (digitalRead(decrease_speed) == HIGH) {
        speed += 5;
        Serial.println(speed);
      } else {
        if(speed>=5){
          speed -= 5;
          Serial.println(speed);
        }
        else speed = 0, Serial.println(speed);
      }
    } else {
      Serial.println("Turn the car on first!");
    }
  }
  lastClkState = clkState;
}
// PINS
int start_stop_button = 2;
int start_stop_led = 8;

int clkPin = 7;
int dtPin = 6;

int upshift_button = 3;
int downshift_button = 4;

//  System state
bool start = false;

int gear = 0;
int speed = 0;

// State memory (edge detection)
bool lastStartState = HIGH;
bool lastClkState = HIGH;
bool lastUpshiftState = HIGH;
bool lastDownshiftState = HIGH;

void setup() {
  pinMode(start_stop_button, INPUT_PULLUP);
  pinMode(start_stop_led, OUTPUT);

  pinMode(clkPin, INPUT_PULLUP);
  pinMode(dtPin, INPUT_PULLUP);

  pinMode(upshift_button, INPUT_PULLUP);
  pinMode(downshift_button, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("System ready");
}

void loop() {
  // Start / Stop control
  bool currentStartState = digitalRead(start_stop_button);
  if (lastStartState == HIGH && currentStartState == LOW) {
    start = !start;
    digitalWrite(start_stop_led, start);

    if (!start) {
      gear = 0;
      speed = 0;
    }

    Serial.println(start ? "START" : "STOP");
  }
  lastStartState = currentStartState;

  // Gear shifting logic 
  bool upState = digitalRead(upshift_button);
  bool downState = digitalRead(downshift_button);

  if (lastUpshiftState == HIGH && upState == LOW && start && gear < 5) {
    gear++;
    Serial.print("Gear: ");
    Serial.println(gear);
  }

  if (lastDownshiftState == HIGH && downState == LOW && start && gear > 0) {
    gear--;
    if (gear == 0) speed = 0;
    Serial.print("Gear: ");
    Serial.println(gear);
  }
  lastUpshiftState = upState;
  lastDownshiftState = downState;
  // Speed control via rotary encoder 
  bool clkState = digitalRead(clkPin);
  if (lastClkState == HIGH && clkState == LOW) {
    if (start && gear > 0) {
      if (digitalRead(dtPin) != clkState) {
        if (speed < gear * 25) speed += 5;
      } else {
        if (speed >= 5) speed -= 5;
        else speed = 0;
      }
      Serial.print("Speed: ");
      Serial.println(speed);
    }
  }
  lastClkState = clkState;
}

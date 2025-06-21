const int doorPin1 = 2;
const int doorPin2 = 3;

int lastState1 = HIGH;
int lastState2 = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(doorPin1, INPUT_PULLUP);
  pinMode(doorPin2, INPUT_PULLUP);
}

void loop() {
  int state1 = digitalRead(doorPin1);
  int state2 = digitalRead(doorPin2);

  if (state1 != lastState1) {
    Serial.print("Door 1 ");
    Serial.println(state1 == HIGH ? "OPENED" : "CLOSED");
    lastState1 = state1;
  }

  if (state2 != lastState2) {
    Serial.print("Door 2 ");
    Serial.println(state2 == HIGH ? "OPENED" : "CLOSED");
    lastState2 = state2;
  }

  delay(100); // debounce + reduce noise
}


int leftPin = 12, rightPin = 27, leftDir = 13, rightDir = 14;
float ch1=0, ch2=0, ch3=0, ch4=0, ch5=0, ch6=0;

void setup() {
  Serial.begin(115200);
  ledcSetup(0,5000,8);
  ledcSetup(1,5000,8);
  ledcAttachPin(leftPin,0);
  ledcAttachPin(rightPin,1);
  pinMode(leftDir, OUTPUT);
  pinMode(rightDir, OUTPUT);
}

void loop() {
  ch1 = pulseIn(2, HIGH);
  ch2 = pulseIn(4, HIGH);
  ch3 = pulseIn(5, HIGH);
  ch4 = pulseIn(3, HIGH);
  ch5 = pulseIn(17, HIGH);
  ch6 = pulseIn(16, HIGH);
  Serial.println("CH1: " + String(ch1) + ", CH2: " + String(ch2) + ", CH3: " + String(ch3) + ", CH4: " + String(ch4) + ", CH5: " + String(ch5) + ", CH6: " + String(ch6));

  if(ch3>1550)
  {
    float temp = ((ch3-1550)/450)*200+55;
    ledcWrite(0, temp);
    digitalWrite(leftDir, LOW);
  }
  else if(ch3>1450 & ch3<1550)
  {
    ledcWrite(0, 0);
    digitalWrite(leftDir, LOW);
  }
  else if(ch3<1450)
  {
    float temp = ((ch3-1000)/450)*200+55;
    ledcWrite(0, temp);
    digitalWrite(leftDir, HIGH);
  }

  if(ch2>1550)
  {
    float temp = ((ch2-1550)/450)*200+55;
    ledcWrite(1, temp);
    digitalWrite(rightDir, LOW);
  }
  else if(ch2>1450 & ch2<1550)
  {
    ledcWrite(1, 0);
    digitalWrite(rightDir, LOW);
  }
  else if(ch2<1450)
  {
    float temp = ((ch2-1000)/450)*200+55;
    ledcWrite(1, temp);
    digitalWrite(rightDir, HIGH);
  }
  
}

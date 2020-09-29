int uks = 2;
int kaks = 3;
int kolm = 4;
int neli = 5;
int viis = 6;
int kuus = 7;

int nupp = 12;
int pressed = 0;

int buzzerPin = 9;

void setup() {
  
  for (int i=uks; i<=kuus; i++) {
    pinMode(i, OUTPUT);
  }
  
pinMode(nupp, INPUT);
pinMode(buzzerPin, OUTPUT);
randomSeed(analogRead(A0));
Serial.begin(9600);
  
}

void buildUpTension() {
  
  delay(100);
  for (int i=uks; i<=kuus; i++) {
    if (i!=uks) {
      digitalWrite(i-1, LOW);
    }
    digitalWrite(i, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(75);
    digitalWrite(buzzerPin, LOW);
    delay(75);
  }
  // right to left
  for (int i=kuus; i>=uks; i--) {
    if (i!=kuus) {
      digitalWrite(i+1, LOW);
    }
    digitalWrite(i, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(75);
    digitalWrite(buzzerPin, LOW);
    delay(75);
  } 
}

void showNumber(int number) {
  digitalWrite(uks, HIGH);
  
  if (number >= 2) {
    digitalWrite(kaks, HIGH);
  }
  if (number >= 3) {
    digitalWrite(kolm, HIGH); 
      
  }
  if (number >= 4) {
    digitalWrite(neli, HIGH); 
       
  }
  if (number >= 5) {
    digitalWrite(viis, HIGH); 
      
  }
  if (number == 6) {
    digitalWrite(kuus, HIGH); 
    
  }
  
}

int throwDice() {
  
  int randNumber = random(1,7);
  
  
    Serial.println(randNumber);
  
  
  return randNumber;
}

void setAllLEDs(int value) {
  for (int i=uks; i<=kuus; i++) {
    digitalWrite(i, value);
  }
}

void loop() {
  
  // if button is pressed - throw the dice
  pressed = digitalRead(nupp);
  if (pressed == HIGH) {
    
    setAllLEDs(LOW);
    
    buildUpTension();
    int thrownNumber = throwDice();
    showNumber(thrownNumber);
    digitalWrite(buzzerPin; LOW);
  } 
  
  
}

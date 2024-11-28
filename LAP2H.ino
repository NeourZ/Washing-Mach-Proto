// use 23 22 19 18 05
#define EnA 23
#define Left 22
#define Right 19
#define LED1 18
#define LED2 5
int Rota = 0 ;
void setup() {
  pinMode(EnA, OUTPUT);
  pinMode(Left, OUTPUT);
  pinMode(Right, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);
  digitalWrite(EnA, HIGH);

}

void loop() {
  do {
    Serial.println("Enter WASH = 1 or DRY = 2 to proceed:");
    while (Serial.available() == 0) {
    }
    Rota = Serial.parseInt();
  } while (Rota != 1 && Rota != 2);
  if(Rota == 1){
    Serial.println("WASHING...");
    for(int i = 0 ; i <= 3 ; i++){
      Serial.println("LEFT");
      digitalWrite(LED1, HIGH);
      digitalWrite(Left, HIGH);
      digitalWrite(Right, LOW);
      delay(5000);
      digitalWrite(Left, LOW);
      digitalWrite(Right, LOW);
      digitalWrite(LED1, LOW);
      delay(500);
      Serial.println("RIGHT");
      digitalWrite(LED2, HIGH);
      digitalWrite(Left, LOW);
      digitalWrite(Right, HIGH);
      delay(5000);
      digitalWrite(Left, LOW);
      digitalWrite(Right, LOW);
      digitalWrite(LED2, LOW);
      delay(500);
    }
    Serial.println("Washing completed!!!");
    delay(1000);
  }
  else if(Rota == 2){
    Serial.println("DRYING...");
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(Left, LOW);
    digitalWrite(Right, HIGH);
    delay(10000);
    digitalWrite(Left, LOW);
    digitalWrite(Right, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    Serial.println("Drying completed!!!");
    delay(1000);
  }
  Rota = 0 ;

}

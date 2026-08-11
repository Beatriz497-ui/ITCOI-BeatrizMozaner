// C++ code
//
int botao = 2;
int buzzer = 8;
void setup()
{
  pinMode(botao, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);        
}

void loop()
{
  int estadoBotao = digitalRead(botao);
  Serial.println(estadoBotao);
                 
  if (estadoBotao == LOW) {
    tone (buzzer, 1000);
  }else {
    noTone (buzzer);
  }
                 
  delay(100);
}

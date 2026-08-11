// C++ code
//
int led = 7;
int botao = 2;
  
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
}

void loop()
{
  int valor = digitalRead(botao);
  if (valor == HIGH){
    digitalWrite(led, LOW);
  }else {
    digitalWrite(led, HIGH);
  }
}

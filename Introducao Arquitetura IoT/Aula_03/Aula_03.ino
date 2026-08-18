// C++ code
//
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int leitura = analogRead(A0);
  Serial.println("AC: ");
  Serial.println(leitura);
  Serial.println(" | Tensão: ");
  float tensao = leitura * 5.0 / 1023.0;
  Serial.println(tensao, 2);
  delay(1000);
}

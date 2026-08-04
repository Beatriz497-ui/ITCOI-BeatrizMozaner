// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Sistema Iniciado");
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Led Ligado!");
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Lef Desligado!");
  delay(1000); // Wait for 1000 millisecond(s)
}

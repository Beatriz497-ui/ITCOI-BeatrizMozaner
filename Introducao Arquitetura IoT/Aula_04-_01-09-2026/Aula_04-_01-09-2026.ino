// Variável
const int carroVerde = 12;
const int carroAmarelo = 11;
const int carroVermelho = 10;
const int pedVerde = 9;
const int pedVermelho = 8;

void setup() {
  // Os leds são pinos de saída
  pinMode(carroVerde, OUTPUT);
  pinMode(carroAmarelo, OUTPUT);
  pinMode(carroVermelho, OUTPUT);
  pinMode(pedVerde, OUTPUT);
  pinMode(pedVermelho, OUTPUT);

  // Estado inicial 
  digitalWrite(carroVerde, HIGH);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVermelho, LOW);
  digitalWrite(pedVerde, LOW);
  digitalWrite(pedVermelho, HIGH);
}

void loop() {
  // FASE 1: Carro - Verde e Pedestres Vermelho
  digitalWrite(carroVerde, HIGH);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVermelho, LOW);
  digitalWrite(pedVerde, LOW);
  digitalWrite(pedVermelho, HIGH);
  delay(5000);

  // FASE 2: Atenção - Carro Amarelo e Pedestres Vermelho
  digitalWrite(carroVerde, LOW);
  digitalWrite(carroAmarelo, HIGH);
  digitalWrite(carroVermelho, LOW);
  digitalWrite(pedVerde, LOW);
  digitalWrite(pedVermelho, HIGH);
  delay(3000);

  // FASE 3: Travessia de Pedestres - Carro Vermelho e Pedestre Verde
  digitalWrite(carroVerde, LOW);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVermelho, HIGH);
  digitalWrite(pedVerde, HIGH);
  digitalWrite(pedVermelho, LOW);
  delay(5000);

  // FASE 4: Pisca o vermelho do pedestre 5 vezes
  digitalWrite(pedVerde, LOW);
  
  for (int x = 0; x < 5; x++) {
    digitalWrite(pedVermelho, HIGH);
    delay(250);
    digitalWrite(pedVermelho, LOW);
    delay(250);
  }
}

// Definição dos pinos do LED RGB 
const int pinoRed = 4;     
const int pinoGreen = 6;   
const int pinoBlue = 5;    

// Pino do Potenciômetro
const int pinoPot = A0;

// Variável para armazenar o valor lido do potenciômetro
int valorPot = 0;

void setup() {
  // Configura os pinos do LED como saídas
  pinMode(pinoRed, OUTPUT);
  pinMode(pinoGreen, OUTPUT);
  pinMode(pinoBlue, OUTPUT);
  
  // Inicia a comunicação serial 
  Serial.begin(9600);
}

void loop() {
  // Leitura analógica da posição do potenciômetro (0 a 1023)
  valorPot = analogRead(pinoPot);
  
  // Exibe o valor no Monitor Serial
  Serial.print("Valor do Potenciometro: ");
  Serial.println(valorPot);

  // Seleção de cores dividida em 5 faixas iguais (~204 para cada etapa):
  if (valorPot < 205) {
    // Faixa 1 (0 a 204): Vermelho
    acenderCor(HIGH, LOW, LOW);
  } 
  else if (valorPot < 410) {
    // Faixa 2 (205 a 409): Amarelo (Vermelho + Verde)
    acenderCor(HIGH, HIGH, LOW);
  } 
  else if (valorPot < 615) {
    // Faixa 3 (410 a 614): Verde
    acenderCor(LOW, HIGH, LOW);
  } 
  else if (valorPot < 820) {
    // Faixa 4 (615 a 819): Azul
    acenderCor(LOW, LOW, HIGH);
  } 
  else {
    // Faixa 5 (820 a 1023): Roxo / Magenta (Vermelho + Azul)
    acenderCor(HIGH, LOW, HIGH);
  }

  delay(100); // Pequena pausa para estabilização da leitura
}

// Função auxiliar para definir os estados das cores
void acenderCor(int estadoRed, int estadoGreen, int estadoBlue) {
  digitalWrite(pinoRed, estadoRed);
  digitalWrite(pinoGreen, estadoGreen);
  digitalWrite(pinoBlue, estadoBlue);
}

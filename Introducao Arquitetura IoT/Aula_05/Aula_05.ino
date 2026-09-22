const int pinoR = 7;      // Canal Vermelho ligado ao Pino 7
const int pinoG = 6;      // Canal Verde ligado ao Pino 6
const int pinoB = 5;      // Canal Azul ligado ao Pino 5
const int pinoBotao = 2;  // Botão ligado ao Pino 2

int estadoAtual = 0;      // 0 = Vermelho (Parado), 1 = Verde (Operando), 2 = Azul (Manutenção)
bool estadoBotaoAnterior = HIGH;

void setup() {
  pinMode(pinoR, OUTPUT);
  pinMode(pinoG, OUTPUT);
  pinMode(pinoB, OUTPUT);
  
  // Ativa o resistor interno de pull-up do Arduino
  pinMode(pinoBotao, INPUT_PULLUP);

  atualizarEstadoLED();
}

void loop() {
  bool estadoBotaoAtual = digitalRead(pinoBotao);

  // Detecta o clique do botão (de HIGH para LOW)
  if (estadoBotaoAnterior == HIGH && estadoBotaoAtual == LOW) {
    estadoAtual = (estadoAtual + 1) % 3; 
    atualizarEstadoLED();
    delay(50); 
  }

  estadoBotaoAnterior = estadoBotaoAtual;
}

void atualizarEstadoLED() {
  
  if (estadoAtual == 0) { 
    // Parado (Vermelho)
    digitalWrite(pinoR, HIGH);
    digitalWrite(pinoG, LOW);
    digitalWrite(pinoB, LOW);
  } 
  else if (estadoAtual == 1) { 
    // Operando (Verde)
    digitalWrite(pinoR, LOW);
    digitalWrite(pinoG, HIGH);
    digitalWrite(pinoB, LOW);
  } 
  else if (estadoAtual == 2) { 
    // Manutenção (Azul)
    digitalWrite(pinoR, LOW);
    digitalWrite(pinoG, LOW);
    digitalWrite(pinoB, HIGH);
  }
}

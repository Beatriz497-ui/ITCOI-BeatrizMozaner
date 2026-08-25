// Sensor de Estacionamento
//

const int led1 = 4;

const int led2 = 5;

const int echoPin = 2;

const int trigPin = 3;

const int buzzerPin = 6;

//Distância limite para ativar o alerta 
const int nThreshold = 30;

//Armazenar o tempo de ida e volta
unsigned long nDuration;

//Armazenar a distância calculada em centímetros
float nDistance;


void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  
  //Garante que o TRIG comece desligado
  digitalWrite(trigPin, LOW);
  
  Serial.begin(9600);
  Serial.println("Iniciando detector ultrassonico.....");
}

void loop()
{
  //1. Envio de Pulso Utrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //2. Medicao do Tempo de Retorno
  nDuration = pulseIn(echoPin, HIGH,30000);
  
  //3.Verificação da Leitura
  //nenhum retorno foi identificado
  if (nDuration == 0 )
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    noTone(buzzerPin);
    
    Serial.println("Sem Leitura Válida");
    delay(200);
    
    return;
    
  }
  
  //4. Calculo da Distância
  //converter tempo(microsegundoa) em distância (cm)
  nDistance = nDuration * 0.0343 / 2;
  
  //5.Exibição da Distância
  Serial.println("Distância: ");
  Serial.println(nDistance, 1);
  Serial.println("cm");
  
  //6. Verificar se a Distância menor que 30 cm
  //apitar Buzzer e acender LED vemelho , apagar LED verde
  if  (nDistance < nThreshold)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    tone(buzzerPin, 2000);
    delay(400);
    noTone(buzzerPin);
    digitalWrite(led2, LOW);
    delay(300);
  } 
  
  //7. Distancia for igual ou maior de 30 cm 
  else
  {
    digitalWrite(led2, LOW);
    noTone(buzzerPin);
    digitalWrite(led1, HIGH);
    delay(400);
    digitalWrite(led1, LOW);
    delay(300);
  }
  
 
} 
  
  

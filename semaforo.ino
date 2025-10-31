/*Projeto de aprendizado

programar um semáforo que funcione da seguinte maneira: A lâmpada verde da saída e a vermelha na entrada, ficarão acesas até que o sensor na entrada seja acionado. Quando isso acontecer contar um um tempo de 3 segundo e iniciar o processo de comutação para altear o sentido da via. Passando a entrada para amarelo por 5 segundos e depois vemelho. Passando então a entrada para verde por 15 segundos. Deve haver um tempo de segurança de 2 segundo onde os dois sentido ficam vermelho.*/

/*Declaração de Constantes e Variáveis*/
const int LED = 13; /*Definição o pino para o LED*/
const int Bot = 2;      /*Definido pino para o Botão*/
bool bot_memory = false;
int LastButtonState = LOW;

void setup(){
/* Configuração I/Os*/
  pinMode(LED, OUTPUT);
  pinMode(Bot, INPUT_PULLUP); 
/*Configuração Serial*/
  Serial.begin(9600);
  Serial.println("Iniciando Programa");
  }

void loop(){
 
  if(digitalRead(Bot) != LastButtonState && digitalRead(Bot) == HIGH){
    delay(100);
    if(bot_memory == false){
      Serial.println("Botão Precionado");
      delay(100);
      bot_memory = !bot_memory;
      Serial.println("Ligado");
      
    }
   else if(bot_memory == true){
      Serial.println("Botão Precionado");
      delay(1000);
      bot_memory = !bot_memory;
      Serial.println("Desligado");
      
    } 
  }
  LastButtonState = digitalRead(Bot);
  if(bot_memory == true){
    digitalWrite(LED, HIGH);
    delay(2000);
    digitalWrite(LED, LOW);
    delay(2000);
  }
}

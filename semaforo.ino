/*Projeto de aprendizado

programar um semáforo que funcione da seguinte maneira: A lâmpada verde da saída e a vermelha na entrada, ficarão acesas até que o sensor na entrada seja acionado. Quando isso acontecer contar um um tempo de 3 segundo e iniciar o processo de comutação para altear o sentido da via. Passando a entrada para amarelo por 5 segundos e depois vemelho. Passando então a entrada para verde por 15 segundos. Deve haver um tempo de segurança de 2 segundo onde os dois sentido ficam vermelho.*/

/*Declaração de Constantes e Variáveis Globais*/
const int VME = 7;             /*Definição o pino para lâmpada vermelha da entrada*/
const int AME = 8;             /*Definição o pino para lâmpada amarela da entrada*/
const int VDE = 9;             /*Definição o pino para lâmpada verde da entrada*/
const int VMS = 10;            /*Definição o pino para lâmpada vermelha da saída*/
const int AMS = 11;            /*Definição o pino para lâmpada amarela da saída*/
const int VDS = 12;            /*Definição o pino para lâmpada verde da saída*/
const int Sensor = 2;              /*Definido pino para sensor de barreira na entrada, utiliza resistor de Pull-up interno LOW, Ligado e HIGH desligado*/
bool EstadoSensor = false;
//bool EstadoAnterior = false;
/*Inicialização das variáveis*/
void setup(){
/* Configuração I/Os*/
  pinMode(13, OUTPUT);
  pinMode(VME, OUTPUT);
  pinMode(AME, OUTPUT);
  pinMode(VDE, OUTPUT);
  pinMode(VMS, OUTPUT);
  pinMode(AMS, OUTPUT);
  pinMode(VDS, OUTPUT);
  pinMode(Sensor, INPUT_PULLUP); 
/*Configuração Serial*/
  Serial.begin(115200);
  Serial.println("Iniciando Programa......");
  }

void loop(){
  bool EstadoSensor = digitalRead(Sensor);       /*Armazena estado do sensor*/
  if(EstadoSensor == true){
    delay(3000);            /*Aguardar tempo para mudar sentido*/
    digitalWrite(AMS, HIGH);
    delay(10000);
    digitalWrite(AMS, LOW);
    digitalWrite(VMS, HIGH);
    delay(5000);
    digitalWrite(VME, LOW);
    delay(100);
    digitalWrite(VDE, HIGH);
    delay(15000);
    EstadoSensor = digitalRead(Sensor);
  }
if(EstadoSensor == true){digitalWrite(13, HIGH);}
else{digitalWrite(13, LOW);}
}

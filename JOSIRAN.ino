
// --- Mapeamento de Harware ---

  int in1 = 5;
  int in2 = 6;
  int in3 = 9;
  int in4 = 10;
  int ENA = 3;
  int ENB = 11;
  
//--- Definir porta dos Sensores ---

  int E   = 8;  // Sensor Esquerdo
  int C   = 12; // Sensor Central
  int D   = 4;  // Sensor Direito

// --- setpoint ---

  int setPoint = 200; // condição 1 sempre o sensor central ira ser 1 entao ja sairá
  int   CT  = 70; // Constante anterior 110// melhor contante 60 para pista h
  float V = 0;     // Valor calculado
  int   LD;        // Lado direito
  int   LE;        // Lado esquerdo
  int   CF;        // Centro Frente
  int   y;         // Controle da velocidade do motor esquerda
  int   x;         // Controle da velocidade do motor direito
  int   Erro;
  int   Kp = 2, Ki = 0.00001, Kd = 2; // Kp estabilidade , Ki disturbio e oscilações , Kd respostas rapidas ao disturbio
  int   Va;
  int   T = 0, TA = 0, DT = 0;
  float P, I, DER;
  
// --- Protótipo das Funções Auxiliares ---

  void frente();
  void tras();
  void direita();
  void esquerda();
  void parado();



void setup() 
{
 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(E, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  Serial.begin(9600);
 
}

void loop()
{
   
  TA = T;
  T = millis();
  DT = T - TA;
  
  LD = digitalRead(D);
  LE = digitalRead(E);
  CF = digitalRead(C);
    

  if(LD == 1 || CF == 1 || LE == 1 ){
    
   V = (300*LE + 200*CF + 100*LD) / ( LE + CF + LD); //Calculo do valor lido
   
   }
  
   // Serial.println(V);
    
    Erro = setPoint - V; // Calculo do Erro
    P = Erro * Kp;
    I = Erro * DT * Ki;
    DER = ( Kd * (V - Va)) / DT;
  
  
    x = CT + (P+I+DER);
    y = CT - (P+I+DER); //Calculo da velocidade do motor

    if(x > 255){
      x = 255;
    }
    if(y > 255){
      y = 255;
    }
   if(x < -195){
      x = -195;
    }
    if(y < -195){
      y = -195;
    }
    //Serial.println(x);
    //Serial.println(y);
    
    if (x > 0 && y > 0){
      frente(x,y);
    } else if((x < 0) && (y > 0)){
      esquerda(-x,y); 
    } else if((x > 0) && (y < 0)){
      direita(x,-y);
    }
     Serial.println(V);
   Serial.println(x);
   Serial.println(y);
}

// --- Desenvolvimento das funções auxiliares ---

void frente(int a, int b)
{
  // 0 1 0 1 - Move o robô para frente
   digitalWrite(in1,  LOW);
   digitalWrite(in2, HIGH);
   digitalWrite(in3,  LOW);
   digitalWrite(in4, HIGH);
   analogWrite (ENA, a);
   analogWrite (ENB, b);
   
}

void tras(int a, int b)
{
  // 1 0 1 0 - Move o robô para tras
   digitalWrite(in1, HIGH);
   digitalWrite(in2,  LOW);
   digitalWrite(in3, HIGH);
   digitalWrite(in4,  LOW);
   analogWrite (ENA, a);
   analogWrite (ENB, b);
}

void direita(int a, int b)
{
  // 0 0 1  - Move o robô para direita
   digitalWrite(in1,  LOW);
   digitalWrite(in2, HIGH);
   digitalWrite(in3, HIGH);
   digitalWrite(in4,  LOW);
   analogWrite (ENA, a);
   analogWrite (ENB, b+60);
}

void esquerda(int a, int b)
{
  // 1 0 0 - Move o robô para esquerda
   digitalWrite(in1, HIGH);
   digitalWrite(in2,  LOW);
   digitalWrite(in3,  LOW);
   digitalWrite(in4, HIGH);
   analogWrite (ENA, a+60);
   analogWrite (ENB, b);
}

void parado(int a, int b)
{
  //  0 0 0 - para o robô
   digitalWrite(ENA,  LOW);
   digitalWrite(ENB,  LOW);
   digitalWrite(in1,  LOW);
   digitalWrite(in2,  LOW);
   digitalWrite(in3,  LOW);
   digitalWrite(in4,  LOW);
   
}




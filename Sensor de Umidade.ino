/* -----------------------------------------------------------------------------------------------------------
  SPEI - SOCIEDADE PARANAENSE DE ENSINO E INFORMÃ�TICA
  TRM - TRABALHO MULTI DISCILINAR
  SENSOR DE UMIDADE 1.0 - DESENVOLVIMENTO
  INTEGRANTES: MARLON JHOW YEUNG, LUCAS BORIM, RODRIGO FARIA DE OLIVEIRA E ANTONIO CAGGIANO NETTO
 ------------------------------------------------------------------------------------------------------------
*/

#include <LiquidCrystal.h>
#define contraste 6

LiquidCrystal lcd(7, 1, 5, 4, 3, 2);//INICIALIZA LCD PELOS PINOS DO LCD
const int PORTA_SENSOR = 0;  // DEFINE A POR DE ENTRADA DO SENSOR
int LED_VERMELHO = 8; // LED VERMELHO
int LED_VERDE = 10; // LED VERDE
int LED_AMARELO = 9; // LED AMARELO
long int VALOR_CONVERTIDO; // RESULTADO PROPORÇÃO
int SENSOR_VALOR = 0; //RECEBE O VALOR DO SENSOR
int PORTA_BUZZER = 11; //PORTA SENSOR SONORO



void setup() {
  // initialize serial communications at 9600 bps
  
  //pinMode(contraste, OUTPUT);//CONTRASTE LCD SEMPRE NO MÁXIMO PARA ÃO PRECISA DO POTENCIOMETRO
  //SELECIONA NUMERO DE COLUNAS E LINHAS NO LCD: 
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  
  Serial.begin(9600);
  //lcd.clear();
  // Print a message to the LCD.
  
}

void loop() {
  
  //lcd.print("Ab");
  
  SENSOR_VALOR = analogRead(PORTA_SENSOR);
  
 
  
  // MOSTRA O RESULTADO NO MONITOR SERIAL --------------------------------------------------------------------
  
Serial.print(SENSOR_VALOR);
  Serial.print("\n");
  
//VALOR_CONVERTIDO = (99 * SENSOR_VALOR)/1023; // REALIZAR O CALCULO DE PROPORÇÃO DO SENSOR
  //Serial.print("\t VALOR CONVERTIDO = ");
  //Serial.print(VALOR_CONVERTIDO);
  
  //----------------------------------------------------------------------------------------------------------
  
  // PROCEDIMENTO NO LCD----------------- --------------------------------------------------------------------
  //lcd.clear();
  //lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  //lcd.print(millis()/1000);
  //lcd.setCursor(0,0);
  //lcd.print("VALOR SENSOR: ");
  //lcd.print(VALOR_CONVERTIDO);
  
  
  //----------------------------------------------------------------------------------------------------------
  
   if (SENSOR_VALOR <= 558){ //MUITO ÚMIDO
     analogWrite(LED_AMARELO, 255);
    
   }
   else{
     analogWrite(LED_AMARELO, 0);
   }
   
   if (SENSOR_VALOR > 558 && SENSOR_VALOR < 723){// UMIDADE IDEAL
     analogWrite(LED_VERDE, 255);
    
   }
   else{
     analogWrite(LED_VERDE, 0);
   }
   
   if (SENSOR_VALOR >= 723){// SEM UMIDADE
     analogWrite(LED_VERMELHO, 255);
     tone(PORTA_BUZZER,650,100);
     delay(1000);
    
   }
   else{
     analogWrite(LED_VERMELHO, 0);
   }

    
  delay(500);//TEMPO DE ATUALIZAÇÃO DO SENSOR
  
    
}


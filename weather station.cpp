#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

// Definições do DHT (Temperatura e Umidade)
#define DHTPIN 2       
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

// Inicialização do BMP280 (Pressão e Altitude)
Adafruit_BMP280 bmp;

// Inicialização do display LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Endereço 0x27 para LCD com I2C

// Definições do anemômetro
#define ANEMO_PIN 3 
volatile unsigned int anemoPulsos = 0;
unsigned long ultimaLeituraAnemo = 0;

// Definições do sensor de luminosidade (Incidência solar)
#define LDR_PIN A0 

// Função de interrupção para contar pulsos do anemômetro
void contaPulsos() {
  anemoPulsos++;
}

void setup() {
  Serial.begin(9600);
  dht.begin();

  // Inicializando o sensor BMP280
  if (!bmp.begin(0x76)) { // Endereço I2C padrão do BMP280
    Serial.println("Erro ao inicializar o BMP280!");
    while (1);
  }

  // Inicializando o LCD
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Estacao Meteo");
  delay(2000);

  // Configuração do anemômetro
  pinMode(ANEMO_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ANEMO_PIN), contaPulsos, FALLING);
}

void loop() {
  // Leitura do DHT
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  // Leitura do BMP280
  float pressao = bmp.readPressure() / 100.0F; 
  float altitudine = bmp.readAltitude(101.325); 

  // Leitura do anemômetro (velocidade do vento em m/s)
  unsigned long tempoAtual = millis();
  float velocidadeVento = (anemoPulsos / 2.0) * 2.4; 
  if (tempoAtual - ultimaLeituraAnemo >= 1000) {
    anemoPulsos = 0;
    ultimaLeituraAnemo = tempoAtual;
  }

  // Leitura do sensor de luminosidade (LDR)
  int leituraLDR = analogRead(LDR_PIN);
  float incidenciaSolar = map(leituraLDR, 0, 1023, 0, 100); 

  // Envia os dados para o Serial Monitor
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" *C");
  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.println(" %");
  Serial.print("Pressao: ");
  Serial.print(pressao);
  Serial.println(" kPa");
  Serial.print("Altitude: ");
  Serial.print(altitudine);
  Serial.println(" m");
  Serial.print("Velocidade do vento: ");
  Serial.print(velocidadeVento);
  Serial.println(" m/s");
  Serial.print("Incidencia Solar: ");
  Serial.print(incidenciaSolar);
  Serial.println(" %");

  // Exibe os dados no LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperatura);
  lcd.print("C ");
  lcd.print("Umid:");
  lcd.print(umidade);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Vento:");
  lcd.print(velocidadeVento);
  lcd.print("m/s");

  delay(2000); // Atualiza a cada 2 segundos
}

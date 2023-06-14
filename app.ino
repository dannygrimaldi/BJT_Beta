/* 
Universidad Autónoma Metropolitana Metropolitana Azcapotzalco
Departamento de Electrónica
UEA: Laboratorio de Circuitos Electrónicos I
Proyecto fin de trimestre. Probador de BJT NPN.
Equipo:
Integrantes:
Daniel Alfredo Hernández Grimaldi
 Israel Juárez González 

*/
// Constantes
int voltPin = A3;
float VBE = 0.65;
float VCC = 4.95;
float RC = 989;
float RB = 98700;

// Variables globales
float VC;
float V2;
float V1;
float IC;
float IB;
float B;

void setup() {
  pinMode(13, OUTPUT); // Pin 13 como salida para controlar el LED en Arduino Uno
  Serial.begin(115200); // Inicializa el puerto serie a 115200 bps
}

void loop() {
  
  digitalWrite(13, HIGH); // Enciende el LED en Arduino Uno
  delay(500);
  digitalWrite(13, LOW); // Apaga el LED en Arduino Uno
  delay(500);

  // Adquisición del voltaje
  VC = analogRead(voltPin);
  VC = ((VC * 1023.0) * VCC) / 1000000;
  
  // Cálculo de V2
  V2 = VC - VBE;
  
  // Cálculo de V1
  V1 = VCC - VC;
  
  // Cálculo de IC
  IC = V1 / RC;
  
  // Cálculo de IB
  IB = V2 / RB;
  
  // Cálculo de la beta
  B = IC / IB;
  
  delay(1000);
  
  // Se muestra la beta medida en el monitor serie del IDE
  Serial.print("Beta = ");
  Serial.println(B);

  // Detectar si el transistor está dañado
  detectarTransistorDanado();
}

void detectarTransistorDanado() {
  float betaUmbral = 100.0; // Umbral para detectar un transistor dañado
  
  if (B < betaUmbral) {
    Serial.println("¡Transistor dañado!");
  } else {
    Serial.println("Transistor en buen estado.");
  }
}

// Proyecto: Tostadora de Café con lectura de temperatura y advertencias
// Autor: Julio

#include "max6675.h"

// Pines del MAX6675
int ktcSO  = 12; // SO (DO)
int ktcCS  = 10; // CS
int ktcSCK = 13; // SCK

MAX6675 sensor(ktcSCK, ktcCS, ktcSO);

// Variables para temporizador
unsigned long startTime = 0;     // Guardará el tiempo cuando inicia el tostado
bool timerStarted = false;       // Indica si ya comenzó el cronómetro

void setup() {
  Serial.begin(9600);
  Serial.println("==== TOSTADORA DE CAFE AUTOMATIZADA (Modo Manual) ====");
  Serial.println("Esperando aumento de temperatura (> 50°C)...");
  delay(2000); // pequeña pausa inicial
}

void loop() {
  // Leer la temperatura actual
  float tempC = sensor.readCelsius();

  // Verificar si hay error en la lectura
  if (isnan(tempC)) {
    Serial.println("⚠️ Error al leer el sensor MAX6675. Revisa conexiones.");
    delay(1000);
    return;
  }

  // Mostrar la temperatura actual
  Serial.print("Temperatura actual: ");
  Serial.print(tempC);
  Serial.println(" °C");

  // Si la temperatura pasa de 50°C, iniciar cronómetro (una sola vez)
  if (tempC > 50 && !timerStarted) {
    timerStarted = true;
    startTime = millis(); // guarda el tiempo actual
    Serial.println("🔥 Sistema activo: iniciando temporizador...");
  }

  // Si el cronómetro ya empezó, mostrar el tiempo transcurrido
  if (timerStarted) {
    unsigned long elapsed = millis() - startTime; // tiempo desde que empezó
    int seconds = (elapsed / 1000) % 60;
    int minutes = (elapsed / 60000);
    Serial.print("🕒 Tiempo de tueste: ");
    Serial.print(minutes);
    Serial.print(" min ");
    Serial.print(seconds);
    Serial.println(" s");
  }

  // Mostrar estado según la temperatura
  if (tempC <= 50) {
    Serial.println("Estado: 🔹 Sistema en espera o frío.");
  } 
  else if (tempC > 50 && tempC < 200) {
    Serial.println("Estado: 🌡️ Calentando (todavía no tuesta).");
  } 
  else if (tempC >= 200 && tempC <= 250) {
    Serial.println("Estado: ☕ Zona ideal de tueste.");
  } 
  else if (tempC > 250 && tempC <= 270) {
    Serial.println("Estado: ⚠️ Alta temperatura, ten precaución.");
  } 
  else if (tempC > 270) {
    Serial.println("🚨 ADVERTENCIA: Temperatura demasiado alta!");
    Serial.println("💥 Apagar manualmente la pistola de calor para evitar daños.");
  }

  Serial.println("--------------------------------------");
  delay(1000); // Esperar 1 segundo antes de la siguiente lectura
}

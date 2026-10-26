#include <Arduino.h>

// ATS-GUARD
// Monitoring and Interlocking System
//
// Author: Nunes Arlindo Chirrute
// Location: Cidade de Maputo
//
// Platform: ESP32
// Monitored contactors: K1 and K2
//
// Function:
// Monitor inputs and trigger alerts when certain
// conditions are detected.
//
// IMPORTANT:
// The ESP32 only monitors and signals.
// It does not directly control the contactors.

// ---------------- PIN CONFIGURATION ----------------

// Command buttons
const int BOTAO_ABRIR  = 13;
const int BOTAO_FECHAR = 33;

// Motion sensor
const int SENSOR_PIR = 14;

// Monitoring inputs for contactors
const int SENSOR_K1 = 26;
const int SENSOR_K2 = 25;

// Alarm outputs
const int LED_ALARME = 2;
const int BUZZER     = 4;

// ---------------- SYSTEM STATE ----------------

bool abrirPremido = false;
bool fecharPremido = false;

bool movimentoDetectado = false;

bool k1Activo = false;
bool k2Activo = false;

bool alarmeActivo = false;

// Stores previous alarm state
bool alarmeAnterior = false;

// Controls Serial Monitor update frequency
unsigned long ultimoRelatorio = 0;

const unsigned long INTERVALO_RELATORIO = 2000;

// ---------------- INPUT READING ----------------

void lerEntradas() {

  // Buttons should connect GPIO to GND
  // when pressed.
  abrirPremido = (digitalRead(BOTAO_ABRIR) == LOW);
  fecharPremido = (digitalRead(BOTAO_FECHAR) == LOW);

  // It is assumed that PIR sensor goes HIGH
  // when motion is detected.
  movimentoDetectado = (digitalRead(SENSOR_PIR) == HIGH);

  // WORKING HYPOTHESIS:
  // Isolated interface should present LOW to ESP32
  // when respective contactor is detected as active.
  //
  // This logic must be confirmed when monitoring
  // interface is chosen and tested.
  k1Activo = (digitalRead(SENSOR_K1) == LOW);
  k2Activo = (digitalRead(SENSOR_K2) == LOW);
}

// ---------------- CONDITION CHECK ----------------

void verificarCondicoes() {

  // Alarm starts OFF each cycle.
  alarmeActivo = false;

  // Condition 1:
  // Both buttons are pressed at same time.
  if (abrirPremido && fecharPremido) {
    alarmeActivo = true;
  }

  // Condition 2:
  // Both contactors are detected as active.
  if (k1Activo && k2Activo) {
    alarmeActivo = true;
  }

  // Condition 3:
  // PIR sensor detects motion.
  if (movimentoDetectado) {
    alarmeActivo = true;
  }
}

// ---------------- ALARM UPDATE ----------------

void actualizarAlarme() {

  digitalWrite(LED_ALARME, alarmeActivo ? HIGH : LOW);
  digitalWrite(BUZZER, alarmeActivo ? HIGH : LOW);

  // Show message when alarm state changes.
  if (alarmeActivo != alarmeAnterior) {

    if (alarmeActivo) {
      Serial.println();
      Serial.println("ALERT: Alarm condition detected.");
    } else {
      Serial.println();
      Serial.println("Alarm deactivated.");
    }

    alarmeAnterior = alarmeActivo;
  }
}

// ---------------- SYSTEM REPORT ----------------

void apresentarEstado() {

  Serial.println();
  Serial.println("ATS-GUARD STATE");

  Serial.print("K1 active: ");
  Serial.println(k1Activo ? "YES" : "NO");

  Serial.print("K2 active: ");
  Serial.println(k2Activo ? "YES" : "NO");

  Serial.print("Open button pressed: ");
  Serial.println(abrirPremido ? "YES" : "NO");

  Serial.print("Close button pressed: ");
  Serial.println(fecharPremido ? "YES" : "NO");

  Serial.print("Motion detected: ");
  Serial.println(movimentoDetectado ? "YES" : "NO");

  Serial.print("Alarm active: ");
  Serial.println(alarmeActivo ? "YES" : "NO");

  Serial.println("End of report");
}

// ---------------- INITIAL SETUP ----------------

void setup() {

  Serial.begin(115200);

  // Buttons setup
  pinMode(BOTAO_ABRIR, INPUT_PULLUP);
  pinMode(BOTAO_FECHAR, INPUT_PULLUP);

  // Sensors setup
  pinMode(SENSOR_PIR, INPUT);

  // Monitoring inputs setup
  pinMode(SENSOR_K1, INPUT_PULLUP);
  pinMode(SENSOR_K2, INPUT_PULLUP);

  // Alarm outputs setup
  pinMode(LED_ALARME, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Initial output state
  digitalWrite(LED_ALARME, LOW);
  digitalWrite(BUZZER, LOW);

  Serial.println();
  Serial.println("ATS-GUARD");
  Serial.println("Monitoring and Alarm System");
  Serial.println();
  Serial.println("Program initialization completed.");
  Serial.println("Operation mode: monitoring.");
  Serial.println("ESP32 does not control contactors.");
}

// ---------------- MAIN LOOP ----------------

void loop() {

  // 1. Read input signals.
  lerEntradas();

  // 2. Check alarm conditions.
  verificarCondicoes();

  // 3. Update LED and buzzer.
  actualizarAlarme();

  // 4. Show state periodically.
  unsigned long tempoActual = millis();

  if (tempoActual - ultimoRelatorio >= INTERVALO_RELATORIO) {

    apresentarEstado();

    ultimoRelatorio = tempoActual;
  }

  delay(50);
}
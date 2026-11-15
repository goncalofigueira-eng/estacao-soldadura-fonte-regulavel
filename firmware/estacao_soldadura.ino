/*
  Projeto: Estação de Soldadura Inteligente & Fonte de Alimentação (PAP)
  Autor: Gonçalo Figueira
  Descrição: Controlo de temperatura de ferro de soldar com dois modos de operação:
             - Modo Automático (3 patamares predefinidos)
             - Modo Manual (ajuste livre através dos botões + e -)
             Alimentado por fonte de bancada unificada (220V AC com circuito redutor).
*/

#include <TM1637Display.h> // Biblioteca para o display digital de 4 dígitos

// --- Definição de Pinos ---
const int pinoSensorTemp = A0;   // Entrada analógica para leitura do sensor de temperatura
const int pinoAquecedor  = 3;    // Saída PWM para o MOSFET (IRFZ44N)
const int pinoBuzzer     = 2;    // Buzzer para feedback sonoro

// Pinos dos Botões
const int pinoBotaoModo      = 4; // Alterna entre Modo Automático e Modo Manual
const int pinoBotaoPatamar   = 5; // Muda entre os 3 patamares (no Modo Automático)
const int pinoBotaoMais      = 6; // Sobe a temperatura (no Modo Manual)
const int pinoBotaoMenos     = 7; // Desce a temperatura (no Modo Manual)

// Pinos do Display de 4 Dígitos
const int pinoCLK = 9;
const int pinoDIO = 10;

TM1637Display display(pinoCLK, pinoDIO);

// --- Definição dos 3 Patamares Predefinidos (°C) ---
const int PATAMAR_1 = 150; // Modo Standby / Baixa temperatura
const int PATAMAR_2 = 320; // Soldadura standard
const int PATAMAR_3 = 380; // Alta temperatura / Componentes pesados

// --- Variáveis de Estado e Controlo ---
bool isModoAutomatico    = true; // Começa em Modo Automático por defeito
int patamarAtual         = 1;    // Patamar selecionado (1, 2 ou 3)
int temperaturaDesejada  = PATAMAR_1;
int temperaturaAtual     = 0;
int potenciaPWM          = 0;
unsigned long tempoMostrarAlvo = 0;

void setup() {
  Serial.begin(9600);

  pinMode(pinoAquecedor, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);

  // Botões configurados com pull-up interno
  pinMode(pinoBotaoModo, INPUT_PULLUP);
  pinMode(pinoBotaoPatamar, INPUT_PULLUP);
  pinMode(pinoBotaoMais, INPUT_PULLUP);
  pinMode(pinoBotaoMenos, INPUT_PULLUP);

  display.setBrightness(0x0f);
  tone(pinoBuzzer, 1000, 150); // Bip de arranque
}

void loop() {
  // 1. Verificar se o utilizador quer trocar de modo (Automático <-> Manual)
  if (digitalRead(pinoBotaoModo) == LOW) {
    isModoAutomatico = !isModoAutomatico; // Inverte o modo atual
    registarAlteracao();
  }

  // 2. Executar a função correspondente ao modo ativo
  if (isModoAutomatico == true) {
    modoAutomatico();
  } else {
    modoManual();
  }

  // 3. Ler a temperatura atual da ponta do ferro
  int leituraSensor = analogRead(pinoSensorTemp);
  temperaturaAtual = map(leituraSensor, 0, 1023, 25, 480);

  // 4. Controlar a potência enviada ao MOSFET (IRFZ44N)
  controlarAquecimento();

  // 5. Atualizar o Display de 4 Dígitos
  atualizarDisplay();

  delay(50);
}

// =========================================================================
// FUNÇÃO 1: MODO AUTOMÁTICO (Seleção cíclica entre os 3 patamares)
// =========================================================================
void modoAutomatico() {
  if (digitalRead(pinoBotaoPatamar) == LOW) {
    patamarAtual++;
    if (patamarAtual > 3) {
      patamarAtual = 1; // Volta ao patamar 1 após o 3
    }
    registarAlteracao();
  }

  // Define a temperatura alvo conforme o patamar ativo
  if (patamarAtual == 1) {
    temperaturaDesejada = PATAMAR_1;
  } else if (patamarAtual == 2) {
    temperaturaDesejada = PATAMAR_2;
  } else if (patamarAtual == 3) {
    temperaturaDesejada = PATAMAR_3;
  }
}

// =========================================================================
// FUNÇÃO 2: MODO MANUAL (Ajuste livre através dos botões + e -)
// =========================================================================
void modoManual() {
  if (digitalRead(pinoBotaoMais) == LOW) {
    temperaturaDesejada = constrain(temperaturaDesejada + 5, 100, 450);
    registarAlteracao();
  }

  if (digitalRead(pinoBotaoMenos) == LOW) {
    temperaturaDesejada = constrain(temperaturaDesejada - 5, 100, 450);
    registarAlteracao();
  }
}

// =========================================================================
// FUNÇÕES AUXILIARES DE HARDWARE E INTERFACE
// =========================================================================
void controlarAquecimento() {
  if (temperaturaAtual < temperaturaDesejada - 5) {
    potenciaPWM = 220; // Aquecimento rápido
  } else if (temperaturaAtual < temperaturaDesejada) {
    potenciaPWM = 90;  // Aproximação suave para estabilizar
  } else {
    potenciaPWM = 0;   // Desliga aquecimento ao atingir a temperatura alvo
  }
  analogWrite(pinoAquecedor, potenciaPWM);
}

void atualizarDisplay() {
  // Mostra a temperatura alvo durante 1.5 segundos sempre que há uma alteração
  if (millis() - tempoMostrarAlvo < 1500) {
    display.showNumberDec(temperaturaDesejada);
  } else {
    display.showNumberDec(temperaturaAtual);
  }
}

void registarAlteracao() {
  tempoMostrarAlvo = millis();
  tone(pinoBuzzer, 1500, 50); // Bip curto de confirmação
  delay(200);                 // Debounce simples para evitar leituras duplas
}

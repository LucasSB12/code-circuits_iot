
/**
 *---------------------------------------------------------------
 * @file    Sinalizador_Duplo_Para_Saida_De_Garagem.ino
 * @brief   Controle de dois LEDs (verde e vermelho) por meio de dois botões
 * @author  Lucas Boeing
 * @date    30/10/2026
 * @version 1.0.0
 *---------------------------------------------------------------
 * @section HARDWARE - Componentes utilizados
 * - Microcontrolador: Arduino Uno
 *
 * - Entradas:
 *     Botão Push-Button 1 - pino 13
 *     Botão Push-Button 2 - pino 12
 *     Ambos utilizam Pull-Up Interno (INPUT_PULLUP).
 *
 * - Saídas:
 *     LED Vermelho - pino 2
 *     LED Verde - pino 3
 *
 *---------------------------------------------------------------
 * @section DESCRIPTION
 *
 * 1. Configura os pinos dos LEDs como saída e os botões
 *    como entrada com Pull-Up interno (setup).
 *
 * 2. Realiza continuamente a leitura do estado dos dois
 *    botões utilizando digitalRead() (loop).
 *
 * 3. Quando o botão 1 é pressionado:
 *    - Apaga o LED vermelho.
 *    - Acende o LED verde por 2 segundos.
 *    - Apaga o LED verde.
 *
 * 4. Quando o botão 2 é pressionado:
 *    - Acende o LED vermelho.
 *    - Apaga o LED verde.
 *    - Aguarda 2 segundos.
 *    - Apaga o LED vermelho.
 *
 * 5. Quando os dois botões são pressionados simultaneamente:
 *    - Os dois LEDs acendem e apagam alternadamente.
 *    - O processo acontece 5 vezes.
 *    - Cada etapa dura 500 milissegundos.
 *
 *---------------------------------------------------------------
 * @section MAPEAMENTO LÓGICO
 *
 * - Botão pressionado: LOW (0).
 * - Botão solto: HIGH (1).
 * - LED ligado: HIGH (1).
 * - LED desligado: LOW (0).
 *
 *---------------------------------------------------------------
 */

// Definição dos pinos utilizados
#define BTN1 13
#define BTN2 12
#define LEDVERMELHO 2
#define LEDVERDE 3
#define ESTADO 1

// Configuração inicial dos pinos
void setup()
{
  // Configura os LEDs como saídas
  pinMode(LEDVERMELHO, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);

  // Configura os botões como entradas com Pull-Up interno
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
}

// Executa continuamente a leitura dos botões
void loop()
{
  // Lê o estado atual dos dois botões
  int estado_BTN1 = digitalRead(BTN1);
  int estado_BTN2 = digitalRead(BTN2);

  // Verifica se o botão 1 foi pressionado
  if(estado_BTN1 == 0){
    digitalWrite(LEDVERMELHO, LOW); // Desliga o LED vermelho
    digitalWrite(LEDVERDE, HIGH);   // Liga o LED verde

    delay(2000);                    // Aguarda 2 segundos

    digitalWrite(LEDVERDE, LOW);    // Desliga o LED verde
  }

  // Verifica se o botão 2 foi pressionado
  if(estado_BTN2 == 0){
    digitalWrite(LEDVERMELHO, HIGH); // Liga o LED vermelho
    digitalWrite(LEDVERDE, LOW);     // Desliga o LED verde

    delay(2000);                     // Aguarda 2 segundos

    digitalWrite(LEDVERMELHO, LOW);  // Desliga o LED vermelho
  }

  // Repete o processo de piscar os LEDs 5 vezes
  for(int i = 0; i < 5; i++)
  {
    // Verifica se os dois botões estão pressionados
    if(estado_BTN1 == 0 && estado_BTN2 == 0){

      digitalWrite(LEDVERDE, HIGH);      // Liga o LED verde
      digitalWrite(LEDVERMELHO, HIGH);   // Liga o LED vermelho

      delay(500);                        // Aguarda 500 milissegundos

      digitalWrite(LEDVERDE, LOW);       // Desliga o LED verde
      digitalWrite(LEDVERMELHO, LOW);    // Desliga o LED vermelho

      delay(500);                        // Aguarda mais 500 milissegundos
    }
  }
}

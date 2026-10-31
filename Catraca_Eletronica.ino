
/**
 *---------------------------------------------------------------
 * @file    Catraca_Eletronica.ino
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
 * 2. Define o estado inicial dos LEDs:
 *    - LED vermelho ligado.
 *    - LED verde desligado.
 *
 * 3. Realiza continuamente a leitura dos dois botões
 *    utilizando digitalRead() (loop).
 *
 * 4. Quando o botão 1 é pressionado:
 *    - Apaga o LED vermelho.
 *    - Acende o LED verde por 5 segundos.
 *    - Apaga o LED verde.
 *    - Acende novamente o LED vermelho.
 *
 * 5. Quando o botão 2 é pressionado:
 *    - Apaga o LED verde.
 *    - O LED vermelho pisca 9 vezes.
 *    - Cada intervalo dura 500 milissegundos.
 *    - Ao finalizar, o LED vermelho permanece ligado.
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

// Configuração inicial dos pinos
void setup()
{
  // Configura os LEDs como saídas
  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDVERMELHO, OUTPUT);

  // Configura os botões como entradas com Pull-Up interno
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);

  // Define o estado inicial dos LEDs
  digitalWrite(LEDVERMELHO, HIGH); // Liga o LED vermelho
  digitalWrite(LEDVERDE, LOW);     // Desliga o LED verde
}

// Executa continuamente a leitura dos botões
void loop()
{
  // Lê o estado atual dos dois botões
  int estado_btn1 = digitalRead(BTN1);
  int estado_btn2 = digitalRead(BTN2);

  // Verifica se o botão 1 foi pressionado
  if(estado_btn1 == LOW){
    digitalWrite(LEDVERMELHO, LOW); // Desliga o LED vermelho
    digitalWrite(LEDVERDE, HIGH);   // Liga o LED verde

    delay(5000);                    // Aguarda 5 segundos

    digitalWrite(LEDVERDE, LOW);    // Desliga o LED verde
    digitalWrite(LEDVERMELHO, HIGH); // Liga o LED vermelho
  }

  // Verifica se o botão 2 foi pressionado
  if(estado_btn2 == LOW){

    // Repete o processo de piscar o LED vermelho 9 vezes
    for(int i = 0; i < 9; i++){

      digitalWrite(LEDVERDE, LOW);     // Mantém o LED verde desligado
      digitalWrite(LEDVERMELHO, HIGH); // Liga o LED vermelho

      delay(500);                      // Aguarda 500 milissegundos

      digitalWrite(LEDVERMELHO, LOW);  // Desliga o LED vermelho

      delay(500);                      // Aguarda mais 500 milissegundos
    }

    // Liga o LED vermelho ao finalizar as repetições
    digitalWrite(LEDVERMELHO, HIGH);
  }
}

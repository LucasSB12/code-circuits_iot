
/*
---------------------------------------------------------------------------------
    Autores: Lucas Boeing & Samuel Henrique
    Atividade: Semáforo para Carros e Pedestres

    Descrição:
    Desenvolvimento de um sistema de semáforo utilizando Arduino,
    com 6 LEDs no total: 3 para os veículos e 3 para os pedestres.

    Semáforo dos carros:
    LEDVERDE     - Indica que os veículos podem passar.
    LEDAMARELO   - Indica atenção para os veículos.
    LEDVERMELHO  - Indica que os veículos devem parar.

    Semáforo dos pedestres:
    LEDVERDEpedestre    - Indica que os pedestres podem atravessar.
    LEDAMARELOpedestre  - Indica atenção para os pedestres.
    LEDVERMELHOpedestre - Indica que os pedestres devem aguardar.

    Funcionamento:
    O programa executa uma sequência de sinalização por meio dos LEDs,
    controlando o tempo de cada etapa com a função delay().
    Após completar a sequência, o ciclo é reiniciado automaticamente.

---------------------------------------------------------------------------------
*/

// Define os pinos dos LEDs do semáforo dos carros
#define LEDVERDE 8
#define LEDAMARELO 9
#define LEDVERMELHO 10

// Define os pinos dos LEDs do semáforo dos pedestres
#define LEDVERDEpedestre 13
#define LEDAMARELOpedestre 12
#define LEDVERMELHOpedestre 11

// Função de configuração executada uma vez ao iniciar o Arduino
void setup()
{
  // Configura os LEDs dos carros como saídas digitais
  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDAMARELO, OUTPUT);
  pinMode(LEDVERMELHO, OUTPUT);

  // Configura os LEDs dos pedestres como saídas digitais
  pinMode(LEDVERDEpedestre, OUTPUT);
  pinMode(LEDAMARELOpedestre, OUTPUT);
  pinMode(LEDVERMELHOpedestre, OUTPUT);
}

// Função principal: executa continuamente a sequência do semáforo
void loop()
{
  // Etapa 1: carros param e pedestres podem atravessar
  digitalWrite(LEDVERMELHO, HIGH);
  digitalWrite(LEDVERDEpedestre, HIGH);

  // Mantém os LEDs acesos por 5 segundos
  delay(5000);

  // Apaga os LEDs da primeira etapa
  digitalWrite(LEDVERMELHO, LOW);
  digitalWrite(LEDVERDEpedestre, LOW);

  // Pequena pausa antes da próxima etapa
  delay(0001);

  // Etapa 2: acende os LEDs amarelos dos carros e pedestres
  digitalWrite(LEDAMARELO, HIGH);
  digitalWrite(LEDAMARELOpedestre, HIGH);

  // Mantém os LEDs amarelos acesos por 2 segundos
  delay(2000);

  // Apaga os LEDs amarelos
  digitalWrite(LEDAMARELO, LOW);
  digitalWrite(LEDAMARELOpedestre, LOW);

  // Pequena pausa antes da próxima etapa
  delay(0001);

  // Etapa 3: veículos podem passar e pedestres devem aguardar
  digitalWrite(LEDVERDE, HIGH);
  digitalWrite(LEDVERMELHOpedestre, HIGH);

  // Mantém os LEDs acesos por 5 segundos
  delay(5000);

  // Apaga os LEDs da terceira etapa
  digitalWrite(LEDVERDE, LOW);
  digitalWrite(LEDVERMELHOpedestre, LOW);

  // Pequena pausa antes de reiniciar o ciclo
  delay(0001);
}

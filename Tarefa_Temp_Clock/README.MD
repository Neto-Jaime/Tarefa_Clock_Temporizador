# Projeto: Semáforo com LEDs RGB no RP2040 BitDogLab

Este projeto implementa um semáforo utilizando LEDs RGB no microcontrolador RP2040 com a BitDogLab. O semáforo alterna entre três estados (vermelho, amarelo e verde), com a mudança de estado sendo controlada por um temporizador de 3 segundos. O estado atual do semáforo é exibido no terminal com cores ANSI.

## Descrição

- O semáforo é composto por três LEDs:
  - **LED Vermelho**: Indica que o semáforo está no estado "vermelho".
  - **LED Verde**: Indica que o semáforo está no estado "verde".
  - **LED Amarelo**: Indica que o semáforo está no estado "amarelo" (quando os LEDs vermelho e verde estão acesos simultaneamente).

O código utiliza o temporizador interno do RP2040 para alternar entre os estados a cada 3 segundos. Além disso, o terminal exibe o estado atual do semáforo, com cores específicas para cada estado, usando códigos ANSI.

## Hardware

- **RP2040** (Placa Raspberry Pi Pico ou similar)
- **LEDs RGB** conectados aos seguintes pinos:
  - LED Vermelho: GPIO 13
  - LED Verde: GPIO 11
  - LED Azul: GPIO 12 (não utilizado no código)

## Funcionalidade

- O código inicia com o **LED Vermelho** aceso.
- Após 3 segundos, o **LED Amarelo** é aceso, e os **LEDs Vermelho** e **Verde** ficam ligados simultaneamente.
- Após 3 segundos, o **LED Verde** é aceso, e o **LED Vermelho** é desligado.

- O ciclo se repete indefinidamente.

## Cores no Terminal

- **LED Vermelho**: O texto "LED VERMELHO" será exibido em vermelho.
- **LED Verde**: O texto "LED VERDE" será exibido em verde.
- **LED Amarelo**: O texto "LED AMARELO" será exibido em amarelo.

## Como Compilar e Executar

1. **Instalar Dependências**:
   - Certifique-se de que você tem o SDK do Raspberry Pi Pico configurado no seu ambiente de desenvolvimento.

2. **Compilar o Código**:
   - Use a ferramenta `CMake` para compilar o código, ou configure seu ambiente de desenvolvimento para compilar o código diretamente para o RP2040.

3. **Carregar o Código**:
   - Faça o upload do código compilado para a sua placa RP2040.

4. **Executar**:
   - Após carregar o código na placa, o semáforo começará a funcionar, alternando entre os estados e exibindo as informações no terminal a cada segundo.

## Estrutura do Código

- **Função `repeating_timer_callback`**: Função de callback do temporizador que alterna o estado do semáforo a cada 3 segundos.
- **Função `main`**: Função principal que configura os LEDs, inicializa o temporizador e imprime o estado atual do semáforo no terminal.

## Exemplo de Saída no Terminal

Iniciando semáforo. LED VERMELHO ligado. (1 segundos) LED VERMELHO está ligado. (2 segundos) LED VERMELHO está ligado. 
Mudança de estado: LED AMARELO ligado. (3 segundos) LED AMARELO está ligado. (4 segundos) LED AMARELO está ligado. 
Mudança de estado: LED VERDE ligado. (5 segundos) LED VERDE está ligado. (6 segundos) LED VERDE está ligado. 
Mudança de estado: LED VERMELHO ligado. (7 segundos) LED VERMELHO está ligado. ...
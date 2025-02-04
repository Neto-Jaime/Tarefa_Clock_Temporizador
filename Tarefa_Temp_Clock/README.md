# Projeto: Semáforo com LEDs RGB no RP2040

Este projeto implementa um semáforo utilizando três LEDs (vermelho, amarelo e verde) no microcontrolador RP2040 Simulado no WOWKI. O semáforo alterna entre três estados, com mudanças de estado a cada 3 segundos, utilizando um temporizador. A cada mudança de estado, o terminal exibe o estado atual com cores ANSI.

## Descrição

- **LED Vermelho**: Indica que o semáforo está no estado "vermelho".
- **LED Amarelo**: Indica que o semáforo está no estado "amarelo".
- **LED Verde**: Indica que o semáforo está no estado "verde".

O código utiliza o temporizador do RP2040 para alternar entre os estados a cada 3 segundos. O estado atual do semáforo é impresso no terminal com cores específicas para cada estado, usando códigos ANSI.

## Hardware

- **RP2040** (Placa Raspberry Pi Pico ou similar)
- **LEDs RGB** conectados aos seguintes pinos:
  - LED Vermelho: GPIO 13
  - LED Amarelo: GPIO 12
  - LED Verde: GPIO 11

## Funcionalidade

- O código começa com o **LED Vermelho** aceso e os LEDs Amarelo e Verde desligados.
- Após 3 segundos, o **LED Amarelo** é aceso, e os outros LEDs são desligados.
- Após 3 segundos, o **LED Verde** é aceso, e os outros LEDs são desligados.
- Após 3 segundos, o **LED Vermelho** é aceso novamente, e os outros LEDs são desligados.
- O ciclo se repete indefinidamente.

## Cores no Terminal

- **LED Vermelho**: O texto "LED VERMELHO" será exibido em vermelho.
- **LED Amarelo**: O texto "LED AMARELO" será exibido em amarelo.
- **LED Verde**: O texto "LED VERDE" será exibido em verde.

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
Mudança de estado: LIGANDO LED AMARELO, DESLIGANDO LED VERMELHO E LED VERDE. (3 segundos) LED AMARELO está ligado. (4 segundos) LED AMARELO está ligado. 
Mudança de estado: LIGANDO LED VERDE, DESLIGANDO LED VERMELHO E LED AMARELO. (5 segundos) LED VERDE está ligado. (6 segundos) LED VERDE está ligado. 
Mudança de estado: LIGANDO LED VERMELHO, DESLIGANDO LED AMARELO E LED VERDE. (7 segundos) LED VERMELHO está ligado. ...
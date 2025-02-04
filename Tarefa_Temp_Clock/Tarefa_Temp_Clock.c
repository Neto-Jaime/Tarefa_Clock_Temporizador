#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 13    // GPIO do LED Vermelho
#define LED_YELLOW 12 // GPIO do LED Amarelo
#define LED_GREEN 11  // GPIO do LED Verde

// Códigos ANSI para cores no terminal
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m" // Reseta a cor

volatile int state = 0;   // Estado do sistema
volatile int seconds = 0; // Contador de segundos

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    switch (state) {
        case 0: // Liga vermelho, desliga os outros
            printf("\nMudança de estado: LIGANDO " YELLOW "AMARELO" RESET ", DESLIGANDO " RED "VERMELHO" RESET " E " GREEN "VERDE" RESET ".\n");
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 1);
            gpio_put(LED_GREEN, 0);
            state = 1;
            break;
        case 1: // Liga amarelo, desliga os outros
            printf("\nMudança de estado: LIGANDO " GREEN "VERDE" RESET ", DESLIGANDO " RED "VERMELHO" RESET " E " YELLOW "AMARELO" RESET ".\n");
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 1);
            state = 2;
            break;
        case 2: // Liga verde, desliga os outros
            
            printf("\nMudança de estado: LIGANDO " RED "VERMELHO" RESET ", DESLIGANDO " YELLOW "AMARELO" RESET " E " GREEN "VERDE" RESET ".\n");
            gpio_put(LED_RED, 1);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 0);
            state = 0;
            break;
    }
    return true; // Continua o temporizador
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial

    // Configura os pinos dos LEDs como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Inicializa no estado correto (vermelho ligado, os outros desligados)
    gpio_put(LED_RED, 1);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);
    
    printf("Iniciando semáforo. " RED "LED VERMELHO" RESET " ligado.\n");

    // Configura o temporizador para alternar a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (true) {
        seconds++; // Incrementa o contador de segundos
        
        // Imprime o LED que está ligado a cada segundo
        switch (state) {
            case 0:
                printf("(%d segundos) " RED "LED VERMELHO" RESET " está ligado.\n", seconds);
                break;
            case 1:
                printf("(%d segundos) " YELLOW "LED AMARELO" RESET " está ligado.\n", seconds);
                break;
            case 2:
                printf("(%d segundos) " GREEN "LED VERDE" RESET " está ligado.\n", seconds);
                break;
        }

        sleep_ms(1000); // Aguarda 1 segundo antes da próxima impressão
    }
}
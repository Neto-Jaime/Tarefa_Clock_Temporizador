#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 13    // Vermelho
#define LED_GREEN 11  // Verde 
#define LED_BLUE 12   //Azul 

//Códigos ANSI para colocar cores no terminal
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m" 

volatile int state = 0;   // Estado do semáforo
volatile int seconds = 0; // Contador de segundos

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    switch (state) {
        case 0: // Amarelo ligado (vermelho + verde)
            printf("\nMudança de estado: " YELLOW "AMARELO" RESET " ligado.\n");
            gpio_put(LED_RED, 1);
            gpio_put(LED_GREEN, 1);
            state = 1;
            break;
        case 1: 
            // Verde ligado 
            printf("\nMudança de estado: " GREEN "VERDE" RESET " ligado.\n");
            gpio_put(LED_RED, 0);
            gpio_put(LED_GREEN, 1);
            state = 2;
            break;
        case 2: // Vermelho ligado
            printf("\nMudança de estado: " RED "VERMELHO" RESET " ligado.\n");
            gpio_put(LED_RED, 1);
            gpio_put(LED_GREEN, 0);
            state = 0;
            break;
    }
    return true; 
}

int main() {
    stdio_init_all(); // Inicializando a comunicação serial

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    
    // Inicializar no estado correto (vermelho ligado)
    gpio_put(LED_RED, 1);
    gpio_put(LED_GREEN, 0);
    
    printf("Iniciando semáforo. " RED "LED VERMELHO" RESET " ligado.\n");

    // Configura o temporizador para alternar a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);


    while (true) {
        seconds++; 
        
        // Imprimir o LED que está ligado a cada segundo
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

        sleep_ms(1000); 
    }
}

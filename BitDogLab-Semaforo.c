#include <stdio.h>
#include "pico/stdlib.h"   // Biblioteca padrão para GPIO e comunicação serial
#include "hardware/timer.h" // Biblioteca para temporizadores

// Definição dos pinos dos LEDs
#define LED_PIN_RED 13    // Pino do LED vermelho
#define LED_PIN_YELLOW 12 // Pino do LED amarelo
#define LED_PIN_GREEN 11  // Pino do LED verde

#define TIMER_INTERVAL_MS 3000  // Intervalo do temporizador (3 segundos)

volatile int estado_semaforo = 0; // 0: vermelho, 1: amarelo, 2: verde

// Função callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterna os LEDs conforme a sequência correta do semáforo
    switch (estado_semaforo) {
        case 0: // Liga apenas o vermelho
            gpio_put(LED_PIN_RED, 1);
            gpio_put(LED_PIN_YELLOW, 0);
            gpio_put(LED_PIN_GREEN, 0);
            printf("Sinal: VERMELHO\n");
            estado_semaforo = 1;
            break;
        case 1: // Liga apenas o amarelo
            gpio_put(LED_PIN_RED, 0);
            gpio_put(LED_PIN_YELLOW, 1);
            gpio_put(LED_PIN_GREEN, 0);
            printf("Sinal: AMARELO\n");
            estado_semaforo = 2;
            break;
        case 2: // Liga apenas o verde
            gpio_put(LED_PIN_RED, 0);
            gpio_put(LED_PIN_YELLOW, 0);
            gpio_put(LED_PIN_GREEN, 1);
            printf("Sinal: VERDE\n");
            estado_semaforo = 0; // Volta ao estado inicial (vermelho)
            break;
    }
    return true; // Mantém o temporizador ativo
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial

    // Inicializa e configura os LEDs
    gpio_init(LED_PIN_RED);
    gpio_init(LED_PIN_YELLOW);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    // **Removido o LED vermelho ligado no início**
    gpio_put(LED_PIN_RED, 0);
    gpio_put(LED_PIN_YELLOW, 0);
    gpio_put(LED_PIN_GREEN, 0);

    // Configura o temporizador para alternar os LEDs a cada 3s
    struct repeating_timer timer;
    add_repeating_timer_ms(TIMER_INTERVAL_MS, repeating_timer_callback, NULL, &timer);

    // Liga o primeiro LED manualmente para iniciar o ciclo corretamente
    repeating_timer_callback(NULL);

    // Loop principal - imprime status na serial a cada 1 segundo
    while (true) {
        printf("Semáforo funcionando...\n");
        sleep_ms(1000);
    }

    return 0;
}

#include <stdio.h>
#include "pico/stdlib.h"   // Biblioteca padrão para GPIO e comunicação serial
#include "hardware/timer.h" // Biblioteca para temporizadores

// Definição dos pinos do LED RGB
#define LED_PIN_RED 11   // Pino do LED vermelho
#define LED_PIN_YELLOW 12 // Pino do LED amarelo
#define LED_PIN_GREEN 13  // Pino do LED verde

#define TIMER_INTERVAL_MS 3000  // Intervalo do temporizador (3 segundos)

volatile int estado_semaforo = 0; // 0: vermelho, 1: amarelo, 2: verde

// Função callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de mudar de estado
    gpio_put(LED_PIN_RED, 0);
    gpio_put(LED_PIN_YELLOW, 0);
    gpio_put(LED_PIN_GREEN, 0);

    // Alterna os LEDs conforme a sequência do semáforo
    if (estado_semaforo == 0) {
        gpio_put(LED_PIN_YELLOW, 1);  // Liga o LED amarelo
        printf("Sinal: AMARELO\n");
        estado_semaforo = 1;
    } else if (estado_semaforo == 1) {
        gpio_put(LED_PIN_GREEN, 1); // Liga o LED verde
        printf("Sinal: VERDE\n");
        estado_semaforo = 2;
    } else {
        gpio_put(LED_PIN_RED, 1); // Liga o LED vermelho
        printf("Sinal: VERMELHO\n");
        estado_semaforo = 0;
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

    // Garante que o LED vermelho começa ligado
    gpio_put(LED_PIN_RED, 1);
    gpio_put(LED_PIN_YELLOW, 0);
    gpio_put(LED_PIN_GREEN, 0);

    // Configura o temporizador para alternar os LEDs a cada 3s
    struct repeating_timer timer;
    add_repeating_timer_ms(TIMER_INTERVAL_MS, repeating_timer_callback, NULL, &timer);

    // Loop principal - imprime status na serial a cada 1 segundo
    while (true) {
        printf("Semáforo funcionando...\n");
        sleep_ms(1000);
    }

    return 0;
}

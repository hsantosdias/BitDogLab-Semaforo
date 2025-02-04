#include <stdio.h>
#include "pico/stdlib.h"   // Biblioteca padrão para GPIO e comunicação serial
#include "hardware/timer.h" // Biblioteca para temporizadores

#define LED_PIN_RED 13  // Pino do LED vermelho
#define LED_PIN_BLUE 12 // Pino do LED azul
#define LED_PIN_GREEN 11 // Pino do LED verde
#define TIMER_INTERVAL_MS 1000  // Intervalo do temporizador (1 segundo)

volatile int estado_led = 0; // Controla a sequência dos LEDs

// Função callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de mudar de estado
    gpio_put(LED_PIN_RED, 0);
    gpio_put(LED_PIN_BLUE, 0);
    gpio_put(LED_PIN_GREEN, 0);

    // Alterna os LEDs conforme a sequência desejada
    if (estado_led == 0) {
        gpio_put(LED_PIN_RED, 1);  // Liga o LED vermelho
        printf("LED VERMELHO ligado\n");
        estado_led = 1;
    } else if (estado_led == 1) {
        gpio_put(LED_PIN_BLUE, 1); // Liga o LED azul
        printf("LED AZUL ligado\n");
        estado_led = 2;
    } else {
        gpio_put(LED_PIN_GREEN, 1); // Liga o LED verde
        printf("LED VERDE ligado\n");
        estado_led = 0; // Volta ao primeiro estado
    }
    
    return true; // Mantém o temporizador ativo
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial

    // Inicializa e configura os LEDs
    gpio_init(LED_PIN_RED);
    gpio_init(LED_PIN_BLUE);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    // Garante que o LED vermelho começa ligado
    gpio_put(LED_PIN_RED, 1);
    gpio_put(LED_PIN_BLUE, 0);
    gpio_put(LED_PIN_GREEN, 0);

    // Configura o temporizador para chamar a função callback a cada 1s
    struct repeating_timer timer;
    add_repeating_timer_ms(TIMER_INTERVAL_MS, repeating_timer_callback, NULL, &timer);

    // Loop principal para manter o programa rodando
    while (true) {
        sleep_ms(1000);
    }

    return 0;
}

#include <stdio.h>
#include "pico/stdlib.h"   // Biblioteca padrão para GPIO e comunicação serial
#include "hardware/timer.h" // Biblioteca para temporizadores

#define LED_PIN_RED 13  // Pino do LED vermelho
#define LED_PIN_BLUE 12 // Pino do LED azul
#define TIMER_INTERVAL_MS 1000  // Intervalo do temporizador (1 segundo)
#define SERIAL_PRINT_INTERVAL 10  // Número de ciclos para imprimir na serial

bool leds_on = false;
int counter = 0;  // Contador para a serial

// Função callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterna o estado dos LEDs
    leds_on = !leds_on;
    gpio_put(LED_PIN_RED, leds_on);
    gpio_put(LED_PIN_BLUE, leds_on);
    
    // Imprime mensagem na serial
    printf("1 segundo passou\n");
    
    return true; // Mantém o temporizador ativo
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial

    // Inicializa e configura os LEDs RED e BLUE
    gpio_init(LED_PIN_RED);
    gpio_init(LED_PIN_BLUE);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);
    gpio_put(LED_PIN_RED, false); // Garante que o LED começa desligado
    gpio_put(LED_PIN_BLUE, false); // Garante que o LED começa desligado

    // Configura o temporizador para chamar a função callback a cada 1s
    struct repeating_timer timer;
    add_repeating_timer_ms(TIMER_INTERVAL_MS, repeating_timer_callback, NULL, &timer);

    // Loop infinito que mantém o programa rodando
    while (true) {
        sleep_ms(1000); // Agora verifica a cada 1s
        counter++;  // Incrementa o contador

        // Apenas imprime a cada SERIAL_PRINT_INTERVAL segundos
        if (counter >= SERIAL_PRINT_INTERVAL) {
            printf("Rotina de repetição\n");
            counter = 0; // Reseta o contador
        }
    }

    return 0;
}

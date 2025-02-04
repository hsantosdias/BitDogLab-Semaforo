#include <stdio.h>
#include "pico/stdlib.h"

const int gpio_pin_r = 13; // LED vermelho
const int gpio_pin_g = 11; // LED 
const int gpio_pin_b = 12; // LED 


int main() {
    stdio_init_all(); // Inicializa comunicação serial (opcional)
    
    gpio_init(gpio_pin_r);
    gpio_set_dir(gpio_pin_r, GPIO_OUT);
    gpio_init(gpio_pin_g);
    gpio_set_dir(gpio_pin_g, GPIO_OUT);
    gpio_init(gpio_pin_b);
    gpio_set_dir(gpio_pin_b, GPIO_OUT);

    while (true) {
        gpio_put(gpio_pin_r, 1); // Liga o LED
        sleep_ms(700);
        gpio_put(gpio_pin_r, 0); // Desliga o LED
        printf("LED Vermelho!\n");
        sleep_ms(500);
                
        gpio_put(gpio_pin_g, 1); // Liga o LED
        sleep_ms(700);
        gpio_put(gpio_pin_g, 0); // Desliga o LED
        printf("LED Verde!\n");
        sleep_ms(500);
        
        gpio_put(gpio_pin_b, 1); // Liga o LED
        sleep_ms(700);
        gpio_put(gpio_pin_b, 0); // Desliga o LED
        printf("LED Azul!\n");
        sleep_ms(500);
        


        printf("LED alternado!\n"); // Mensagem para depuração (opcional)
    }

    return 0;
}

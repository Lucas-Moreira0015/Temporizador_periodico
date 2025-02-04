#include <stdio.h>
#include "pico/stdlib.h"   // Inclui a biblioteca padrão para funcionalidades básicas como GPIO, temporização e comunicação serial.
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.

#define LED_PIN_GREEN 11      // define a constante do pino 11, referente ao led verde
#define LED_PIN_BLUE 12       // define a constante do pino 12, referente ao led azul
#define LED_PIN_RED 13        // define a constante do pino 13, referente ao led vermelho

bool led_GREEN_on = false;    // deixa em estado 0, led verde desligado
bool led_BLUE_on = false;     // deixa em estado 0, led azul desligado
bool led_RED_on = false;      // deixa em estado 0, led vermelho desligado

int estado = 0;              // define a constante estado igual a zero
  
// Fun��o callback ser� chamada repetidamente pelo temporizador
// O tipo bool indica que a fun��o deve retornar verdadeiro ou falso para continuar ou parar o temporizador.
bool repeating_timer_callback(struct repeating_timer *t) {
    // Imprime uma mensagem na saída serial indicando que 3 segundos se passaram.
    printf("3 segundos pr�ximo sinal\n");
    // liga o led vermelho e deixa os leds azul e verde desligados
        // Alterna os LEDs de acordo com o estado atual, cada caso representado um sinal
    switch (estado) {
        // sinal vermelho, leds verde e azul desligados
        case 0:                                   
            gpio_put(LED_PIN_RED, !led_RED_on);        // inverte o estado do led, indo para verdadeiro, ligado
            gpio_put(LED_PIN_BLUE, led_BLUE_on);       // usado o estado do led predefinido, falso, desligado
            gpio_put(LED_PIN_GREEN, led_GREEN_on);     // usado o estado do led predefinido, falso, desligado
            break;
        // sinal amarelo, representado pelo led azul, leds verde e vermelho desligados
        case 1:
            gpio_put(LED_PIN_RED, led_RED_on);         // usado o estado do led predefinido, falso, desligado
            gpio_put(LED_PIN_BLUE, !led_BLUE_on);      // inverte o estado do led, indo para verdadeiro, ligado
            gpio_put(LED_PIN_GREEN, led_GREEN_on);     // usado o estado do led predefinido, falso, desligado
            break;
        // sinal verde, leds vermelho e azul desligados
        case 2:
            gpio_put(LED_PIN_RED, led_RED_on);         // usado o estado do led predefinido, falso, desligado
            gpio_put(LED_PIN_BLUE, led_BLUE_on);       // usado o estado do led predefinido, falso, desligado
            gpio_put(LED_PIN_GREEN, !led_GREEN_on);    // inverte o estado do led, indo para verdadeiro, ligado
            break;
     
    }
    estado++;    // incrementa o estado para passar para o pr�ximo sinal

    // j� que s� tem os estados de 0 a 2, n�o deixamos ele passa de 2, e reeinicia para o primeiro sinal
    if (estado >= 3){
        estado = 0;
    }
    
    // Retorna true para manter o temporizador repetindo. Se retornar false, o temporizador para.
    return true;
}

int main() {
    // Inicializa a comunica��o serial, permitindo o uso de fun��es como printf.
    stdio_init_all();

    // Inicializar o pino GPIO11
    gpio_init(LED_PIN_RED);            // inicial o pino 11
    gpio_set_dir(LED_PIN_RED,GPIO_OUT);    // direciona o pino 11 como sa�da

    gpio_init(LED_PIN_BLUE);             // inicializa o pino 12
    gpio_set_dir(LED_PIN_BLUE,GPIO_OUT);     // direciona o pino 12 como sa�da

    gpio_init(LED_PIN_GREEN);             // inicializa o pino 13
    gpio_set_dir(LED_PIN_GREEN,GPIO_OUT);     // dereciona o pino 13 como sa�da

    // Declara��o de uma estrutura de temporizador de repeti��o.
    // Esta estrutura armazenar� informa��es sobre o temporizador configurado.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a fun��o de callback a cada 3 segundo.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop infinito que mant�n o programa em execu��o.
    while (true) {
        // exibe mensagem a cada 1 segundo.
        sleep_ms(1000);
        
        // caso o sinal esteja vermelho
        if (estado == 1){
            printf("PARE\n");
        }
        // caso o sinal esteja amarelo
        if (estado == 2){
            printf("ATEN��O\n");
        }
        // caso o sinal esteja verde
        if (estado == 0){
            printf("SIGA\n");
        }
    }
    return 0;
}

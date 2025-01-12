#include "pico/stdlib.h"
#ifdef CYW43_WL_GPIO_LED_PIN
#include "pico/cyw43_arch.h"
#endif

const uint led_pin_red = 11; 

//Função responsável por inicializar o pino do led
void init_led_pin(uint pin_value){ 
  gpio_init(pin_value); 
  gpio_set_dir(pin_value, GPIO_OUT);
  stdio_init_all();
}

//Função responsável por expressar a letra S em código morse
void S_letter_morse(){ 
  //Representação de um ponto em código morse
  gpio_put(led_pin_red, true);
  sleep_ms(200);
  gpio_put(led_pin_red, false); 

  //Intervalo para sinalização de um ponto ou traço em morse(GAP)
  sleep_ms(125);

  gpio_put(led_pin_red, true);
  sleep_ms(200);
  gpio_put(led_pin_red, false); 

  sleep_ms(125); 

  gpio_put(led_pin_red, true);
  sleep_ms(200);
  gpio_put(led_pin_red, false); 

}

//Função responsável por expressar a letra O em código morse
void O_letter_morse(){ 
  //Representação de um traço em código morse
  gpio_put(led_pin_red, true);
  sleep_ms(800);
  gpio_put(led_pin_red, false); 

  //Intervalo para indicar outra letra em código morse
  sleep_ms(125);

  gpio_put(led_pin_red, true);
  sleep_ms(800);
  gpio_put(led_pin_red, false); 

  sleep_ms(125);

  gpio_put(led_pin_red, true);
  sleep_ms(800);
  gpio_put(led_pin_red, false);
}

int main() {
  
  init_led_pin(led_pin_red);
  
  gpio_put(led_pin_red, false);

  while (true) {
    
    S_letter_morse(); 

    sleep_ms(250);
    
    O_letter_morse();

    sleep_ms(250);

    S_letter_morse(); 

    sleep_ms(3000);
  }
}
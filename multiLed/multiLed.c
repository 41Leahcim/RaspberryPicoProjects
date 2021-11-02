#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0

int main(){
    unsigned int pins[5] = {28, 27, 26, 22, 21};
    unsigned int i, j;
    for(i = 0;i < sizeof(pins) / sizeof(*pins);i++){
        gpio_init(pins[i]);
        gpio_set_dir(pins[i], OUTPUT);
    }
    j = 0;
    while(1){
        for(i = 0;i < sizeof(pins) / sizeof(*pins);i++){
            gpio_put(pins[i], (j & (1 << i)) >> i);
        }
        sleep_ms(1000);
        j++;
    }
    return 0;
}

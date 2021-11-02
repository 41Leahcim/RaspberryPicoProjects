// import all needed library functions
#include "pico/stdlib.h"
#include "hardware/pio.h"

#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0

int main(){
    // define all needed pins
    unsigned int pins[8] = {2, 3, 4, 5, 28, 27, 26, 22};

    // define the patterns for each number
    unsigned int values[10] = {1 | 2 | 4 | 0x20 | 0x40 | 0x80,
                               1 | 0x20,
                               1 | 2 | 8 | 0x40 | 0x80,
                               1 | 2 | 8 | 0x20 | 0x40,
                               1 | 4 | 8 | 0x20,
                               2 | 4 | 8 | 0x20 | 0x40,
                               2 | 4 | 8 | 0x20 | 0x40 | 0x80,
                               1 | 2 | 0x20,
                               0xff ^ 0x10,
                               0xff ^ 0x80 ^ 0x10};

    // declare the number and iterator
    unsigned int i, number;

    // initialize all pins and set the direction
    for(i = 0;i < 8;i++){
        gpio_init(pins[i]);
        gpio_set_dir(pins[i], OUTPUT);
    }

    while(1){
        // iterate through the numbers
        for(number = 0;number < 10;number++){
            // set all pins to the correct values
            for(i = 0;i < 10;i++){
                if(values[number] & (1 << i)){
                    gpio_put(pins[i], HIGH);
                }else{
                    gpio_put(pins[i], LOW);
                }
            }
            // wait 999 milliseconds, so the user has time to see the number
            sleep_ms(999);
        }
    }
    return 0;
}

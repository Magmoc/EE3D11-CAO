#include "LPC13xx.h"
#include "sLEDje.h"
#include "delay.h"

#define BUTTON1 LPC_GPIO2
#define LED1 LPC_GPIO3

int main (void)
{
	init();
	//blink();
	button();

}

static void button(void){
    int led_status = 0;

    init_button();
    while (1){
        if (but1_pressed() == true){
            delay_ms(25);
            led_status = ~led_status;
            LED1->DATA = (led_status<<0);

            while(but1_pressed() == true){ }
            delay_ms(25);
        }
    }
}

static bool but1_pressed(){
    return ((BUTTON1->DATA & 1<<9) == 0);
}

static void init_button(void){
    BUTTON1->DIR &= ~(1<<9);
}

static void blink(void){
	while(1){
        led_on();
        delay_ms(500);

        led_off();
        delay_ms(500);
	}
}
static void init (void){
    init_delay();
    LED1->DIR |= (1<<0);
}

static void led_off (void){
    LED1->DATA |= (1<<0);
}

static void led_on (void){
    LED1->DATA &= ~(1<<0);
}


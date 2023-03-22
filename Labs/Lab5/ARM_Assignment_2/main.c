#include "LPC13xx.h"
#include "timer.h"

#define TIMER0 LPC_TMR32B0
#define MR0 TIMER0->MR0
#define MR3 TIMER0->MR3

int main (void)
{
    assignment_1();

}

static void assignment_1(void){
	init();
	pin_high();
	timer_start();
    loop();
}

static void loop(void){
    const int freq = 100;
    const float dutycycle = 0.8;
    const float period_T = 1/freq;
    const float period_dT = dutycycle * period_T;

    while(1){
        while(MR0 == false && MR3 == false){ }

        if(MR3 == true){
            pin_high();
            MR3 = 0;
        }
        else{
            if (MR0 == true){
                pin_low();
                MR0 = 0;
            }
            else{ }
        }    }
}

static void init(void){

}

void pin_low(void){
}

void pin_high(void){
}

void timer_start(void){
}

void timer_stop(void){
}

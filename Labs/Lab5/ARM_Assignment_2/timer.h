#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>

static void init(void);
void pin_low(void);
void pin_high(void);
void timer_start(void);
void timer_stop(void);
static void loop(void);
static void assignment_1(void);

#endif // TIMER_H

/******************************************************************************************
  Filename    : wdt.c

  Core        : V850ES/JG3-L

  Mcu         : μPD70F3793

  Author      : Chalandi Amine

  Owner       : Chalandi Amine

  Date        : 28.10.2026

  Description : Watchdog timer driver

******************************************************************************************/

#include <stdint.h>

#define WDTM2 (*(volatile uint8_t*)(0xFFFFF6D0ul))
#define WDTE  (*(volatile uint8_t*)(0xFFFFF6D1ul))
#define RCM   (*(volatile uint8_t*)(0xFFFFF80Cul))

void wdt_disable(void);
void wdt_feed(void);

void wdt_disable(void)
{
    WDTE  = 0xAC;
    RCM   = 1;
    WDTM2 = 0;
}


void wdt_feed(void)
{
    /* feed the WD */
    WDTE = 0xAC;
}
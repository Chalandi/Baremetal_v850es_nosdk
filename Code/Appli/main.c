/******************************************************************************************
  Filename    : main.c

  Core        : V850ES/JG3-L

  Mcu         : μPD70F3793

  Author      : Chalandi Amine

  Owner       : Chalandi Amine

  Date        : 28.10.2026

  Description : Application main function

******************************************************************************************/
#include <stdint.h>
#include "uart.h"
#include "printf.h"

#define TM0CTL0  (*(volatile uint8_t*)0xFFFFF690ul)
#define TM0CMP0  (*(volatile uint16_t*)0xFFFFF694ul)
#define TM0EQIC0 (*(volatile uint8_t*)0xFFFFF150ul)

#define PM3L (*(volatile uint8_t*)(0xFFFFF426ul))
#define P3L  (*(volatile uint8_t*)(0xFFFFF406ul))

volatile uint32_t x;

void timer_isr(void);

void main(void)
{
  /* set P36 as output low (LED ON) */
  PM3L &= (uint8_t)~(1u << 6);
  P3L  &= (uint8_t)~(1u << 6);

  /* configure the TMM0 timer */
  TM0CTL0 = 0;
  TM0CMP0 =19999; //1ms interrupt
  TM0EQIC0 = 7;
  TM0CTL0 = 0x80;

  /* initilize uart */
  uart_init(115200);
  printf("Hello from V850ES!\n");

  for(;;);
}


__attribute__((interrupt)) void timer_isr(void)
{
     if(++x >= 500)
     {
         P3L ^= (1u << 6);
         x = 0;
      }
}

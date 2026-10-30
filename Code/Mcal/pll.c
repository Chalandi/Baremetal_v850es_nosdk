/******************************************************************************************
  Filename    : pll.c

  Core        : V850ES/JG3-L

  Mcu         : μPD70F3793

  Author      : Chalandi Amine

  Owner       : Chalandi Amine

  Date        : 28.10.2026

  Description : PLL Driver

******************************************************************************************/

#include <stdint.h>


#define PLLCTL   (*(volatile uint8_t*)0xFFFFF82Cul)
#define PLLLOCKR (*(volatile uint8_t*)0xFFFFF824ul)
#define PCC      (*(volatile uint8_t*)0xFFFFF828ul)
#define PRCMD    (*(volatile uint8_t*)0xFFFFF1FCul)

void pll_init(void);

void pll_init(void)
{
  /* enable the PLL (20MHz) */
  PRCMD  = 0;
  PCC    = 0;
  PLLCTL = 3;
  while(PLLLOCKR);
}
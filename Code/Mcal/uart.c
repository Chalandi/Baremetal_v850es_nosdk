/******************************************************************************************
  Filename    : uart.c

  Core        : V850ES/JG3-L

  Mcu         : μPD70F3793

  Author      : Chalandi Amine

  Owner       : Chalandi Amine

  Date        : 28.10.2026

  Description : UART Driver

******************************************************************************************/

#include "uart.h"


void uart_init(uint32_t baud)
{
  /*
  P31 --> RXDA0
  P30 --> TxDA0
  */

  /* configure UART IO */
  INTF3 &= (uint8_t)~(1u << 1);
  INTR3 &= (uint8_t)~(1u << 1);
  PFC3L &= (uint8_t)~((1ul << 1) | (1ul << 0));
  PMC3L |= (uint8_t)((1u << 1) | (1u << 0));

  /* set UART prescaler to 8 */
  UA0CTL1 = 3;

  /* set the baud rate */
  UA0CTL2 = (uint8_t)(((CPU_FREQ) + (uint32_t)(baud * (1ul << UA0CTL1))) / (uint32_t)(2ul * baud * (1ul << UA0CTL1)));

  /* enabled UART Tx and Rx */
  UA0CTL0 = 0x12;
  UA0CTL0 |= (1u << 7);
  UA0CTL0 |= ((1u << 6) | (1u << 5));

}

void uart_send(const char* msg)
{
  for(uint32_t i=0; msg[i]!=0; i++)
  {
      uart_put((uint8_t)msg[i]);
  }
}

void uart_put(uint8_t c)
{
  UA0TX = c;
  while(UA0STR & 0x80);
}

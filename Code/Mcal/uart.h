/******************************************************************************************
  Filename    : uart.h

  Core        : V850ES/JG3-L

  Mcu         : μPD70F3793

  Author      : Chalandi Amine

  Owner       : Chalandi Amine

  Date        : 28.10.2026

  Description : UART Driver header file

******************************************************************************************/

#ifndef _MINI_UART_H_
#define _MINI_UART_H_

#include<stdint.h>

 #define UA0CTL0  (*(volatile uint8_t*)0xFFFFFA00ul)
 #define UA0CTL1  (*(volatile uint8_t*)0xFFFFFA01ul)
 #define UA0CTL2  (*(volatile uint8_t*)0xFFFFFA02ul)
 #define UA0STR   (*(volatile uint8_t*)0xFFFFFA04ul)
 #define UA0RX    (*(volatile uint8_t*)0xFFFFFA06ul)
 #define UA0TX    (*(volatile uint8_t*)0xFFFFFA07ul)

 #define INTF3    (*(volatile uint8_t*)0xFFFFFC06ul)
 #define INTR3    (*(volatile uint8_t*)0xFFFFFC26ul)
 #define PFC3L    (*(volatile uint8_t*)0xFFFFF466ul)
 #define PMC3L    (*(volatile uint8_t*)0xFFFFF446ul)

 #define CPU_FREQ 20000000

void uart_init(uint32_t baud);

void uart_send(const char* msg);

void uart_put(uint8_t c);

#endif /*_MINI_UART_H_*/

#include <stdint.h>
#include "stm32f446xx.h"

void button_init(void);
void uart2_init(void);
void dma1_init(void);


int main(void)
{
	button_init();
	uart2_init();
	dma1_init();

	while(1);

	return 0;

}

void button_init(void)
{
	// Button is connected to PC 13
	GPIO_TypeDef *pGPIOC = GPIOC;
	RCC_TypeDef *pRCC = RCC;
	EXTI_TypeDef *pEXTI = EXTI;
	SYSCFG_TypeDef *pSYSCFG = SYSCFG;

	// Enable the peripheral clock for the GPIOC peripheral
	pRCC->AHB1ENR |= (1 << 2);

	// Keep the GPIO pin in input modes
	pGPIOC->MODER &= ~(0x3 << 26);

	// Enable the interrupt over that GPIO pin
	pEXTI->IMR |= (1 << 13);

	// Enable the peripheral clock for the SYSCFG peripheral
	pRCC->APB2ENR |= (1 << 14);

	// Configuring the SYSCFG control register
	pSYSCFG->EXTICR[3] &= ~(0xf << 4); //clearing
	pSYSCFG->EXTICR[3] |= (0x2 << 4); // setting

	// Configure the edge detection on that GPIO pin
	pEXTI->FTSR |= (1 << 13);

	// Enable the IRQ related to that GPIO pin in NVIC of the processor
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}


void uart2_init(void)
{
	// Enable the peripheral clock for the UART2 peripheral



}


void dma1_init(void)
{

}

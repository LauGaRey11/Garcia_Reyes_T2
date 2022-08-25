/* Laura García Reyes;  Tarea 2: LEDS */

#include <stdio.h>
#include <stdint.h>

#define SIM_5     (*((volatile uint32_t *) 0x40048038)) // CLK
#define PCR_PTB21 (*((volatile uint32_t *) 0x4004A054)) //pin control para azul
#define PCR_PTB22 (*((volatile uint32_t *) 0x4004A058)) //pin control para rojo
#define PCR_PTE26 (*((volatile uint32_t *) 0x4004D068)) //pin control para verde

#define GPIO_B_BASE_ADDR (((volatile uint32_t *) 0x400FF040u))
#define GPIO_E_BASE_ADDR (((volatile uint32_t *) 0x400FF100u))

typedef struct
	{
	uint32_t PDOR;
	uint32_t PSOR;
	uint32_t PCOR;
	uint32_t PTOR;
	uint32_t PDIR;
	uint32_t PDDR;
	}GPIO_t;

#define GPIO_B ((GPIO_t*) GPIO_B_BASE_ADDR)
#define GPIO_E ((GPIO_t*) GPIO_E_BASE_ADDR)

int main(void) {

	SIM_5 = 0x00002400; //activer CLK
	PCR_PTB21 = 0x00000100; //activar led azul
	PCR_PTB22 = 0x00000100; //activar led rojo
	PCR_PTE26 = 0x00000100; //activar led verde

	while(1)
		{
		GPIO_B->PDDR = 0x00400000;
		GPIO_B->PDDR = 0x00000000;

		GPIO_B->PDDR = 0x00200000;
		GPIO_B->PDDR = 0x00000000;

		GPIO_E->PDDR = 0x04000000;
		GPIO_E->PDDR = 0x00000000;

		GPIO_B->PDDR = 0x00600000; GPIO_E->PDDR = 0x04000000;
		GPIO_B->PDDR = 0x00000000; GPIO_E->PDDR = 0x00000000;
	    }
}

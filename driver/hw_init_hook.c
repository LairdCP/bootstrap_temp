#include "arch/at91_pio.h"
#include "gpio.h"

void hw_init_hook(void)
{
#if defined (CONFIG_AT91SAM9X5EK)
	/* Setup WB45NBT custom GPIOs */
	const struct pio_desc gpios[] = {
	/*  {"NAME",        PIN NUMBER,     VALUE, ATTRIBUTES, TYPE },*/
		{"CHIP_PWD_L",	AT91C_PIN_PA(28),	0, PIO_DEFAULT, PIO_OUTPUT},
		{"VBUS_SENSE",	AT91C_PIN_PB(11),	0, PIO_DEFAULT, PIO_INPUT},
		{"VBUS_EN",	    AT91C_PIN_PB(12),	0, PIO_DEFAULT, PIO_OUTPUT},
		{"IRQ",	        AT91C_PIN_PB(18),	0, PIO_PULLUP,  PIO_INPUT},
		{(char *)0,	0, 0, PIO_DEFAULT, PIO_PERIPH_A},
	};
#else
#error CONFIG_USER_HW_INIT needs to be defined for your board.
#endif

	pio_configure(gpios);
}

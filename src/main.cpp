/* MBED RTOS Blinky
 * Flash some simple LEDs using the RTOS
 * Thread version
 */

#include <mbed.h>

DigitalOut   rLED_as(D5,1); /* initialise app shield red led off */
DigitalOut   red(LED1,1); /* initialise red led to 1 = off */
DigitalOut   green(LED2,1); /* initialise green led off */
DigitalOut   blue(LED3,1); /* initialise blue led off */


void flash_red(void)
{
	while(true) {
		red = 0;
		wait(0.3);
                red = 1;
		wait(0.6);
	}
}

void flash_green(void)
{
	wait(0.3);
        while(true) {
		green = 0;
		wait(0.3);
                green = 1;
                wait(0.6);
	}
}

void flash_blue(void)
{
	wait(0.6);
        while(true) {
		blue = 0;
		wait(0.3);
                blue = 1;
		wait(0.6);
	}
}

int main(void)
{
	Thread blink_red, blink_green, blink_blue;
	blink_red.start(flash_red);
        blink_green.start(flash_green);
        blink_blue.start(flash_blue);
	blink_red.join();
}


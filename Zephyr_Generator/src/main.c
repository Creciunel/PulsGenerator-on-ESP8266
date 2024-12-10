/*
 * @description: Generate a wave signal using DAc from a array
 * @author: Creciunel Catalin 
 * @email: creciunelcatalin@gmail.com
 * @file: main.c
 * @date: 12.12.2024
 * 
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>


// init gpio
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(DT_NODELABEL(blinking_led), gpios);

/**
 * @function: main
 * @description: main function
 * @return: 0 on success, -1 on error
 */
int main(void)
{
	if(!device_is_ready(led.port)) {
		return -1;
	}

	int ret;
	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);

	if(ret != 0) {
		return -1;
	}

	while (true)
	{
		ret = gpio_pin_toggle_dt(&led);
		printf("GPIO pin toggle on %s\n", CONFIG_BOARD_TARGET);
		if(ret != 0) {
			return -1;
		}
		k_sleep(K_MSEC(100));
		ret = gpio_pin_toggle_dt(&led);
		printf("GPIO pin toggle on %s\n", CONFIG_BOARD_TARGET);
		if(ret != 0) {
			return -1;
		}
		k_sleep(K_MSEC(200));
	}

	return 0;
}

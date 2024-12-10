/*
 * @description: Generate a wave signal using DAc from a array
 * @author: Creciunel Catalin 
 * @email: creciunelcatalin@gmail.com
 * @file: main.c
 * @date: 12.12.2024
 * 
 * 
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define GPIO_NUMBER 25

#define GPIO_HIGH 1
#define GPIO_LOW 0
// init gpio
static const struct device *gpio_ct_dev = DEVICE_DT_GET(DT_NODELABEL(gpio0));


int main(void)
{
	if(!device_is_ready(gpio_ct_dev)) {
		return -1;
	}

	int ret;
	ret = gpio_pin_configure(gpio_ct_dev, GPIO_NUMBER, GPIO_OUTPUT_ACTIVE);

	if(ret != 0) {
		return -1;
	}

	while (true)
	{
		ret = gpio_pin_set_raw(gpio_ct_dev, GPIO_NUMBER, GPIO_ACTIVE_HIGH);
		printf("GPIO pin %i is %i on %s\n", GPIO_NUMBER, GPIO_ACTIVE_HIGH, CONFIG_BOARD_TARGET);
		if(ret != 0) {
			return -1;
		}
		k_sleep(K_MSEC(1000));
		ret = gpio_pin_set_raw(gpio_ct_dev, GPIO_NUMBER, GPIO_ACTIVE_LOW);
		printf("GPIO pin %i is %i on %s\n", GPIO_NUMBER, GPIO_ACTIVE_LOW, CONFIG_BOARD_TARGET);
		if(ret != 0) {
			return -1;
		}
		k_sleep(K_MSEC(1000));
	}

	return 0;
}

#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main);

static struct gpio_callback button_a_cb_data;
static struct gpio_callback button_b_cb_data;
static struct gpio_callback button_c_cb_data;

static const struct gpio_dt_spec led =
	GPIO_DT_SPEC_GET(DT_NODELABEL(blinking_led), gpios);
static const struct gpio_dt_spec button_a =
	GPIO_DT_SPEC_GET(DT_NODELABEL(button_a), gpios);
static const struct gpio_dt_spec button_b =
	GPIO_DT_SPEC_GET(DT_NODELABEL(button_b), gpios);
static const struct gpio_dt_spec button_c =
	GPIO_DT_SPEC_GET(DT_NODELABEL(button_c), gpios);

volatile int position = 0; // Variable to track position
volatile bool debounce = false; // Debounce flag

void button_a_pressed(const struct device *dev,
					  struct gpio_callback *cb,
					  uint32_t pins)
{
	if (debounce) return; // Ignore if still bouncing
	debounce = true; // Set debounce flag

	position++;
	LOG_INF("Button A pressed! Current position: %d", position);

	// Start a timer for debouncing
	k_sleep(K_MSEC(200)); // Adjust this value as needed (200 ms is common)
	debounce = false; // Clear debounce flag
}

void button_b_pressed(const struct device *dev,
					  struct gpio_callback *cb,
					  uint32_t pins)
{
	if (debounce) return; // Ignore if still bouncing
	debounce = true; // Set debounce flag

	position--;
	LOG_INF("Button B pressed! Current position: %d", position);

	// Start a timer for debouncing
	k_sleep(K_MSEC(200)); // Adjust this value as needed
	debounce = false; // Clear debounce flag
}

void button_c_pressed(const struct device *dev,
					  struct gpio_callback *cb,
					  uint32_t pins)
{
	if (debounce) return; // Ignore if still bouncing
	debounce = true; // Set debounce flag

	LOG_INF("Button C pressed! Position reset.");
	position = 0; // Reset position

	// Start a timer for debouncing
	k_sleep(K_MSEC(200)); // Adjust this value as needed
	debounce = false; // Clear debounce flag
}

int main(void)
{
	if (!device_is_ready(led.port))
	{
		LOG_ERR("LED device not ready");
		return -1;
	}

	if (!device_is_ready(button_a.port))
	{
		LOG_ERR("Button A device not ready");
		return -1;
	}

	if (!device_is_ready(button_b.port))
	{
		LOG_ERR("Button B device not ready");
		return -1;
	}

	if (!device_is_ready(button_c.port))
	{
		LOG_ERR("Button C device not ready");
		return -1;
	}

	int ret;

	// Configure LED
	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret != 0)
	{
		LOG_ERR("Failed to configure LED: %d", ret);
		return -1;
	}

	// Configure Button A
	ret = gpio_pin_configure_dt(&button_a, GPIO_INPUT | GPIO_PULL_UP);
	if (ret != 0)
	{
		LOG_ERR("Failed to configure Button A: %d", ret);
		return -1;
	}

	// Configure Button B
	ret = gpio_pin_configure_dt(&button_b, GPIO_INPUT | GPIO_PULL_UP);
	if (ret != 0)
	{
		LOG_ERR("Failed to configure Button B: %d", ret);
		return -1;
	}

	// Configure Button C
	ret = gpio_pin_configure_dt(&button_c, GPIO_INPUT | GPIO_PULL_UP);
	if (ret != 0)
	{
		LOG_ERR("Failed to configure Button C: %d", ret);
		return -1;
	}

	// Configure interrupts for buttons
	ret = gpio_pin_interrupt_configure_dt(&button_a, GPIO_INT_EDGE_FALLING);
	if (ret != 0)
	{
		LOG_ERR("Failed to configure interrupt for Button A: %d", ret);
		return -1;
	}

	ret = gpio_pin_interrupt_configure_dt(&button_b, GPIO_INT_EDGE_FALLING);
	if (ret != 0)
	{
		LOG_ERR("Failed to configure interrupt for Button B: %d", ret);
		return -1;
	}

	ret = gpio_pin_interrupt_configure_dt(&button_c, GPIO_INT_EDGE_FALLING);
	if (ret != 0)
	{
		LOG_ERR("Failed to configure interrupt for Button C: %d", ret);
		return -1;
	}

    // Initialize callbacks
	gpio_init_callback(&button_a_cb_data, button_a_pressed, BIT(button_a.pin));
	gpio_add_callback(button_a.port, &button_a_cb_data);

	gpio_init_callback(&button_b_cb_data, button_b_pressed, BIT(button_b.pin));
	gpio_add_callback(button_b.port, &button_b_cb_data);

	gpio_init_callback(&button_c_cb_data, button_c_pressed, BIT(button_c.pin));
	gpio_add_callback(button_c.port, &button_c_cb_data);

	while (true)
    {
        // Toggle LED as an example action
        ret = gpio_pin_toggle_dt(&led);
        if (ret != 0)
        {
            LOG_ERR("Could not toggle LED");
            return -1;
        }

        k_sleep(K_MSEC(500)); // Adjust as needed
    }

    return 0;
}

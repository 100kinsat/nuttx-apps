#include <nuttx/config.h>
#include <arch/board/cxd56_gpioif.h>
#include <stdbool.h>

#define GPIO_PIN    PIN_UART2_TXD

int main(int argc, FAR char *argv[])
{
    board_gpio_config(GPIO_PIN, 0, false, true, PIN_FLOAT);
    board_gpio_write(GPIO_PIN, 0);
    bool ptn = false;

    while (1) {
        board_gpio_write(GPIO_PIN, ptn);
        ptn = !ptn;
    }
}
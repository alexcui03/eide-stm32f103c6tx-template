#include <stm32f10x.h>

void delay(int t) {
    while (t--) for (int i = 0; i < 1000; ++i) __NOP();
}

int main() {
    GPIO_InitTypeDef gpio_defa;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    gpio_defa.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
    gpio_defa.GPIO_Speed = GPIO_Speed_50MHz;
    gpio_defa.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &gpio_defa);

    while (1) {
        GPIO_SetBits(GPIOA, GPIO_Pin_1);
        GPIO_ResetBits(GPIOA, GPIO_Pin_2);
        delay(1000);
        GPIO_ResetBits(GPIOA, GPIO_Pin_1);
        GPIO_SetBits(GPIOA, GPIO_Pin_2);
        delay(1000);
    }
    return 0;
}

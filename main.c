#include <iostream>
int main()
{
    while (1)
    {
        int digit;
        if (digit != 2)
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
        }
        if (digit != 5 && digit != 6)
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
        }
        if (digit != 1 && digit != 7 && digit != 0)
        {
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);
        }
        if (digit != 1 && digit != 4)
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
        }
        if (digit != 1 && digit != 7 && digit != 4 && digit != 9)
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
        }
        if (digit == 1 || digit == 6 || digit == 8)
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
        }
        if (digit == 4 || digit == 6 || digit == 8 || digit == 5 || digit == 9)
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
        }
    }
}
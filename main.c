#include <stdbool.h>
void resetPins()
{
    // two digits
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
    // ones digit
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);
}
void displayNumbers(int num)
{
    resetPins();
    int onesDigit = num % 10;
    int twosDigit = num / 10;

    // display ones digit
    if (onesDigit != 2)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
    }
    if (onesDigit != 5 && onesDigit != 6)
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
    }
    if (onesDigit != 1 && onesDigit != 7 && onesDigit != 0)
    {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);
    }
    if (onesDigit != 1 && onesDigit != 4)
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
    }
    if (onesDigit != 1 && onesDigit != 7 && onesDigit != 4 && onesDigit != 9)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
    }
    if (onesDigit == 2 || onesDigit == 6 || onesDigit == 8 || onesDigit == 0)
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
    }
    if (onesDigit == 4 || onesDigit == 6 || onesDigit == 8 || onesDigit == 5 || onesDigit == 9 || onesDigit == 0)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
    }
    // turn off LED

    // tens digit
    if (twosDigit != 2)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
    }
    if (twosDigit != 5 && twosDigit != 6)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
    }
    if (twosDigit != 1 && twosDigit != 7 && twosDigit != 0)
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
    }
    if (twosDigit != 1 && twosDigit != 4)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
    }
    if (twosDigit != 1 && twosDigit != 7 && twosDigit != 4 && twosDigit != 9)
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
    }
    if (twosDigit == 2 || twosDigit == 6 || twosDigit == 8 || twosDigit == 0)
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
    }
    if (twosDigit == 4 || twosDigit == 6 || twosDigit == 8 || twosDigit == 5 || twosDigit == 9 || twosDigit == 0)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
    }
}

void greenLight(int toggle)
{ // if toggle = true: turn on
    if (toggle == 1)
    {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
    }
}

void redLight(int toggle)
{ // if toggle = 1: turn on
    if (toggle == 1)
    {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);
    }
}

bool checkSensor(int sensor_identifier)
{ // sensor_identifer==1 -> sensor A, sensor_identifer==2 -> sensor B

    if (sensor_identifier == 1)
    {
    }
    else if (sensor_identifier == 2)
    {
    }

    return true;
}

bool A_flag;
bool B_flag;
// occupancy count
int count{0};
int max = 4;
while (1)
{

    displayNumbers(count);
    if (count >= max)
    {
        redLight(1);
        greenLight(-1);
    }
    else
    {
        redLight(-1);
        greenLight(1);
    }
    if (checkSensor(1) == true)
    {
        if (A_flag == true)
        {
            A_flag = false;
            continue;
        }
        else if (B_flag == true)
        {
            count++;
            B_flag = false;
        }
        else
        {
            A_flag = true;
        }
    }
    else if (checkSensor(2) == true)
    {
        if (B_flag == true)
        {
            B_flag = false;
            continue
        }
        else if (A_flag == true && count >= 1)
        {
            count--;
            A_flag = false;
        }
        else
        {
            B_flag = true;
        }
    }
}
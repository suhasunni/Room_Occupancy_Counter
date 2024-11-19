void displayNumbers(int num)
{
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

while (1)
{
    /* USER CODE END WHILE */
    for (int i = 0; i <= 99; i++)
    {
        displayNumbers(i);
        HAL_Delay(1);
        resetPins();
    }
    break;

    /* USER CODE BEGIN 3 */
}
#include "main.h"
#include "stm32f4xx_hal.h"
#include "led.h"

static GPIO_InitTypeDef GPIO_InitStruct = {0};

void led_setup(void) {
  __HAL_RCC_GPIOA_CLK_ENABLE();
  GPIO_InitStruct.Pin = LED_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Output push-pull mode
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);
}

void led_loop(void) {
  // HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
  // HAL_Delay(1000); // Delay for 1 second

  // Turn the LED on
  HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_SET);
  HAL_Delay(1000); // Delay for 1 second

  // Turn the LED off
  HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET);
  HAL_Delay(1000); // Delay for 1 second
}

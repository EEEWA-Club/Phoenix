#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "led.h"

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* Private defines -----------------------------------------------------------*/
/* GPIO Pins definitions */
#define B1_GPIO_Port        GPIOC
#define B1_Pin              GPIO_PIN_13

/* UART Pins definitions */
#define USART_TX_GPIO_Port  GPIOA
#define USART_TX_Pin        GPIO_PIN_2
#define USART_RX_GPIO_Port  GPIOA
#define USART_RX_Pin        GPIO_PIN_3

/* LED Pins definitions */
#define LD2_GPIO_Port       GPIOA
#define LD2_Pin             GPIO_PIN_5

/* External LED Pins */
#define LED_PORT            GPIOA
#define LED_PIN             GPIO_PIN_10

/* SWD Debug Pins definitions */
#define TMS_GPIO_Port       GPIOA
#define TMS_Pin             GPIO_PIN_13
#define TCK_GPIO_Port       GPIOA
#define TCK_Pin             GPIO_PIN_14
#define SWO_GPIO_Port       GPIOB
#define SWO_Pin             GPIO_PIN_3

/* SPI2 Pins definitions */
#define SPI2_SCK_GPIO_Port  GPIOB
#define SPI2_SCK_Pin        GPIO_PIN_13
#define SPI2_MISO_GPIO_Port GPIOB
#define SPI2_MISO_Pin       GPIO_PIN_14
#define SPI2_MOSI_GPIO_Port GPIOB
#define SPI2_MOSI_Pin       GPIO_PIN_15
#define SPI2_CS_GPIO_Port   GPIOA
#define SPI2_CS_Pin         GPIO_PIN_4
#define NRF24L01_CSN_PORT   GPIOA
#define NRF24L01_CSN_PIN    GPIO_PIN_4

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

#include "communication.h"

/* Private functions */
static void CS_LOW(void);
static void CS_HIGH(void);

void communication_init(void) {
    /* Initialize the CS pin for NRF24L01 (Chip Select) */
    CS_HIGH();

    /* You may need to add further initialization for SPI2 and NRF24L01 here */
}

void communication_send_data(const uint8_t* data, uint8_t length) {
    /* Select NRF24L01 for communication */
    CS_LOW();

    /* Send data to NRF24L01 using SPI2 */
    HAL_SPI_Transmit(&hspi2, (uint8_t*)data, length, HAL_MAX_DELAY);

    /* Deselect NRF24L01 */
    CS_HIGH();
}

void communication_receive_data(uint8_t* data, uint8_t* length) {
    /* Select NRF24L01 for communication */
    CS_LOW();

    /* Receive data from NRF24L01 using SPI2 */
    HAL_SPI_Receive(&hspi2, data, *length, HAL_MAX_DELAY);

    /* Deselect NRF24L01 */
    CS_HIGH();
}

/* Helper function to set CS pin low (select NRF24L01) */
static void CS_LOW(void) {
    HAL_GPIO_WritePin(NRF24L01_CSN_PORT, NRF24L01_CSN_PIN, GPIO_PIN_RESET);
}

/* Helper function to set CS pin high (deselect NRF24L01) */
static void CS_HIGH(void) {
    HAL_GPIO_WritePin(NRF24L01_CSN_PORT, NRF24L01_CSN_PIN, GPIO_PIN_SET);
}

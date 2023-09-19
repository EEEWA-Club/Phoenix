#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

/* Function prototypes */
void communication_init(void);
void communication_send_data(const uint8_t* data, uint8_t length);
void communication_receive_data(uint8_t* data, uint8_t* length);

#ifdef __cplusplus
}
#endif

#endif /* COMMUNICATION_H */

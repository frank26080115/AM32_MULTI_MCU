/*
 * crsf.h
 *
 *  Created on: Jun 27, 2023
 *      Author: alkaz
 */

#ifndef CRSF_H_
#define CRSF_H_

#include <stdint.h>

// these CRSF_CHANNEL_VALUE_ constants are taken from https://github.com/ExpressLRS/ExpressLRS/blob/master/src/lib/CrsfProtocol/crsf_protocol.h 
#define CRSF_CHANNEL_VALUE_MIN  172 // 987us - actual CRSF min is 0 with E.Limits on
#define CRSF_CHANNEL_VALUE_1000 191
#define CRSF_CHANNEL_VALUE_MID  992
#define CRSF_CHANNEL_VALUE_2000 1792
#define CRSF_CHANNEL_VALUE_MAX  1811 // 2012us - actual CRSF max is 1984 with E.Limits on
#define CRSF_FRAMETYPE_RC_CHANNELS_PACKED 0x16

#define CRSF_CHAN_CNT 16
#define CRSF_BUFF_CNT 100
extern uint8_t  crsf_buffer[CRSF_BUFF_CNT];   // accessed by crsf_UART_Init to setup DMA
extern uint16_t crsf_channels[CRSF_CHAN_CNT]; // accessed by main application
extern uint8_t  crsf_input_channel;           // assigned from EEPROM
//extern uint8_t crsf_output_PWM_channel;     // purpose unknown

void crsf_UART_Init(void);
void crsf_startDma(void);
void crsf_decode(void);

#endif /* CRSF_H_ */

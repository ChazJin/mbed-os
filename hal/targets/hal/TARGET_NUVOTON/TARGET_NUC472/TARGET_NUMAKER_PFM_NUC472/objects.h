/* mbed Microcontroller Library
 * Copyright (c) 2015-2016 Nuvoton
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MBED_OBJECTS_H
#define MBED_OBJECTS_H

#include "cmsis.h"
#include "PortNames.h"
#include "PeripheralNames.h"
#include "PinNames.h"
#include "dma_api.h"

#ifdef __cplusplus
extern "C" {
#endif

struct gpio_irq_s {
    //IRQn_Type irq_n;
    //uint32_t irq_index;
    //uint32_t event;
    
    PinName     pin;
    uint32_t    irq_handler;
    uint32_t    irq_id;
};

struct port_s {
    PortName port;
    uint32_t mask;
    PinDirection direction;
};

struct analogin_s {
    ADCName adc;
    //PinName pin;
};

struct serial_s {
    UARTName uart;
    PinName pin_tx;
    PinName pin_rx;
    
    uint32_t baudrate;
    uint32_t databits;
    uint32_t parity;
    uint32_t stopbits;
    
    void        (*vec)(void);
    uint32_t    irq_handler;
    uint32_t    irq_id;
    uint32_t    inten_msk;
    
    // Async transfer related fields
    DMAUsage    dma_usage_tx;
    DMAUsage    dma_usage_rx;
    int         dma_chn_id_tx;
    int         dma_chn_id_rx;
    uint32_t    event;
    void        (*irq_handler_tx_async)(void);
    void        (*irq_handler_rx_async)(void);
};

struct spi_s {
    SPIName spi;
    PinName pin_miso;
    PinName pin_mosi;
    PinName pin_sclk;
    PinName pin_ssel;
    
    //void        (*vec)(void);
    
    // Async transfer related fields
    DMAUsage    dma_usage;
    int         dma_chn_id_tx;
    int         dma_chn_id_rx;
    uint32_t    event;
    //void        (*irq_handler_tx_async)(void);
    //void        (*irq_handler_rx_async)(void);
};

struct i2c_s {
    I2CName     i2c;
    //void        (*vec)(void);
    int         slaveaddr_state;
    
    uint32_t    tran_ctrl;
    char *      tran_beg;
    char *      tran_pos;
    char *      tran_end;
    int         inten;
    
    
    // Async transfer related fields
    DMAUsage    dma_usage;
    uint32_t    event;
    int         stop;
    uint32_t    address;
};

struct pwmout_s {
    PWMName pwm;
    //PinName pin;
    uint32_t period_us;
    uint32_t pulsewidth_us;
};

struct sleep_s {
    uint32_t start_us;
    uint32_t end_us;
    uint32_t period_us;
    int powerdown;
};

struct trng_s {

};

#ifdef __cplusplus
}
#endif

#include "gpio_object.h"

#endif

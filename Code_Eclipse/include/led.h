/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef BLINKLED_H_
#define BLINKLED_H_

#include "stm32f7xx.h"
#include "stm32f7xx_hal.h"

// ----- LED definitions ------------------------------------------------------

// Adjust these definitions for your own board.


// Ports numbers are: PA=0, PB=1, PC=2, PD=3, PE=4, PF=5, PG=6, PH=7, PI=8.

#if defined(STM32F746xx)

#if defined(STM32F746_EVAL)

//#warning "Assume a STM32F746G-EVAL board, PF12 & PB7, active low."

#define BLINK_PORT_NUMBER         (5)
#define BLINK_PIN_NUMBER          (12)

#define BLINK_PORT_NUMBER_RED     (1)
#define BLINK_PIN_NUMBER_RED      (7)

#define BLINK_ACTIVE_LOW          (1)

#else

#warning "Assume a STM32F746G-DISCO board, PI1, active high."

// STM32F746-DISCO definitions (the GREEN led, I1, active high)

#define BLINK_PORT_NUMBER               (8)
#define BLINK_PIN_NUMBER                (1)
#define BLINK_ACTIVE_LOW                (0)

#endif

#else

#warning "Unknown board, assume PA5, active high."

#define BLINK_PORT_NUMBER               (0)
#define BLINK_PIN_NUMBER                (5)
#define BLINK_ACTIVE_LOW                (0)

#endif

#define BLINK_GPIOx(_N)                 ((GPIO_TypeDef *)(GPIOA_BASE + (GPIOB_BASE-GPIOA_BASE)*(_N)))
#define BLINK_PIN_MASK(_N)              (1 << (_N))
#define BLINK_RCC_MASKx(_N)             (RCC_AHB1ENR_GPIOAEN << (_N))

// ----------------------------------------------------------------------------

extern
void
blink_led_init(void);

// ----------------------------------------------------------------------------

void
blink_led_on(void);

void
blink_led_off(void);

// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------

#endif // BLINKLED_H_

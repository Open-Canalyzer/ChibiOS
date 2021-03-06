/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef MCUCONF_H
#define MCUCONF_H

/*
 * AVR drivers configuration.
 * The following settings override the default settings present in
 * the various device driver implementation headers.
 * Note that the settings for each driver only have effect if the driver
 * is enabled in halconf.h.
 */

/*
 * ADC driver system settings.
 */
#define AVR_ADC_USE_ADC1                   FALSE

/*
 * CAN driver system settings.
 */

/*
 * MAC driver system settings.
 */

/*
 * PWM driver system settings.
 */
#define AVR_PWM_USE_TIM1                   FALSE
#define AVR_PWM_USE_TIM2                   FALSE
#define AVR_PWM_USE_TIM3                   FALSE
#define AVR_PWM_USE_TIM4                   FALSE
#define AVR_PWM_USE_TIM5                   FALSE

/*
 * ICU driver system settings.
 */
#define AVR_ICU_USE_TIM1                   FALSE
#define AVR_ICU_USE_TIM3                   FALSE
#define AVR_ICU_USE_TIM4                   FALSE
#define AVR_ICU_USE_TIM5                   FALSE

/*
 * GPT driver system settings.
 */
#define AVR_GPT_USE_TIM1                   FALSE
#define AVR_GPT_USE_TIM2                   FALSE
#define AVR_GPT_USE_TIM3                   FALSE
#define AVR_GPT_USE_TIM4                   FALSE
#define AVR_GPT_USE_TIM5                   FALSE

/*
 * SERIAL driver system settings.
 */
#define AVR_SERIAL_USE_USART0              FALSE
#define AVR_SERIAL_USE_USART1              FALSE

/*
 * I2C driver system settings.
 */
#define AVR_I2C_USE_I2C1                   FALSE

/*
 * SPI driver system settings.
 */
#define AVR_SPI_USE_SPI1                   FALSE
#define AVR_SPI_USE_16BIT_POLLED_EXCHANGE  FALSE

#define AVR_USB_USE_USB1                   TRUE

#endif /* MCUCONF_H */

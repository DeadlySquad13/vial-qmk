#pragma once

#include_next <mcuconf.h>

#undef RP_PWM_USE_PWM4
#define RP_PWM_USE_PWM4                  TRUE

// #undef RP_I2C_USE_I2C1
// #define RP_I2C_USE_I2C1 TRUE

#undef RP_SPI_USE_SPI1
#define RP_SPI_USE_SPI1 TRUE
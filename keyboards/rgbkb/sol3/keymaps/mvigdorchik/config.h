/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#pragma once

#define ENCODER_RESOLUTION 2

// 20m timeout (20m * 60s * 1000mil)
// #define RGB_DISABLE_TIMEOUT 1200000
#define RGB_DISABLE_WHEN_USB_SUSPENDED

#define SPLIT_WPM_ENABLE

#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2
// 224B per layer right now
#define DYNAMIC_KEYMAP_LAYER_COUNT 8
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 2047

#define VIA_QMK_RGBLIGHT_ENABLE

#define STM32_ONBOARD_EEPROM_SIZE 2048

/* Encoder Configuration */
//      Matrix Entries  k36/k35(E1SW>B13), k33/k32, k7/k28
#define ENCODERS_PAD_A { A1, B10, A13 }
#define ENCODERS_PAD_B { A2, B11, B14 }
//      Matrix Entries  k72/k71(E5SW>B0), k69/k68, k43/k64
#define ENCODERS_PAD_A_RIGHT { A1, C15,  B3 }
#define ENCODERS_PAD_B_RIGHT { A2, C14, B13 }

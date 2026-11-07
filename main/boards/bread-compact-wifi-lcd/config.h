#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

// =====================================================================
// ZARA AI pin map
// ESP32-S3-WROOM-1 N16R8 + INMP441 mic + MAX98357A amp + ST7735 128x160
// Camera pins (GPIO 4-13, 15-18) are intentionally NOT used by this
// firmware, so the camera stays wired but idle.
// UNTESTED: not compiled or run on hardware.
// =====================================================================

#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

// Mic and speaker use two separate I2S buses (simplex)
#define AUDIO_I2S_METHOD_SIMPLEX

// INMP441 microphone
#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_1
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_2
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_42

// MAX98357A amplifier
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_38   // DIN on the amp
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_40
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_41

// Buttons and LED (GPIO 48 is the TFT chip-select, so no LED here)
#define BUILTIN_LED_GPIO        GPIO_NUM_NC
#define BOOT_BUTTON_GPIO        GPIO_NUM_0
#define TOUCH_BUTTON_GPIO       GPIO_NUM_NC
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_NC
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_NC

// ST7735 TFT (backlight wired straight to 3.3V, so no backlight pin)
#define DISPLAY_MOSI_PIN      GPIO_NUM_39
#define DISPLAY_CLK_PIN       GPIO_NUM_14
#define DISPLAY_DC_PIN        GPIO_NUM_21
#define DISPLAY_RST_PIN       GPIO_NUM_47
#define DISPLAY_CS_PIN        GPIO_NUM_48
#define DISPLAY_BACKLIGHT_PIN GPIO_NUM_NC

// 128x160 settings copied from the project's ST7735_128X160 option
#define DISPLAY_WIDTH     128
#define DISPLAY_HEIGHT    160
#define DISPLAY_MIRROR_X  true
#define DISPLAY_MIRROR_Y  true
#define DISPLAY_SWAP_XY   false
#define DISPLAY_INVERT_COLOR false
#define DISPLAY_RGB_ORDER LCD_RGB_ELEMENT_ORDER_RGB
#define DISPLAY_OFFSET_X  0
#define DISPLAY_OFFSET_Y  0
#define DISPLAY_SPI_MODE  0

#endif // _BOARD_CONFIG_H_

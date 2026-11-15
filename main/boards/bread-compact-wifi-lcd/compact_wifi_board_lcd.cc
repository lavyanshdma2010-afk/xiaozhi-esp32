#include "wifi_board.h"
#include "codecs/no_audio_codec.h"
#include "display/lcd_display.h"
#include "system_reset.h"
#include "application.h"
#include "button.h"
#include "config.h"
#include "mcp_server.h"
#include "esp32_camera.h"

#include <esp_log.h>
#include <driver/i2c_master.h>
#include <esp_lcd_panel_vendor.h>
#include <esp_lcd_panel_io.h>
#include <esp_lcd_panel_ops.h>
#include <driver/spi_common.h>

// UNTESTED: not compiled or run on hardware.
// Zara AI version of the Bread Compact WiFi + LCD board.
// Changes from the stock file:
//  - only the ST7735/ST7789-style panel path is kept
//  - no status LED (GPIO 48 is the TFT chip-select)
//  - no lamp test tool (GPIO 18 is a camera data pin)
//  - no backlight control (backlight is wired to 3.3V)
//  - SPI clock lowered to 10 MHz for jumper-wire reliability
//  - built-in camera enabled, so the AI can take a photo and describe it

#define TAG "CompactWifiBoardLCD"

class CompactWifiBoardLCD : public WifiBoard {
private:
    Button boot_button_;
    LcdDisplay* display_;
    Esp32Camera* camera_ = nullptr;

    void InitializeSpi() {
        spi_bus_config_t buscfg = {};
        buscfg.mosi_io_num = DISPLAY_MOSI_PIN;

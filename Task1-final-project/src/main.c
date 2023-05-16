#include <stdio.h>
#include "driver/i2s_std.h"
#include "driver/gpio.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

#define SAMPLES 1024
#define FREQUENCY 16000
#define I2S_WS 25
#define I2S_SD 33
#define I2S_SCK 32
#define I2S_PORT I2S_NUM_0

TaskHandle_t TaskHandle1 = NULL;
i2s_chan_handle_t tx_handle;

i2s_chan_config_t chan_cfg = I2S_CHANNEL_DEFAULT_CONFIG(I2S_NUM_AUTO, I2S_ROLE_MASTER);


i2s_new_channel(&chan_cfg, &tx_handle);

i2s_std_config_t std_cfg = {
    .clk_cfg = I2S_STD_CLK_DEFAULT_CONFIG(48000),
    .slot_cfg = I2S_STD_MSB_SLOT_DEFAULT_CONFIG(I2S_DATA_BIT_WIDTH_32BIT, I2S_SLOT_MODE_STEREO),
    .gpio_cfg = {
        .mclk = I2S_GPIO_UNUSED,
        .bclk = GPIO_NUM_4,
        .ws = I2S_WS,
        .dout = GPIO_NUM_18,
        .din = I2S_GPIO_UNUSED,
        .invert_flags = {
            .mclk_inv = false,
            .bclk_inv = false,
            .ws_inv = false,
        },
    },
};

i2s_channel_init_std_mode(tx_handle,std_cfg);

gpio_num_t LED = GPIO_NUM_2;

//configura o adc
void adcConfig() {
  adc1_config_width(ADC_WIDTH_BIT_12);
}

//configura o led
void ledConfig() {
  gpio_reset_pin(LED);
  gpio_set_direction(LED, GPIO_MODE_OUTPUT);
}


void task1(void *pvParameter) {
    while(1) {

    }
}

void app_main(void) {
    xTaskCreate(&task1, "readPotency", 2048, NULL, 5, &TaskHandle1);
}

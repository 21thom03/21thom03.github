#include <stdio.h>
#include "main_config.h"

/**********************************
 * Class and structur declaration
***********************************/

i2c_sensor_t BME280_sensor = {
    .port = I2C_PORT,
    .slave_addr = 0x76,
    .i2c_config = {
            .mode = I2C_MODE_MASTER,
            .sda_io_num = I2C_MASTER_SDA_IO, // select GPIO specific to your project
            .sda_pullup_en = GPIO_PULLUP_ENABLE,
            .scl_io_num = I2C_MASTER_SCL_IO, // select GPIO specific to your project
            .scl_pullup_en = GPIO_PULLUP_ENABLE,
            .master.clk_speed = I2C_MASTER_FREQ_HZ, // select frequency specific to your project
    },
};

BME280_config_t BME280_sensor_conf = {
    .mode = SLEEP_CONFIG,
    .t_sb = t_sb_10,
    .filter = filter_2,
    .osrs_T = Over_1,
    .osrs_P = Over_2,
    .osrs_H = Over_4,
    .spi3w = 0,
};

void app_main(void)
{
    uint8_t value_reg;
    uint8_t reset = 0xB6;
    i2c_begin(BME280_sensor);

    BME280_config(BME280_sensor, BME280_sensor_conf);

    i2c_disconnected(BME280_sensor);
}
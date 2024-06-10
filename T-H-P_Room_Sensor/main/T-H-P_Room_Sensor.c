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
    .mode = NORMAL_CONFIG,
    .t_sb = t_sb_10,
    .filter = no_filter,
    .osrs_T = Over_1,
    .osrs_P = Over_2,
    .osrs_H = Over_4,
    .spi3w = 0,
};

void app_main(void)
{
    int32_t raw_values[4] = {0};
    int32_t press, temp, hum;
    i2c_begin(BME280_sensor);

    BME280_Reset_sensor(BME280_sensor);
    BME280_config(BME280_sensor,BME280_sensor_conf);
    BME280_Read_Compensation(BME280_sensor);

    int i;
    for( i=0; i<10;i++)
    {
        if(BME280_Measuring(BME280_sensor) > 0)
        {
                BME280_Read_T_P_H_values(BME280_sensor, raw_values);
                temp = BME280_compensate_T_double(raw_values[0]);
                printf("Temperature %2d °C\n", temp);
                press = BME280_compensate_P_double(raw_values[1]);
                printf("Pressure %d Pascal\n", press);
                hum = BME280_compensate_H_double(raw_values[2]);
                printf("Humidity %d %\n", hum);
                vTaskDelay(500);
        }
    }
    i2c_disconnected(BME280_sensor);
}
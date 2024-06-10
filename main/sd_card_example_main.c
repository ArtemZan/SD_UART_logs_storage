/* SD card and FAT filesystem example.
   This example uses SPI peripheral to communicate with SD card.

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"
#include "sd_test_io.h"
#include "uart.h"
#include "../build/config/sdkconfig.h"
#include "SD.h"
#include "logs.h"

static const char *TAG = "SD debugger";

#define MOUNT_POINT "/sdcard"

void on_uart_read(char *data)
{
    const char *logs_file_path = MOUNT_POINT "/bms_logs.txt";

    ESP_LOGI(TAG, "File written: %s", data);
    SD_write_file(logs_file_path, data);
}

void app_main(void)
{
    SD_init(MOUNT_POINT);

    // Use POSIX and C standard library functions to work with files.

    // First create a file.
    const char *logs_file_path = MOUNT_POINT "/bms_logs.txt";
    ESP_LOGI(TAG, "Read logs file");
    SD_read_file(logs_file_path);

    SD_write_file(logs_file_path, "-------------------------Start SD debugger-------------------------\n");

    SD_debug_log("-------------------------Start SD debugger-------------------------\n");



    vTaskDelay(1000 / portTICK_PERIOD_MS);
    start_read_uart_task();
}

// -----------------------------------------------------------------

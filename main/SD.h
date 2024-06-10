#include "esp_check.h"

esp_err_t SD_write_file(const char *path, char *data);

esp_err_t SD_read_file(const char *path);

esp_err_t SD_init(const char *mount_point);

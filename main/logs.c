#include "SD.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void SD_debug_log(const char* format, ...) {
    printf("SD_debug_log\n");
    va_list args;

    const size_t size = snprintf(NULL, 0, format, args);
    char* buffer = malloc(size + 1);

    va_start(args, format);

    sprintf(buffer, format, args);

    SD_write_file("/sdcard/debug_logs.txt", buffer);
    free(buffer);
}
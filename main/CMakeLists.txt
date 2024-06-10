set(srcs "sd_card_example_main.c"
"uart.c"
"SD.c"
"logs.c")

idf_component_register(SRCS ${srcs}
                       INCLUDE_DIRS "." "$ENV{IDF_PATH}/components/esp_driver_uart/include"
                       REQUIRES fatfs sd_card
                       WHOLE_ARCHIVE)

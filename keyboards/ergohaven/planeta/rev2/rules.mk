SERIAL_DRIVER = vendor

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7789_spi
QUANTUM_PAINTER_LVGL_INTEGRATION = yes
RGBLIGHT_ENABLE = yes

RAW_ENABLE = yes

SRC += lvgl_helpers.c \
	   display.c

OLED_GAMING = yes
COMBO_ENABLE = yes

TAP_DANCE_ENABLE = yes
TAPPING_TERM_PER_KEY = yes
SRC += tap_dance.c

SRC += macroses.c

# ifeq ($(strip $(COMBO_ENABLE)), yes)
#   SRC += combos.c
# endif

ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += led.c
  SRC += font_block.c
endif

ifeq ($(strip $(OLED_GAMING)), yes)
  SRC += keyboards/ergohaven/k02/game/game.c
  SRC += keyboards/ergohaven/k02/game/drawing.c
  SRC += keyboards/ergohaven/k02/game/rndgen.c
endif

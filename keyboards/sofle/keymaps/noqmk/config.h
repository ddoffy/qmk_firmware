#pragma once

// OLED settings
#define OLED_TIMEOUT        80000
#define OLED_BRIGHTNESS     90
#define OLED_DISPLAY_CLOCK  0x80

#define SPLIT_WPM_ENABLE
#define SPLIT_OLED_ENABLE
#define SPLIT_TRANSPORT_MIRROR

#define MASTER_RIGHT

#ifdef MASTER_LEFT
#define USE_SERIAL
#define EE_HANDS
#endif

#ifdef MASTER_RIGHT
#define USE_SERIAL
#define EE_HANDS
#endif

#define TAPPING_TERM_PER_KEY

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
#endif
#define TAPPING_TERM 200

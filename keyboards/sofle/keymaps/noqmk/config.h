#pragma once

// // OLED settings
// #define OLED_TIMEOUT        80000
#define OLED_BRIGHTNESS 90
// #define OLED_DISPLAY_CLOCK  0x80

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

// #define TAPPING_TERM_PER_KEY
//
// #ifdef TAPPING_TERM
//     #undef TAPPING_TERM
// #endif
// #define TAPPING_TERM 175
// MOUSEKEY_DELAY	10	Delay between pressing a movement key and cursor movement
// MOUSEKEY_INTERVAL	20	Time between cursor movements in milliseconds
// MOUSEKEY_MOVE_DELTA	8	Step size
// MOUSEKEY_MAX_SPEED	10	Maximum cursor speed at which acceleration stops
// MOUSEKEY_TIME_TO_MAX	30	Time until maximum cursor speed is reached
// MOUSEKEY_WHEEL_DELAY	10	Delay between pressing a wheel key and wheel movement
// MOUSEKEY_WHEEL_INTERVAL	80	Time between wheel movements
// MOUSEKEY_WHEEL_DELTA	1	Wheel movement step size
// MOUSEKEY_WHEEL_MAX_SPEED	8	Maximum number of scroll steps per scroll action
// MOUSEKEY_WHEEL_TIME_TO_MAX	40	Time until maximum scroll speed is reached

#define MOUSEKEY_WHEEL_DELTA 3

// MOUSEKEY_DELAY	10	Delay between pressing a movement key and cursor movement
// MOUSEKEY_INTERVAL	20	Time between cursor movements in milliseconds
// MOUSEKEY_MOVE_DELTA	8	Step size
// MOUSEKEY_MAX_SPEED	10	Maximum cursor speed at which acceleration stops
// MOUSEKEY_TIME_TO_MAX	30	Time until maximum cursor speed is reached
// MOUSEKEY_WHEEL_DELAY	10	Delay between pressing a wheel key and wheel movement
// MOUSEKEY_WHEEL_INTERVAL	80	Time between wheel movements
// MOUSEKEY_WHEEL_DELTA	1	Wheel movement step size
// MOUSEKEY_WHEEL_MAX_SPEED	8	Maximum number of scroll steps per scroll action
// MOUSEKEY_WHEEL_TIME_TO_MAX	40	Time until maximum scroll speed is reached

#define MOUSEKEY_MOVE_DELTA 4 // Step size
#define MOUSEKEY_MAX_SPEED 5  // Maximum cursor speed at which acceleration stops



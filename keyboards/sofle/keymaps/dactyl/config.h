// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4

#define SPLIT_TRANSPORT_MIRROR

#define MASTER_LEFT

#ifdef MASTER_LEFT
#    define USE_SERIAL
#    define EE_HANDS
#endif

#ifdef MASTER_RIGHT
#    define USE_SERIAL
#    define EE_HANDS
#endif

#define SERIAL_PIN D0
// Optionally add
#define SPLIT_USB_DETECT // later if needed

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif
#define TAPPING_TERM 175

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD


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

#define MOUSEKEY_MOVE_DELTA 2 // Step size
#define MOUSEKEY_MAX_SPEED 5  // Maximum cursor speed at which acceleration stops

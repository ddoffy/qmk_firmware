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

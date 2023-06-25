#ifndef _CVLOD_H_
#define _CVLOD_H_

/*
Here we create declarations for a few functions and variables in CVLOD so they can be referenced from our custom C code.
Later we will tell armips their addresses by defining labels for them in "cvlod.asm"
*/
#include "n64types.h"
#include "controller.h"

// Actually the current gold amount. In this mod, we will use this variable as a sound ID
// for switching between the different sounds, as well as to be able to see the sound ID in the GOLD counter.
extern u32 sound_ID; // 0x801CAB40

extern u16 current_menu; // 0x801CAE0E
extern controller_struct controller; // 0x801C87F4
extern u8 play_sound(u16 song_ID); // 0x800166F8
extern void controller_readData(); // 0x800196DC

enum menu_ID
{
    PAUSE = 0x9
};

#endif
#include "../include/cvlod.h"

// This function will be called inside the game loop function, so that it can constantly check for inputs.
// More specifically, it will be called from 0x80017DD4 (see "main.asm")

// We check if the buttons have been ''pressed'' for changing the sound ID.
// It isn't very responsive (because the input is only updated for one frame, then goes back to 0),
// and you may need to press the buttons a few times for the counter to update.
// The thing is, if we change it to detect the buttons being held, it becomes difficult to land on a specific sound ID.
// That's why we only check if the buttons are being ''held'' for the other controls that don't deal with updating the counter.

// Tip: If you use Project64, you can untick the "Limit FPS" option to make the game go much faster,
// so that you can switch the sound IDs faster as well, without having to press the buttons various times.

void mod_play_any_sound()
{
    if (current_menu == PAUSE)
    {
        switch(controller.buttons_pressed)
        {
            case R_JPAD:
                sound_ID++;
                break;
            
            case L_JPAD:
                sound_ID--;
                break;
                
            case U_JPAD:
                sound_ID += 50;
                break;
                
            case D_JPAD:
                sound_ID -= 50;
                break;
        }
		
        switch(controller.buttons_held)
        {
            case Z_TRIG:
                play_sound(sound_ID);
                break;
                
            case L_TRIG:
                sound_ID = 0;
                break;
        
            case R_TRIG:
                // Stop sound
                play_sound(1);
                break;
        }
    }
    // Original instruction at 0x80017DD4
    // We replaced the call to "controller_readData()" with "mod_play_any_sound()"
    // So in order to not break things up, we put the call we've replaced at the end of this function here,
    // as if we never replaced the call to "controller_readData()".
    controller_readData();
}

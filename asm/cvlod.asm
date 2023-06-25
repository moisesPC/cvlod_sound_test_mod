// Tell armips' linker where the functions and variables we declared in "cv64.h" are located in RAM during the game's execution

// Actually the current gold amount. In this mod, we will use this variable as a sound ID
// for switching between the different sounds, as well as to be able to see the sound ID in the GOLD counter.
.definelabel sound_ID, 0x801CAB40

.definelabel current_menu, 0x801CAE0E
.definelabel controller, 0x801C87F4
.definelabel play_sound, 0x800166F8
.definelabel controller_readData, 0x800196DC
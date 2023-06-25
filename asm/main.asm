// Let armips know we're coding for the N64 architecture
.n64

// Open the ROM file
.open "cvlod.z64", "cvlod.mod.z64", 0

// Include cvlod.asm to tell armips' linker where to find the game's function(s)
.include "asm/cvlod.asm" 

// Set the displacement between ROM and RAM addresses.
// 0x80000400 (entrypoint, RAM) - 0x1000 (entrypoint, ROM) = 0x7FFFF400
.headersize 0x7FFFF400 

// The address we're going to insert our custom code to. We are going to overwrite some unused strings in memory that are related to the unused crash screen.
.org 0x800BD3C0

// Import and link the compiled C object at the address above.
.importobj "play_sound.o"

/// Hooks and patches ///

// Hook (i.e. insert a call to) our "mod_play_any_sound()" function inside the game loop, at 0x80017DD4
.org 0x80017DD4
	jal mod_play_any_sound

// Make the money counter update even if no new money has been collected from money bags.
.org 0x8008B5C8
	nop

// Close the ROM file
.close

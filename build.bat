mips64-elf-gcc -Wall -O1 -mtune=vr4300 -march=vr4300 -mabi=32 -fomit-frame-pointer -G0 -c src/play_sound.c
armips asm/main.asm
n64crc "cvlod.mod.z64"
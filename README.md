# fstring
Faster string.h for PIC16F1xxx. I've recently been making a project for PIC16F18855
that uses the standar functions from string.h but they were too slow for my application
since XC8 doesn't seem to make use of basic indirect addressing optimizations
in it's free version.
Initially I only needed memmove but I decided to code the other functions.

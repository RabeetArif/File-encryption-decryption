#!/bin/bash

g++ -o ./make/output.exe main.c ./Login/*.c ./Registration/*.c ./Encryption/*.c ./Decryption/*.c./File_Status/*.c
./Util/*.c./make/output.exe
exit
: Build and deploy

: Change directory to the project directory and the Arduino IDE directory

set PATH=%PATH%;C:\Program Files (x86)\Arduino\hardware\tools\avr\bin

avr-gcc.exe -mmcu=atmega328p -v "C:\Workspace\Personal\Embedded\Bare Metal\Projects\ATMEGA328P-AVR-GCC\Src\main.c" "C:\Workspace\Personal\Embedded\Bare Metal\Projects\ATMEGA328P-AVR-GCC\Src\hardware.c" "C:\Workspace\Personal\Embedded\Bare Metal\Projects\ATMEGA328P-AVR-GCC\Src\basic.c" -o "C:\Workspace\Personal\Embedded\Bare Metal\Projects\ATMEGA328P-AVR-GCC\Build\outputfile.o"
avr-objcopy.exe -O ihex -j .text -j .data "C:\Workspace\Personal\Embedded\Bare Metal\Projects\ATMEGA328P-AVR-GCC\Build\outputfile.o" "C:\Workspace\Personal\Embedded\Bare Metal\Projects\ATMEGA328P-AVR-GCC\Build\outputfile.hex" 
avrdude.exe -C "C:\Program Files (x86)\Arduino\hardware\tools\avr\etc\avrdude.conf" -v -p atmega328p -c stk500v1 -P "COM4" -b 19200 -U lfuse:w:0xFF:m -U flash:w:"C:\Workspace\Personal\Embedded\Bare Metal\Projects\ATMEGA328P-AVR-GCC\outputfile.hex":i
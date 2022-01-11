/*
	ktlab TinyBASIC V1.0
	Linux edition
	(C)2022 ktlab
*/

// Compiler requires description
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>

// ktlab TinyBASIC symbols
// TO-DO Rewrite defined values to fit your machine as needed
#define SIZE_LINE 78 //Command line buffer length + NULL
#define SIZE_IBUF 78 //i-code conversion buffer size
#define SIZE_LIST 1024 //List buffer size
#define SIZE_ARRY 64 //Array area size
#define SIZE_GSTK 6 //GOSUB stack size(2/nest)
#define SIZE_LSTK 15 //FOR stack size(5/nest)

// Depending on device functions
// TO-DO Rewrite these functions to fit your machine
#define STR_EDITION "LINUX"

// Terminal control
//#define c_putch(c) putchar(c)



/*
ktlab Tiny BASIC
The BASIC entry point
*/
void basic(){
	unsigned char len;

	inew();
	c_puts("TOYOSHIKI TINY BASIC"); newline();
	c_puts(STR_EDITION);
	c_puts(" EDITION"); newline();
	error(); // Print OK, and Clear error flag

	// Input 1 line and execute
	while(1){
		c_putch('>');// Prompt
		c_gets(); // Input 1 line
		len = toktoi(); // Convert token to i-code
		if(err){ // Error
			error();
			continue; // Do nothing
		}

		if(*ibuf == I_SYSTEM){
			return;
		}

		if(*ibuf == I_NUM){ // Case the top includes line number
			*ibuf = len; // Change I_NUM to byte length
			inslist(); // Insert list
			if (err) // Error
				error();  // Print error message
			continue;
		}

		icom(); // Execute direct
		error(); // Print OK, and Clear error flag
	}
}

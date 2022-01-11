/*
	ktlab Tiny BASIC for Linux
	(C)2022 ktlab
	Build: cc ktbasic.c kbasic.c -o ktbasic
*/

#include <stdlib.h>
#include <time.h>

void kbasic(void); // prototype

int main(){
	srand((unsigned int)time(0)); // for RND function
	kbasic(); // call The BASIC
	return 0;
}

/*
** To be compiled with -z execstack
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
	xor rax, rax
	xor rdi, rdi
	mov al, 0x3c
	mov dil, 0x2
	syscall
*/

unsigned char shellcode[] = "\x48\x31\xc0\x48\x31\xff\xb0\x3c\x40\xb7\x02\x0f\x05";

int main(void)
{
  puts("Entry point");
  ((void (*)(void))shellcode)();
  puts("Not displayed");
}

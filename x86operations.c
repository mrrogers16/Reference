#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
void *new_memset(void *str, int c, size_t n);
char *new_strncpy(char *dest, const char *src, size_t n);

char gBuffer1[] = "Once, a WISE MAN said nothing.";

char gBuffer2[] = {0x54, 0x68, 0x65, 0x20, 0x66, 0x6F, 0x6F, 0x6C,
                   0x20, 0x77, 0x6F, 0x6E, 0x64, 0x65, 0x72, 0x73,
                   0x2C, 0x20, 0x74, 0x65, 0x68, 0x20, 0x77, 0x69,
                   0x73, 0x65, 0x20, 0x6D, 0x61, 0x6E, 0x20, 0x61,
                   0x73, 0x6B, 0x73, 0x2E, 0x00};

BYTE gBuffer3[] = {0x23, 0xDC, 0xA8, 0xAB, 0x30, 0x5B, 0x72, 0xE5,
                   0x8D, 0x2F, 0x2D, 0xB4, 0x4F, 0x99, 0xA6, 0x6F};

char gSpace[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

char gScratchBuffer[128];

void printHexBytes(char *data, int length)
{
    int x;

    printf("HEX BYTES:\n\n");
    for (x = 0; x < length; x++)
    {
        if ((x % 8) == 0)
            printf("\n");
        printf("%02X ", (unsigned char)*(data + x));
    }
    printf("\n\n");
    return;
} // printHexBytes

void correctBuffer(char *buffer)
{
    __asm
    {
		mov esi, buffer

		mov al, byte ptr[esi + 19]
		mov bl, byte ptr[esi + 20]


		mov byte ptr[esi + 19], bl
		mov byte ptr[esi + 20], al
        // #5 your code here to correct the error, hard-coded it OK
    }
    return;
}

// the main function for lab #9
int main(int argc, char *argv[])
{
    int x;

    printf("%s\n\n", gBuffer1);
    new_memset(gScratchBuffer, 0, 128); // #1 your function to replace these
    new_memset(gSpace, 0x20, 8);

    new_strncpy(gScratchBuffer, gBuffer2, 128); // #2 your function to replace this one

    printf("%s\n\n", gScratchBuffer); // #5 there is a misspelled word, write assembly to correct it
    correctBuffer(gScratchBuffer);
    printf("BUFFER CORRECTED: %s\n\n", gScratchBuffer);

    memcpy(&gScratchBuffer[96], gBuffer3, 13);
    printHexBytes(&gScratchBuffer[96], 16); // YOU should check to make sure there is an exact match here

    x = _strnicmp(&gBuffer1[8], &gBuffer2[22], 8); // #3 replace the strincmp function (most diffcult)
    if (x == 0)
        printf("SUCCESS - Matched words with mismatched cases!\n\n");
    else
        printf("FAILURE! You stuff didn't match,  :'(   BUT, you can try again!\n\n");

    memcpy(gScratchBuffer, &gBuffer1[8], 5); // #4 replace the memcpy
    memcpy(&gScratchBuffer[5], &gBuffer2[4], 4);
    gScratchBuffer[9] = 0;
    printf("WOOT WOOT: %s\n\n", gScratchBuffer);
    system("pause");
    return 0;
} // main

void *new_memset(void *str, int c, size_t n)
{
    __asm
    {
		push   edi
		mov    ecx, [ebp + 16]          // counter
		mov    al, byte ptr [ebp + 12] // int value to set
		mov    edi, [ebp + 8]           // void * pointer
		rep    stosb 

		mov    eax, [ebp + 8]
		pop    edi

    }
    return;
}

char *new_strncpy(char *dest, const char *src, size_t n)
{
    __asm {
		mov    edi, dst
		mov    esi, src

		xor    ecx, ecx

	LOOP_REP :
		mov    al, byte ptr[esi + ecx]

		mov    byte ptr[edi + ecx], al
		cmp    al, 0
		jz     LOOP_FILL
		inc    ecx
		cmp    ecx, [ebp + 16]
		jne    LOOP_REP

	LOOP_FILL :

		mov byte ptr[edi + ecx], 0x00
		inc ecx
		cmp ecx, [ebp + 16]

		jne LOOP_FILL
    }
}
void memcpy(char *dst, char *src, int size)
{
    __asm {

		mov    edi, dst
		mov    esi, src

		xor    ecx, ecx

	LOOP_REP :
		mov    al, byte ptr[esi + ecx]
		mov    byte ptr[edi + ecx], al
		cmp    al, 0
		jz     Done
		inc    ecx
		cmp    ecx, [ebp + 16]
		jne    LOOP_REP
	Done :
		nop

    }
}
int _strnicmp(char *dst, char *src, int count)
{
    int retVal;
    __asm {
		mov   edi, dst
		mov   esi, src

		xor   ecx, ecx
		xor   eax, eax
		xor   edx, edx

	LOOP_1 :
		mov   al, byte ptr[edi + ecx]
		mov   bl, byte ptr[esi + ecx]
		cmp   al, 0x5A
		ja    NEXT_CHECK
		cmp   al, 0x41
		jae   ADD_1
		jmp   NEXT_CHECK

	ADD_1 :
		add   al, 0x20
		jmp   NEXT_CHECK
	ADD_2 :
	    add   bl, 0x20
		jmp   COMP_STRING

	NEXT_CHECK :
		cmp   bl, 0x5A
		ja    COMP_STRING
		cmp   bl, 0x41
		jae   ADD_2

	COMP_STRING :
		cmp   al, bl
		ja    STRING1_BIG
		jb    STRING2_BIG
		inc   ecx
		cmp   ecx, count
		jz    DONE
		jne   LOOP_1

	STRING1_BIG :
		mov   edx, 1
		jmp   DONE
	STRING2_BIG :
		mov   edx, -1
		jmp   DONE


	DONE :
		mov   [retVal], edx

    }
    return retVal;
}

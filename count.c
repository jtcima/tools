#include <stdio.h>
#include "tools.h"
#include <string.h>



void letter_freq(void)
{
    char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //char *letters_lower = "abcdefghijklmnopqrstuvwxyz";
    char buf[CAESAR_LEN];
    puts("Enter msg: ");
    fgets(buf, CAESAR_LEN, stdin);

    for(int i = 0; i < strlen(letters); i++)
    {
        int c = 0;
        for(int j = 0; j < strlen(buf); j++)
        {
            if(letters[i] == buf[j])
            {
                c += 1;
                
            }
        }
        printf("%c: %d\n", letters[i], c);
    }
}
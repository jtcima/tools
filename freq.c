#include <stdio.h>
#include "config.h"
#include "util.h"
#include <string.h>




void letter_freq(void)
{
    char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char buf[STRING_LEN];
    puts("Enter text: ");
    fgets(buf, STRING_LEN, stdin);

    for(int i = 0; i < strlen(letters); i++)
    {
        int c = 0;
        for(int j = 0; j < strlen(buf); j++)
        {
            if(letters[i] == upper(buf[j]))
            {
                c += 1;                
            }
        }
        printf("%c: %d\n", letters[i], c);
    }
}




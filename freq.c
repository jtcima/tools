
#include <stdio.h>
#include "tools.h"
#include <string.h>

char upper(char c)
{
    if( c >= 'a' && c <= 'z')
    {
        c = c-32;
    }
    
    return c;
}




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




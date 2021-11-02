#include "util.h"
#include "config.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char upper(char c)
{
    if( c >= 'a' && c <= 'z')
    {
        c = c-32;
    }
    
    return c;
}

char* remove_space(char* str)
{
    static char buf[STRING_LEN];
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] != ' ')
        {
            buf[i] = str[i];
        }
        printf("%c", buf[i]);
    }

    return buf;
}

void fill(char* str1, char* str2)
{
    if(strlen(str1) > strlen(str2))
    {
        int dif = strlen(str1) - strlen(str2);
        int index = strlen(str2)-1;
        for (int i = 0; i < dif; i++)
        {
            str2[index] = str2[i];
            index += 1;
            if(strlen(str1) == strlen(str2))
            {
                break;
            }
        }
    }
    else
    {
        return;
    }
}


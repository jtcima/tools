#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "config.h"
#include "util.h"
#include "error.h"

char x;
char msg[STRING_LEN];
char key[STRING_LEN];

void vigenere_decode(void)
{
    
    puts("Enter encrypted msg:");
    fgets(msg, STRING_LEN, stdin);
    for(int i = 0; i < strlen(msg)-1; i++)
    {
        if(msg[i] < 'A' || (msg[i] > 'Z' && msg[i] < 'a') || msg[i] > 'z') 
        {
            invalid_args();
        }
    }
    puts("Enter key: ");
    fgets(key, STRING_LEN, stdin);
    for(int i = 0; i < strlen(key)-1; i++)
    {
        if(key[i] < 'A' || (key[i] > 'Z' && key[i] < 'a') || key[i] > 'z')
        {
            invalid_args();
        }
    }

    fill(msg, key);

    puts("The decrypted msg is: ");

    for(int i = 0; i < strlen(msg); i++)
    {       
        if(upper(msg[i]) >= 65 && upper(msg[i]) <= 90)
        {
            x = (upper(msg[i]) - upper(key[i]) + 26) %26;
            x += 'A';
            printf("%c", x);
        }
        else
        {
            printf("%c", msg[i]);
        }
        
    }
}
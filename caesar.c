#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "error.h"
#include "config.h"

void caesar_decrypt(void)
{
    char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *letters_lower = "abcdefghijklmnopqrstuvwxyz";
    char msg[STRING_LEN];
    char msgcpy[STRING_LEN];
    int key;

    puts("Enter encrypted msg:");
    fgets(msg, STRING_LEN, stdin);

    for(int i = 0; msg[i] != '\0'; i++)
    {
        if(isdigit(msg[i]))
        {
            invalid_args();
        }
    }

    for(key = 1; key < 26; key++)
    {
        for(int i = 0; msg[i] != '\0';i++)
        {
            if(msg[i] == ' ')
            {
                msgcpy[i] = ' ';
                i++; 
            }
            
            if(msg[i] >= 'a' && msg[i] <= 'z')
            {
                if((strchr(letters_lower, msg[i])-key) < letters_lower)
                {
                    int pos = strlen(letters_lower)-(key-(strchr(letters_lower, msg[i]) - letters_lower));
                    msgcpy[i] = letters_lower[pos];
                }
                else
                {
                    msgcpy[i] = *(strchr(letters_lower, msg[i])-key);
                }
            }

            if(msg[i] >= 'A' && msg[i] <= 'Z')
            {
                if((strchr(letters, msg[i])-key) < letters)
                {
                    int pos = strlen(letters)-(key-(strchr(letters, msg[i]) - letters));
                    msgcpy[i] = letters[pos];
                }
                else
                {
                    msgcpy[i] = *(strchr(letters, msg[i])-key);
                }
            }       
        }
        printf("msg no.%d is: %s\n", key, msgcpy);
    } 
}


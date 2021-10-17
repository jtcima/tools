#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "error.h"

void caesar_decrypt(void)
{
    char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *letters_lower = "abcdefghijklmnopqrstuvwxyz";
    int key;
    puts("Enter key pass:");
    scanf("%d", &key);

    if(!scanf("%d", &key) || key < 0)
    {
        invalid_args();
        exit(1);
    }

    if(key > 26) 
    {
        while (key >= 26)
        {
            key = key % 26;
        }
        
    }

    static char msg[15];
    puts("Enter encrypted msg:");
    scanf("%s", msg);

    for(int i = 0; msg[i] != '\0'; i++)
    {
        if(isdigit(msg[i]))
        {
            invalid_args();
            exit(1);
        }
    }

    for(int i = 0; msg[i] != '\0'; i++)
    {
        if(msg[i] >= 'a' && msg[i] <= 'z')
        {
            if((strchr(letters_lower, msg[i])-key) < letters_lower)
            {
                int pos = strlen(letters_lower)-(key-(strchr(letters_lower, msg[i]) - letters_lower));
                msg[i] = letters_lower[pos];
            }
            else
            {
                msg[i] = *(strchr(letters_lower, msg[i])-key);
            }
        }

        if(msg[i] >= 'A' && msg[i] <= 'Z')
        {
            if((strchr(letters, msg[i])-key) < letters)
            {
                int pos = strlen(letters)-(key-(strchr(letters, msg[i]) - letters));
                msg[i] = letters[pos];
            }
            else
            {
                msg[i] = *(strchr(letters, msg[i])-key);
            }
        }       
    }
    
    printf("The decrypted msg is: %s", msg);
}


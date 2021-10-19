#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "error.h"
#include "tools.h"

void caesar_decrypt(void)
{
    char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *letters_lower = "abcdefghijklmnopqrstuvwxyz";
    char msg[CAESAR_LEN];
    int key;
    //puts("Enter key pass (enter positive number only):");
    //int check = scanf("%d", &key);
    //int c = getchar();
/*
    if(c != '\n' && c != EOF)
    {
        invalid_args();
    }
    
    if (check != 1 || key < 0)
    {
        invalid_args();
    }

 
    if(key > 26) 
    {
        while (key >= 26)
        {
            key = key % 26;
        }
    }
*/

    puts("Enter encrypted msg:");
    fgets(msg, CAESAR_LEN, stdin);
    char msgcpy[CAESAR_LEN];
   
/*
    for(int i = 0; msg[i] != '\0'; i++)
    {
        if(isdigit(msg[i]))
        {
            invalid_args();
        }
    }
*/
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
    
    
        printf("The decrypted msg %d is: %s\n", key, msgcpy);

    }
    

}


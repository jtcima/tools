#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void caesar_decrypt()
{
    char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int key;
    printf("enter key: \n");
    scanf("%d", &key);
    static char msg[15];
    printf("\nenter encrypted msg: \n");
    scanf("%s", msg);
    for(int i = 0; msg[i] != '\0'; i++)
    {
        if(msg[i] >= 'a' && msg[i] <= 'z')
        {
            msg[i] = msg[i] - 32;
        }
        
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
    
    printf("the decrypted msg is: %s", msg);
}


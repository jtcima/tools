#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "config.h"

char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char msg[STRING_LEN];
FILE* key;

void keygen()
{
    
    for (int i = 0; i < strlen(letters); i++)
    {
        for (int j = 0; j < strlen(letters); j++)
        {
            for (int k = 0; k < strlen(letters); k++)
            {
                for(int l = 0; l < strlen(letters); l++)
                {
                    for(int m = 0; m < strlen(letters); m++)
                    {
                        for (int n = 0; n < strlen(letters); n++)
                        {
                            
                            key = fopen("key.txt", "a");
                            fprintf(key,"%c%c%c%c%c%c\n", letters[i], letters[j], letters[k], letters[l], letters[m], letters[n]);
                            fclose(key);
                            
                            //printf("%c%c%c%c%c%c\n", letters[i], letters[j], letters[k], letters[l], letters[m], letters[n]);
                        }
                    }
                }
            }
        }
    }
}

char* input()
{
    puts("Enter encrypted msg:");
    fgets(msg, STRING_LEN, stdin);
    return msg;
}

void generate(char* input_string)
{
    char x;
    char res[strlen(letters)][strlen(input_string)];
    for(int i = 0; i < strlen(input_string)-1; i++)
    {
        for(int j = 0; j < strlen(letters); j++)
        {
            x = (input_string[i] - letters[j] + 26) %26;
            x += 'A';
            res[j][i] = x;
        }         
    }

    for(int i = 0; i < sizeof(res)/sizeof(res[0]); i++)
    {
        for (int j = 0; j < sizeof(res[0])/sizeof(res[0][0]); j++)
        {
            printf("%c", res[i][j]);
        }
        printf("\n");
    }
}



int main() {

    keygen();
    //generate(input());

    return 0;
}

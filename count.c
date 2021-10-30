#include <stdio.h>
//#include "tools.h"
#include <string.h>

#define CAESAR_LEN 50000

struct count
{
    char letter;
    int num;
};

struct count sub[26];

void letter_freq(char* buf)
{
    char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //char *letters_lower = "abcdefghijklmnopqrstuvwxyz";

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
        
        sub[i].letter = letters[i];
        sub[i].num = c;
        //printf("%c: %d\n", sub[i].letter, sub[i].num);
    }

    for (int i = 0; i < (sizeof(sub)/ sizeof(sub[0])); i++)
    {
        for (int j = 0; j < (sizeof(sub)/sizeof(sub[0])); j++)
        {
            if(sub[i].num > sub[j].num)
            {
                struct count temp = sub[i];
                sub[i] = sub[j];
                sub[j] = temp;
            }
        }
    }

    for (int i = 0; i < sizeof(sub)/ sizeof(sub[0]); i++)
    {
        printf("%c: %d\n", sub[i].letter, sub[i].num);
    }

}

void subsitution()
{
    char common_letters[26] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    char buf[CAESAR_LEN];
    puts("Enter msg: ");
    fgets(buf, CAESAR_LEN, stdin);

    letter_freq(buf);

    for(int i = 0; i < strlen(buf); i++)
    {
        for(int j = 0; j < sizeof(sub)/sizeof(sub[0]); j++)
        {
            if(buf[i] == sub[j].letter)
            {
                buf[i] = common_letters[j];
                break;
            }
        }

        printf("%c ", buf[i]);
    }
}

int main()
{
    subsitution();
}
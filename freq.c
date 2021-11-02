#include <stdio.h>
#include "config.h"
#include "util.h"
#include <string.h>

struct count
{
    char letter;
    int c_num;
};


void letter_freq(void)
{
    char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static struct count count_letter[26];
    char buf[STRING_LEN];
    puts("Enter string: ");
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
        count_letter[i].letter = letters[i];
        count_letter[i].c_num = c;
    }

    for (int i = 0; i < (sizeof(count_letter)/ sizeof(count_letter[0])); i++)
    {
        for (int j = 0; j < (sizeof(count_letter)/sizeof(count_letter[0])); j++)
        {
            if(count_letter[i].c_num > count_letter[j].c_num)
            {
                struct count temp = count_letter[i];
                count_letter[i] = count_letter[j];
                count_letter[j] = temp;
            }
        }
    }

    for (int i = 0; i < sizeof(count_letter)/ sizeof(count_letter[0]); i++)
    {
        printf("%c: %d\n", count_letter[i].letter, count_letter[i].c_num);
    }
}

struct count* letter_freq_ver2(char* str)
{
    char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static struct count count_letter[26];

    for(int i = 0; i < strlen(letters); i++)
    {
        int c = 0;
        for(int j = 0; j < strlen(str); j++)
        {
            if(letters[i] == upper(str[j]))
            {
                c += 1;                
            }
        }
        count_letter[i].letter = letters[i];
        count_letter[i].c_num = c;
    }

    for (int i = 0; i < (sizeof(count_letter)/ sizeof(count_letter[0])); i++)
    {
        for (int j = 0; j < (sizeof(count_letter)/sizeof(count_letter[0])); j++)
        {
            if(count_letter[i].c_num > count_letter[j].c_num)
            {
                struct count temp = count_letter[i];
                count_letter[i] = count_letter[j];
                count_letter[j] = temp;
            }
        }
    }

    return count_letter;
}

void com_letters_subs(void)
{
    char common_letters[26] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    char buf[STRING_LEN];
    puts("Enter string: ");
    fgets(buf, STRING_LEN, stdin);

    struct count *sub = letter_freq_ver2(buf);

    for(int i = 0; i < strlen(buf); i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(upper(buf[i]) == sub[j].letter)
            {
                buf[i] = common_letters[j];
                break;
            }
        }

        printf("%c", buf[i]);
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void char_to_num()
{
    char letters[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char buf[5000];
    puts("Enter msg: ");
    fgets(buf, 5000, stdin);
    for (int i = 0; i < strlen(buf); i++ )
    {
        for(int j = 0; j < strlen(letters); j++)
        {
            if(buf[i] == letters[j])
                printf("%d ", j);
        }
    }
}



int main(int argc, char** argv)
{

    //count_char();
    char_to_num();
    


    return 0;
}
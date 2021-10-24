// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
#include "tools.h"
 
/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string. */
void permute(char *a, int start_index, int end_index)
{
int i;
FILE *fp;
if (start_index == end_index)
{
    printf("%s\n", a);
    fp = fopen("result.txt", "a");
    fputs(a, fp);
    fclose(fp);
}
    
else
{
    for (i = start_index; i <= end_index; i++)
    {
        swap((a+start_index), (a+i));
        permute(a, start_index+1, end_index);
        swap((a+start_index), (a+i)); //backtrack
    }
}
}
 
/* Driver program to test above functions */
void input_to_permute()
{
    char str[STRING_LEN];
    puts("Enter the string for generating permutation: ");
    fgets(str, STRING_LEN, stdin);
    int n = strlen(str);
    permute(str, 0, n-2);
}
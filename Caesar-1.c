#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

void chckarg(int count);
void rot(char* str, char* ARGV);

int main(int argc, char* argv[])
{
    chckarg(argc);
    printf("type text: \n");
    string text = GetString();
    rot(text, argv[1]);
    return 0;
}
// print error and exit if arguments are too many or too few
void chckarg(int count)
{
    if(count != 2)
    {
        printf("type a positive number as argument\n");
        exit(1);
    }
}
// execute rotation of a->z and A->Z  **in call, rot(text, argv[1])** 
void rot(char* str, char* ARGV)
{
    int k = atoi(ARGV);
    int l = strlen(str);
    for(int l2=0; l2<l; l2++)
    {
        //rotate every text[i] a-z & A-Z using circular typecasting between char str[l2] and int l2b/l2t
        if(65 <= (int) str[l2] && (int) str[l2] <= 90)
        {
            int l2b = (int) str[l2] + k;
            if(l2b > 90)
            {
                do
                {
                    l2b = l2b - 26;
                }
                while(l2b>=90);
            }
            str[l2] = (char) l2b;
            printf("%c", str[l2]);
        }
        else if(97 <= (int) str[l2] && str[l2] <= 122)
        {
            int l2t = (int) str[l2] + k;
            if(l2t > 122)
            {
                do
                {
                    l2t = l2t - 26;
                }
                while(l2t>=122);
            }
            str[l2] = (char) l2t;
            printf("%c", str[l2]);
        }
        else printf("%c", str[l2]);
    }
    printf("\n");
}

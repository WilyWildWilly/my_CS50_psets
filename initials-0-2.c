#include <stdio.h>
#include <cs50.h>
#include <string.h>

// treat arguments as name, return initials

char cap(char init);

int main(int argc, char* argv[])
{
    int a = argc;
    
    for(int i=1; i<a; i++)
    {
        for(int i2=0; i2<1; i2++)
        {
            cap(argv[i][0]);    
        }
        
    }
    printf("\n");
}

char cap(char init)
{
    if( (int) init >=97 && init <=123)
    {
        init = (int) init - 32;
        printf("%c", init);
    }
    else
    {
        printf("%c ", init);
    }
    return 'a';
}
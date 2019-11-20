#include <cs50.h>
#include <stdio.h>

      //these are prototypes for the functions at the bottom of the program
void pr_sp();
void pr_hs();

int main(void)
    // ask for, create and store a positive int as x, then create a variable integer, assign value 0, store it as y  
    // then if x is between 1 and 23 
{
    printf("insert height of the half-pyramid (1-23)\n");
    int x = get_int();
    int y = 0;
    if( x > 0 && x <=23 && y < x)
    {
//  as long as y < 0 print (x-y-1) times ' ', print (y+2) times '#', then go down 1 line, increase y by 1 and repeat
        while(y < x)
        
        {
            pr_sp(x-y-1);
            pr_hs(y+2);
            printf("\n");
            y=y+1;
            
            
        }
        
        
    }
}
//here the two functions, "prints a space" and "print a hash" are explained 
void pr_sp(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void pr_hs(int m)
{
    for(int i = 0; i < m; i++)
    {
        printf("#");
    }
}
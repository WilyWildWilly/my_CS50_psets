//program is for some reason working with all values but 4.20.

#include <stdio.h>
#include <cs50.h>

// first variable 'coin' is created global. 
int coin =0;

// four functions are introduced, each one representing the phase of subtracting a type of coin
int sub25(int n);
int sub10(int n);
int sub05(int n);
int sub01(int n);

int main(void)
{
    //the user is prompted to introduce a variable, 'cash'
    
    printf("how much is the change?\n");
    float cash = get_float();
    
    //which is immediately converted to a more precisably manageable integer, 
    cash *= 1000;
    cash *= 10;
    cash /= 10;
    
    int x;
    x = cash;
    
    
    
    if(cash <= 0)
    
    {
        return main(); // instruction to restart the main function be the number not valid
    
    }
    else
    {
        x /= 10;                              // we subtract all the coins. 'x' is set as the int from which to sub, 
        x = sub25(x);                 //and set to equal the result of the function applied to itself.
        x = sub10(x);
        x = sub05(x);
        x = sub01(x);
    }
    //we print out the result 
    printf("%i\n", coin);
}

int sub25(n)                    //functions subtract a number cyclically until possible, adding 
{                               //+1 to 'coin' at every iteration and returning 'n' eventually. 
    for(; n >= 25; coin++)      //Variable 'x' (change* 100) is put in as 'n' in function call.
    {                           // 'n' is transformed according to function, then returned and 
        n = n-25;               //used in the next function. In function call, 'x' equals the 
    }                           //resulting int 'n'.
    return n;
}
int sub10(n)
{
    for(; n >= 10; coin++)
    {
        n = n-10;
    }
    return n;
}
int sub05(n)
{
    for(; n >= 5; coin++)
    {
        n = n-5;
    }
    return n;
}
int sub01(n)
{
    for(; n >= 1; coin++)
    {
        n = n-1;
    }
    return n;
}
#include <stdio.h>
#include <cs50.h>

int main(void)

{
    printf("How long is your shower in minutes? (please express value as a positive integer)\n");
    int minutes = get_int();
    float gallons = minutes * 1.5;
    float ounces = gallons * 128;
    int bottles = ounces / 16;
    
    if (minutes <= 0)
    {
        printf("Retry:\n");
        return main();
    }
    
    else
    {
        printf("minutes: %i \nbottles: %i \n", minutes, bottles);
    }
        

}

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
//Declare var
    float dollars;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
//user input
    do
    {
        dollars = get_float("Change Owed: ");
    }
    while (dollars < 0);
//convert dollar to cent
    int cents = round(dollars * 100);
//Quarters
    for (int i = 1; (cents - 25) >=0; i++)
    {
        cents = cents - 25;
        quarters = i;
    }
//dimes
    for (int i = 1; (cents - 10) >=0; i++)
    {
        cents = cents - 10;
        dimes = i;
    }
//nickels
    for (int i = 1; (cents - 5) >=0; i++)
    {
        cents = cents - 5;
        nickels = i;
    }
//pennies
    for (int i = 1; (cents - 1) >=0; i++)
    {
        cents = cents - 1;
        pennies = i;
    }
//prepare and print results
    int minCoins = (quarters + dimes + nickels + pennies);
    printf("%i\n", minCoins);
}
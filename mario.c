#include <cs50.h>
#include <stdio.h>

//start command
int main (void)

{
//declare variable so it doesn't flip out later
    int n; //only use "int" once, when you're declaring the variable? Created an error earlier when i used it below this
    
//do while loop (input) this will determine number of rows
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n >8);
    
//nested for loop to determine composition of each row (will need 4 variables.)
    for (int i = 0; i < n; i++)
    {
        
        //left sides spaces
        for (int j = 1; j < (n-i); j++)
        {
            printf(" ");
        }
        
        //left side hashes
        for (int k = 0; k <= i; k++)
        {
                printf("#");
        }
        
        //middle gap
        printf("  ");
        
        //right side hashes
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}

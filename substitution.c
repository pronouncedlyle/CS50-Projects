#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Get key
string plainText;
string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string lower = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, string argv[])
{
    //Validate Key
    //If your program is executed without any command-line arguments or with more than one command-line argument,
    //your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.
    if (argc != 2)
    {
        printf("Invalid key \n");
        return 1;
    }
    //Check key length (26)
    if (strlen(argv[1]) != 26)
    {
        printf("Invalid key \n");
        return 1;
    }
    //Check for non-alphabetic characters
    for (int i = 0; argv[1][i] != '\0'; i++) //while (argv[1][i] != '\0') could use this instead, just gotta declare i somewhere else
    {
        if (isalpha(argv[1][i]))
        {
            i++;
        }
        else
        {
            printf("Invalid key \n");
            return 1;
        }
    }
    //Check for repeated characters (case insensitive)
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        for (int j = i + 1; argv[1][j] != '\0'; j++)
        {
            //lower case check
            if (islower(argv[1][i]))
            {
                if ((argv[1][i] == argv[1][j]) || (toupper(argv[1][i])) == argv[1][j])
                {
                    printf("Invalid key \n");
                    return 1;
                }
            }
            //upper case check
            if (isupper(argv[1][i]))
            {
                if ((argv[1][i] == argv[1][j]) || (tolower(argv[1][i])) == argv[1][j])
                {
                    printf("Invalid key \n");
                    return 1;
                }
            }
        }
    }

// Get plaintext
    plainText = get_string("plaintext:");
    printf("ciphertext: ");
// Encipher
    for (int i = 0; plainText[i] != '\0'; i++)
    {
        //lower case
        if (islower(plainText[i]))
        {
            for (int j = 0; lower[j] != '\0'; j++)
            {
                if (lower[j] == plainText[i])
                {
                    printf("%c", tolower(argv[1][j]));
                }
            }
        }
        //upper case
        else if (isupper(plainText[i]))
        {
            for (int j = 0; upper[j] != '\0'; j++)
            {
                if (upper[j] == plainText[i])
                {
                    printf("%c", toupper(argv[1][j]));
                }
            }
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
    return 0;
}
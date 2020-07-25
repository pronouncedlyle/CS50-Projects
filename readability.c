#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //variables and user input
    float letters = 0;
    float words = 0;
    float sentences = 0;
    float gradeLevel = 0;

    string sampleText = get_string("Input text sample: ");

    //count letters, words, and sentences
    for (int i = 0, n = strlen(sampleText); i < n; i++)
    {
        //get number of letters
        if ((sampleText[i] >= 'a' && sampleText[i] <= 'z') || (sampleText[i] >= 'A' && sampleText[i] <= 'Z'))
        {
            letters++;
        }

        //get number of words
        if (sampleText[i] == ' ')
        {
            words++;
        }

        if ((sampleText[i] == '.') || (sampleText[i] == '!') || (sampleText[i] == '?'))
        {
            sentences++;
        }
    }
    if (letters > 0)
    {
        words++;
    }

    //Calculations
    gradeLevel = round((0.0588 * ((letters * 100) / words)) - (0.296 * ((sentences * 100) / words)) - 15.8);

    //TEST PRINT printf("%f\n%f\n%f\n", letters, words, sentences);

    //print results
    if (gradeLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gradeLevel >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", gradeLevel);
    }
}
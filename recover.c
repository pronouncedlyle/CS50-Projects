#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //If your program is not executed with exactly one command-line argument, it should remind the user of correct usage, and main should return 1.
    if (argc != 2)
    {
        printf("Invalid argument\n");
        return 1;
    }

    //open memory card
    FILE *input = fopen(argv[1], "r");

    //If the forensic image cannot be opened for reading, your program should inform the user as much, and main should return 1.
    if (input == NULL)
    {
        printf("Invalid file\n");
        return 1;
    }
    //create buffer i guess
    unsigned char buffer[512];

    //create file for output
    FILE *output = NULL;

    //not quite sure how this one works
    char image[8];

    //counter
    int filecount = 0;

    while (fread(&buffer, 512, 1, input) == 1)
    {
        //Look for beginning of JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (filecount > 0)
            {
                fclose(output);
            }
            sprintf(image, "%03i.jpg", filecount);
            filecount++;
            output = fopen(image, "w");
            fwrite(&buffer, 512, 1, output);
        }
        else if (filecount > 0)
        {
            fwrite(&buffer, 512, 1, output);
        }
    }
    //close out files
    fclose(output);
    fclose(input);
    return 0;
}
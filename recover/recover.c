#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open the card file
    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    BYTE buffer[512];
    FILE *output = NULL;

    int jpeg_count = 0;
    char filename[8]; //xxx.jpg
    bool is_jpeg;


    // Read the image one 512-byte block at a time
    while (fread(buffer, sizeof(BYTE), 512, input) == 512)
    {
        // Check whether this block begins with a JPEG signature

           is_jpeg= buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0;

        if (is_jpeg)
        {
            // Close the previous JPEG, if one is already open
            if (output != NULL)
            {
                fclose(output);
            }

            // Create filenames
            sprintf(filename, "%03i.jpg", jpeg_count);
            jpeg_count++;

            output = fopen(filename, "w");

            if (output == NULL)
            {
                fclose(input);
                return 1;
            }
        }

        // Write the block only after the first JPEG has been found
        if (output != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, output);
        }
    }

    // Closing any file opened
    if (output != NULL)
    {
        fclose(output);
    }

    fclose(input);

    return 0;
}

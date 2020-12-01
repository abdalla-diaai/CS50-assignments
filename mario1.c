#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");

    }
    while (height <= 0 || height >= 9);

    for (int i = 0; i < height; i += 1)
    {
        // Print spaces

        for (int k = height - 1; k > i; k -= 1)
        {
            printf(" ");
        }
        // Print left hashes

        for (int j = 0; j <= i; j += 1)
        {

            printf("#");
        }
        // Print gap (two spaces)

        for (int l = 0; l < 2; l += 1)
        {
            printf(" ");
        }
        // Print right hashes

        for (int m = 0; m <= i; m += 1)
        {

            printf("#");
        }
        printf("\n");
    }
    return 0;
}
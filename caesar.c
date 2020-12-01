#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    //check the input

    int key;
    if (argc == 2)
    {

        // Iterate through the input of command line

        for (int j = 0, n = strlen(argv[1]); j < n; j++)
        {
            // Check if input of command line is digits only
            if (isdigit(argv[1][j]))
            {
                // Convert input of commant line to integer
                key = atoi(argv[1]);
            }

            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        // Confirm that the key is stored in variable key declared above

        //printf("%i\n", key);

        string message = get_string("Plaintext: ");
        int length = strlen(message);
        int cipher[length];

        for (int i = 0; i < length; i += 1)
        {
            // Check for upper case, convert using the key and returning back to letters
            if (isupper(message[i]))
            {
                cipher[i] = (((message[i] - 65) + key) % 26) + 65;;
            }

            else if(islower(message[i]))
            {
                cipher[i] = (((message[i] - 97) + key) % 26) + 97;;
            }
            else
            {
                cipher[i] = message[i];
            }
        }

        printf("ciphertext:");
        for (int j = 0; j < length; j += 1)
        {
            printf("%c", cipher[j]);
        }
        printf("\n");
    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}
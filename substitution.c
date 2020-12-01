#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //check the input

    if (argc == 2)
    {
        int count = 0;
        for (int i = 0, n = strlen(argv[1]); i < n; i += 1)
        {
            if (isalpha(argv[1][i]))
            {
                count += 1;
            }
            else
            {
                count -= 5;
            }
        }
        //printf("%i\n", count);

        if (count == 26)
        {
            string message = get_string("Plaintext: ");
            string key = argv[1];
            string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

            int length = strlen(message);
            int plain [length]; //if this array need to be used later, it need to be declared outside the loop

            for (int i = 0; i < length; i += 1)
            {
                for (int j = 0, mm = strlen(letters); j < mm; j += 1)
                {

                    //for handling different formats, numbers, punctuation, uppercase, lowercase, space
                    if (islower(message[i]))
                    {
                        plain[i] = tolower(key[j]);
                    }
                    else if (isupper(message[i]))
                    {
                        plain[i] = toupper(key[j]);
                    }
                    else
                    {
                        plain[i] = message[i];
                    }
                    
                }
            }
    //to print this string once, it needs to be outside the loop
        printf("ciphertext: ");

        for (int l = 0; l < length; l += 1)
        {
            printf("%c", plain[l]);
        }
        }

        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

    }

    else
    {
        return 1;
    }

    printf("\n");
    return 0;
    // decipher the message


}
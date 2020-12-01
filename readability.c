#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float sentences = 0;
float words = 0;
float letters = 0;
int main(void)
{
    string text = get_string("Text: ");
    for (int i = 0, n = strlen(text); i < n; i += 1)
    {
        // Assuming sentences will end with "." or "!" or "?"

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences += 1;
        }
        // Assuming words will be seperated with " "

        if (text [i] == ' ')
        {
            words += 1;
        }
        // Iterate through text and increase counter by one if it is a letter

        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    words += 1;

    float S = sentences * 100 / words;
    float L = letters * 100 / words;

    //printf("%f %f", L, S);
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //printf("%f %f %f %i\n", sentences, words, letters, index);


    // Program output based on the index

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }
    return 0;
}
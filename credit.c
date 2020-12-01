#include <cs50.h>
#include <stdio.h>
#include <string.h>


//function prototype

int counter(long number);
int card_check(long number);
int luhn_check(long number);

int main(void)
{
    long number = get_long("Enter a valid credit card number: ");
    card_check(number);
    luhn_check(number);
}



//function to count the numbers
//function entery has to be long as number input

int counter(long num)
{
    int count = 0;

    //count the number of the digits and store it in an array

    while (num > 0)
        {
            int digit = num % 10;
            num /= 10;
            count += 1;
        }

    if (count >= 13 && count <= 16 )
    {
        //printf("The length of card number is: %i\n", count);

    }

    else
    {
        //printf("Sorry innvalid number!\n");
    }
    return count;

}

//credit card check

int card_check(long num)
{
    long n1 = num;
    long n2 = num;
    long n3 = num;
    int length = counter(num);
    int total = luhn_check(num) % 10;

    while (n3)
    {
        n2 = n1;
        n1 = n3;
        n3 /= 10;
    }
    //printf("%li\n", n2);



    if (n2 / 10 == 4 &&  total == 0 && (length == 13 || length == 16) )
    {
        printf("VISA\n");
    }

    else if ((n2 == 34 || n2 == 37) && length == 15 && total % 10 == 0)
    {
        printf("AMEX\n");
    }

    else if ((n2 == 51 || n2 == 52 || n2 == 53 || n2 == 54 || n2 == 55) && length == 16 && total % 10 == 0)
    {
        printf("MASTERCARD\n");
    }
        //printf("The length of card number is: %i\n", count);

    else
    {
        printf("INVALID\n");
    }


    return 0;
}


int luhn_check(long number)
{

    int sum = 0;
    int count = counter(number);

    //printf("%i\n", count);



    int array[count];
    int odd[count/2];
    for (int i = 0; i < count; i += 1)
    {
        int digit = number % 10;
        number /= 10;
        //printf("%i\n", digit);
        array[i] = digit;
        //printf("%i\n", array[i]);
    }


    for (int j = 0; j < count; j += 1)
    {
        if (j % 2 == 0)
        {
            //printf("%i\n", array[j]);
            sum += array[j];
        }
        else if (j % 2 > 0 && 2 * array[j] >= 10)
        {
            int temp = 2* array[j];
            int temp2 = temp % 10;
            int temp3 = temp / 10;
            sum += (temp2 + temp3);
        }

        else

        {
            sum += 2 * array[j];
            //printf("%i\n", odd[j]);
        }

    }

    //printf("The credit card is valid, Luhn's sum is: %i\n", sum);
    return sum;


}
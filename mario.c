#include <cs50.h>

#include <stdio.h>

int main(void)
{
    int x;
    int y;
    do
    {
        x = get_int("Width: ");
        y = get_int("Height: ");

    } 
    while (x < 1  & y < 1);
    for (int i = 0; i < y; i +=1)
    {
        printf("i is now %i\n", i);
        for (int j = 0; j < x; j +=1)
        {
            printf("j is now %i\n", j);
            printf("#");
        }
        printf("\n");
        printf("x is now %i\n", x);
        printf("y is now %i\n", y);
        x -= 2;
    }
    
}
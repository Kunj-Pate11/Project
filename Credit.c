#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    long c_number;
    int sum = 0;
    bool multiply = false;
    int count;

    do
    {
        c_number = get_long("Number: ");
    }
    while (c_number < 1);

    long number = c_number;

    for (count = 0; number > 0; count++)
    {
        int last_digit = number % 10;
        if (multiply)
        {
            last_digit *= 2;
            sum += (last_digit % 10) + (last_digit / 10); // Adding each digit after multiplying by 2.
        }
        else
        {
            sum += last_digit; // Adding every other digit starting from the last.
        }

        multiply = !multiply; // Changing bool value each time.
        number /= 10;
    }

    sum %= 10; // Checking if the last digit is equal to 0.
    c_number /= pow(10, count - 2); // Cheacking the last two digit.

    if ((count == 13 || count == 15 || count == 16) && sum == 0)
    {
        if (c_number == 34 || c_number == 37)
        {
            printf("AMEX\n");
        }
        else if (c_number >= 51 && c_number <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (c_number / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
} 
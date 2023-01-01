#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    printf("\n");
    printf("enter credit card number: ");
    long n;
    scanf("%ld", &n);
    long x = n;
    int chksm;

    // finding length of the card number
    int len = 0;
    do
    {
        x /= 10;
        len++;
    }
    while (x != 0);

    // finding half of length for later
    int half = round(len/2);

    // if else statement to stop user from putting in card numbers with wrong number of digits
    if (len == 13 || len == 15 || len == 16)
    {
        int part1 = 0;
        int part2;
        int card[len];

        // converting given long with card number into an array, so we can index into it and pick out the numbers we want for our checksum.
//        printf("card array: ");
        for (int i = 0; i < len; i++)
        {
            card[i] = ((int)(n % 10));
            n = n / (long)10;
//            printf("%i", card[i]);
        }
//        printf("\n");

        //adding first part of checksum to an array and printing it to check, needs further work before the final step of adding it with part 2
        char card1[half];
//        printf("part 1 array: ");
        for (int i = 0, j = 1; j < len; j = j + 2, i++)
        {
            card1[i] = card[j] + '0';
//            printf("%c", card1[i]);
        }
//        printf("\n");

        //moving second part of checksum to an array and printing it to check
        int card2[half];
//        printf("part 2 array: ");
        for (int i = 0, j = 0; j < len; j = j + 2, i++)
        {
            card2[i] = card[j];
//            printf("%i", card2[i]);
        }
//        printf("\n");

        //adding second part of the checksum together
        for (int i = 0; i < half; i++)
        {
            part2 = part2 + card2[i];
        }
//        printf("part 2 total: %i\n", part2);

        for (int i = 0; i < len; i++)
        {
            //printf("%c", card1[i]);
        }
        //printf("\n");


        int p1;
        p1 = atoi(card1);
        p1 = p1*2;

        int p1x[half];
//        printf("part 1 multiplied array: ");
        for (int i = 0; i < half; i++)
        {
            p1x[i] = p1 % 10;
            p1 = p1 / 10;
//            printf("%i", p1x[i]);
        }
//        printf("\n");

        //adding second part of the checksum together
        for (int i = 0; i < half; i++)
        {
            part1 = part1 + p1x[i];
        }
//        printf("part 1 total: %i\n", part1);

        // adding 2 pars of checksum together
        chksm = part1 + part2;
//        printf("checksum: %i", chksm);

        // checking if the sum is 0 according to Lunh's algorithm
        chksm = chksm % 10;

        printf("\nThe credit card %i%i%i%i********** is ", card[len - 1], card[len - 2], card[len - 3],
               card[len - 4]);

        int recognized = 0;

        // checking the checksum, and if found valid printing the type of card they hold
        if (chksm == 0) {
            if (card[len - 1] == 4) {
                printf("a Visa and it is valid.\n");
                recognized = 1;
            }
            if (card[len - 1] == 3 && card[len - 2] == 4) {
                printf("an Amex and it is valid.\n");
                recognized = 1;
            }
            if (card[len - 1] == 3 && card[len - 2] == 7) {
                printf("an Amex and it is valid.\n");
                recognized = 1;
            }
            int mc_check = 1;
            for (int i = 1; i < 6; i++) {
                if (card[len - 1] == 5 && card[len - 2] == i) {
                    mc_check = 0;
                }
            }
            if (mc_check == 0) {
                printf("a Mastercard and it is valid.\n");
                recognized = 1;
            }
            if (recognized == 0) {
                printf("a valid card but is not recognized. This program can only recognize Visa, Mastercard, and American Express cards.\n");
            }
        }
        else
        {
            printf("invalid. Make sure you have input the correct number. Please try again.\n");
        }
    }
    else
    {
        printf("Invalid number of digits in card number.\n");
    }
}
#include <stdio.h>
/**
 * main - finds and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2
 * followed by a new line
 * Return: ALways 0 (Succes
 */
void fibonacciNumbers() {
    int num1 = 1, num2 = 2;
    int count = 2; // already have the first two Fibonacci numbers

    printf("%d, %d", num1, num2); // print the first two numbers

    while (count < 98) {
        int nextNum = num1 + num2;

        printf(", %d", nextNum);

        num1 = num2;
        num2 = nextNum;

        count++;
    }

    printf("\n");
}

int main() {
    fibonacciNumbers();

    return 0;
}


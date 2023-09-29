#include <stdio.h>

int main(void)
{
    int x = 0;
    do
    {
        printf("hello world \n");
        x = x + 1; // Corrected the assignment statement
    }
    while (x < 500);
}

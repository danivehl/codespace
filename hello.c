#include <stdio.h>
#include <unistd.h> // Include the header for the sleep function

int main(void)
{
    int x;
    x = 0;
    do
    {
        printf("hello world \n");
        x = x + 1;
        sleep(1); // Add a one-second delay
    }
    while (x < 5);
}

#include <stdio.h>
#include "ft_printf.h"


int main(void)
{
    int original;
    int yours;

    printf("\n--- TEST 1: Normal string ---\n");
    original = printf("Hello %s!\n", "World");
    fflush(stdout);
    yours = ft_printf("Hello %s!\n", "World");
    printf("Return: original = %d, yours = %d\n", original, yours);

    printf("\n--- TEST 2: Empty string ---\n");
    original = printf("[%s]\n", "");
    fflush(stdout);
    yours = ft_printf("[%s]\n", "");
    printf("Return: original = %d, yours = %d\n", original, yours);

    printf("\n--- TEST 3: NULL string ---\n");
    original = printf("[%s]\n", (char *)NULL);
    fflush(stdout);
    yours = ft_printf("[%s]\n", (char *)NULL);
    printf("Return: original = %d, yours = %d\n", original, yours);

    printf("\n--- TEST 4: Character ---\n");
    original = printf("Character: %c\n", 'A');
    fflush(stdout);
    yours = ft_printf("Character: %c\n", 'A');
    printf("Return: original = %d, yours = %d\n", original, yours);

    printf("\n--- TEST 5: Percent ---\n");
    original = printf("100%%\n");
    fflush(stdout);
    yours = ft_printf("100%%\n");
    printf("Return: original = %d, yours = %d\n", original, yours);

    return (0);
}

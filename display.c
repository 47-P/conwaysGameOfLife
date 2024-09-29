#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    for (int i = 0; i < 10; i++) {
    int random_bit = rand() % 2;
    printf("%d ", random_bit);
}

}
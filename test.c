#include "stdio.h"

int main(void)
{
    static char a = 0;
    a = 2;
    a = 1;
    printf("%c", a);
}

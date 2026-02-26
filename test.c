#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *func1(void *arg)
{
    char *str = arg;
    int i = 0;
    while(str[i])
    {
        printf("%c", str[i]);
        i++;
    }
    pthread_exit(arg);
}

int main(void)
{
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, func1, "2 phrase completement sensé");
    pthread_create(&t2 , NULL, func1, "grosksosdetounsi");

    int i, j;
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return(0);
}

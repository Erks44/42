#include <stdlib.h>

char    *ft_substr(char const *str, unsigned int start, size_t len)
{
    char *s;
    int i = start;
    int j = 0;
    int y = 0;
    int a = 0;

    if (!str)
        return(NULL);
    while(str[y])
        y++;
    if (start >  y)
    {
        s = malloc(1);
        s[0] = '\0';
        return(s);
    }
    if(y < len)
        s = malloc((y - start + 1)*(sizeof(char)));
    else
        s = malloc((len + 1) * (sizeof(char)));
    if (!s)
        return(NULL);
    while(str[i] && j < len)
    {
        s[j] = str[i];
        i++;
        j++;
    }
    s[j] = '\0';
    return(s);
}

#include <stdio.h>
int main()
{
    printf("%s\n", ft_substr("abcdef", 5, 10));
    return(0);
}

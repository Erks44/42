#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <unistd.h>

char *ft_strdup(char *str)
{
    char *s;
    int i = 0;

    while(str[i])
        i++;
    s = malloc((i + 1) * sizeof(char));
    if (!s)
        return (NULL);
    i = 0;
    while(str[i])
    {
        s[i] = str[i];
        i++;
    }
    s[i] = '\0';
    return(s);
}

char *get_next(int fd)
{
    static int buffer_read = 0;
    static int buffer_pos = 0;
    static char buffer[BUFFER_SIZE];
    char line[10000];
    int i = 0;
    
    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);

    while(1)
    {
        if (buffer_pos >= buffer_read)
        {
            buffer_read = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            if (buffer_read <= 0)
                break;
        }
        line[i++] == buffer[buffer_pos++];
        if (line[i - 1] == '\n')
            break;
    }
    if (i == 0)
        return(0);
    line[i] = '\0';
    return(ft_strdup(line))
}

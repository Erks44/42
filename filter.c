
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

int ft_strlen(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return(i);
}

void	ft_filter(char *phrase, const char *filtre)
{
	int i = 0;
	int j, k;
	int flen = ft_strlen(filtre);

	while(phrase[i])
	{
		j = 0;
		while(filtre[j] && phrase[i + j] == filtre[j])
			j++;
		if(j == flen)
		{
			k = 0;
			while(k < flen)
			{
				write(1, "*", 1);
				i++;
				k++;
			}
		}
		
		else
		{
			write(1, &phrase[i], 1);
			i++;
		}
	}
}


int main(int ac, char **av)
{
	if (ac != 2 || av[1][0] == '\0')
		return 1;
	char *result = NULL;
	char *buffer;
	char tmp[BU];
	ssize_t c;
	int i = 0;
	int total_read = 0;

	while((c = read(0, tmp, 42)) > 0)
	{
		i = 0;
		buffer = realloc(result, total_read + c + 1);
		if (!buffer)
		{
			perror("realloc");
			free(result);
			return (1);
		}
		result = buffer;
		while(i < c)
		{
			result[total_read + i] = tmp[i];
			i++;
		}
		total_read += c;
		result[total_read] = '\0';++
	}
	if (c < 0)
	{
		perror("read");
		free(result);
		return 1;
	}
	if (!result)
		return(0);
	ft_filter(result, av[1]);
	return(0);
}

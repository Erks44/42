#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

int	ft_strlen(const char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

void	filter(char *phrase, const char *filtre)
{
	int i = 0;
	int j = 0;
	int k;
	int flen = ft_strlen(filtre);

	while(phrase[i])
	{
		j = 0;
		while(filtre[j] && phrase[i + j] == filtre[j])
			j++;
		if(j == flen)
		{
			k = 0;
			while(k < j)
			{
				write(1, "*", 1);
				k++;
				i++;
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
	ssize_t c;
	int i = 0;
	char buffer[BUFFER_SIZE];
	char *result = NULL;
	char *op;
	int total_read = 0;

	if(ac != 2)
		return(1);

	while((c = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		i = 0;
		op = realloc(result, total_read + c + 1);
		if(!op)
		{
			free(result);
			perror("realloc");
			return(1);
		}
		result = op;
		while(i < c)
		{
			result[total_read + i] = buffer[i];
			i++;
		}
		total_read += c;
		result[total_read] = '\0';
	}
	result[total_read] = '\0';
	if(c < 0)
	{
		perror("read");
		return(1);
	}
	filter(result, av[1]);
	free(result);
	return(0);
}


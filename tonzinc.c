#include <unistd.h>
#include <string.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

int main(int ac, char **av)
{
	char	buf[1025];
	ssize_t n;
	char	*s;
	size_t	len;
	char	*p;
	char	*pos;
	size_t	i;

	if (ac != 2 || av[1][0] == '\0')
		return(1);
	s = av[1];
	len = ft_strlen(s);
	while((n = read(0, buf, 1024)) > 0)
	{
		buf[n] = '\0';
		p = buf;
		while((pos = strstr(p, s)) != NULL)
		{
			write(1, p, pos - p);
			i = 0;
			while(i < len)
			{
				write(1, "*", 1);
				i++;
			}
			p = pos + len;
		}
		write(1, p, strlen(p));
	}
}

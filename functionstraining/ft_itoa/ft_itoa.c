#include <stdlib.h>

int ft_intlen(int nbr)
{
	int i = 0;
	if (nbr == 0)
		return(1);
	else if (nbr < 0)
		i++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return(i);
}

char	*ft_itoa(int nbr)
{
	char *str;
	int len = ft_intlen(nbr);
	int i = len;
	long nb = nbr;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return(NULL);
	if (nb == 0)
		return("0");
	str[i] = '\0';
	i--;
	if(nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return(str);
}

#include <stdio.h>

/*int main(void)
{
	printf("%s\n", ft_itoa(-0));
	return(0);
}*/
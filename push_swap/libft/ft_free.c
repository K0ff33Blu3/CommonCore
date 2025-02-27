#include "libft.h"

void	ft_free(char **s, int i)
{
	if (i < 0)
	{
		i = 0;
		ft_putstr_fd("array intero", 1);
		ft_putchar_fd('\n', 1);
		ft_putchar_fd(s[i][0], 1);
		//ft_putstr_fd(*s, 1);
		//printf("%s\n", s[i]);
		while (s[i][0] != 0)
		{
			i++;
		}
	}
	ft_putnbr_fd(i, 1);
	ft_putchar_fd('\n', 1);
	while (i-- >= 0)
		free(s[i]);
	free(s);
}

int main()
{
	char	**str;
	int	n_str;
	int	i;

	n_str = 1;
	str = (char **)malloc(sizeof(char *) * (n_str + 1));
	if (!str)
		return 1;	
	ft_putstr_fd("qualcosa\n", 1);
	str[n_str] = NULL;
	while (i < n_str)
	{
		str[i] = (char *)malloc(5);
		if (!str[i])
		{
			perror("errore di allocazione");
			ft_free(str, i);
			return 1;
		}
		str[i] = "ciao";
		i++;
	}
	ft_putstr_fd("qualcosa\n", 1);
	ft_free(str, -1);
	ft_putstr_fd("qualcosa\n", 1);
	return 0;
}
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char *a;
	char *b;
	int i  = 1;
	a = malloc(ac);
	while (i < ac)
	{
		a[i] = av[i][0];
		printf(" a est : %s", a[i]);
		i++;
	}
	printf(" ordre est: %d", is_sorted(a));
}

int	is_sorted(char *a)
{
	int i;
	i = 0;
	while(i < ft_strlen(a))
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void 	push(char *a, char *b)
{
	char *temp_a;
	char *temp_b;
	int i = 1;

	temp_a = malloc(ft_strlen(a));
	temp_b = malloc(ft_strlen(b) + 2);
	temp_b[i] = a[0];
	while(i < t_strlen(b))
	{
		temp_b[i] = b[i];
		i++;
	}
	temp_b[i + 1] = '\0';
	while(i < t_strlen(a))
	{
		temp_a[i] = a[i];
		i++;
	}
	temp_a[i] = '\0';
	copy_char(a, temp_a);
	copy_char(b, temp_b);
	free(temp_a);
	free(temp_b);
}

char *copy_char(char *str, char *temp)
{
	str = NULL;
	str = malloc(ft_strlen(tepm));
	while(i < t_strlen(temp))
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*rev_rotate(char *a)
{
	char *temp;
	int i = 1;

	temp = malloc(ft_strlen(a));
	temp[0] = a[ft_strlen(a) - 1];
	while(i < ft_strlen(a))
	{
		tepm[i] = a[i - 1];
		i++;
	}
	temp[i] = '\0';
	a = copy_char(a, temp);
	free(temp);
	return (a);
}

char	*rotate(char *a)
{
	char *temp;
	int i = 1;

	temp = malloc(ft_strlen(a));
	temp[ft_strlen(a) - 1] = a[0];
	while(i < ft_strlen(a))
	{
		tepm[i -1] = a[i];
		i++;
	}
	temp[i] = '\0';
	a = copy_char(a, temp);
	free(temp);
	return (a);
}

void	rr_rotate(char *a, char *b)
{
	rotate(a);
	rotate(b);
}

void	rr_rev_rotate(char *a, char *b)
{
	rev_rotate(a);
	rev_rotate(b);
}

char	*swap(char *a)
{
	char	temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	return (a);
}

void	ss_swap(char *a, char *b)
{
	swap(a);
	swap(b);
}  

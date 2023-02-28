/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:48:49 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/28 15:52:50 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
	{
		i++;
	}
	if (s1[i] - s2[i] < -127)
		return (-(s1[i] - s2[i]));
	return (s1[i] - s2[i]);
}

char	*ft_strjoin_1(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && s2 && *s2)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

int	ft_putnbr(int n, int fd)
{
	long int	nb;

	nb = (long int)n;
	if (nb == -2147483648)
	{
		ft_putchar_fd ('-', fd);
		ft_putchar_fd ('2', fd);
		nb = 147483648;
	}	
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar_fd (nb + 48, fd);
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		ft_putnbr (nb * (-1), fd);
	}
	if (nb >= 10)
	{
		ft_putnbr (nb / 10, fd);
		ft_putnbr (nb % 10, fd);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr (n, fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

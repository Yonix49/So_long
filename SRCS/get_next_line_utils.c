/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:18:57 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/03/01 11:53:47 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen1(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_verification(int start, size_t len, char *s)
{
	size_t	x;

	if ((size_t)(start + len) > ft_strlen1(s))
		x = ft_strlen1(s) - start + 1;
	else
		x = len + 1;
	return (x);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;
	size_t	x;

	if (!s)
		return (NULL);
	i = 0;
	x = ft_verification(start, len, s);
	if (s && start >= ft_strlen1(s))
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
		return (s1);
	}
	s1 = malloc(sizeof(char) * (x));
	if (!s1)
		return (NULL);
	while (i < len && (char)s[i + start])
	{
		s1[i] = (char)s[i + start];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
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
	str = (char *)malloc(sizeof(char) * (ft_strlen1(s1) + ft_strlen1(s2) + 1));
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
	return (str);
}

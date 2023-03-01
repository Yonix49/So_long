/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:38:52 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/03/01 11:54:52 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_file_not_empty(int fd)
{
	char	c;

	if (read(fd, &c, 1) < 1)
		return (0);
	return (1);
}

int	verif_open(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd <= 0 )
	{
		close(fd);
		write(2, "Fichier inexistant\n", 18);
		return (0);
	}
	if (check_file_not_empty(fd) == 0)
	{
		close(fd);
		write(2, "Map Vide Error\n", 16);
		return (0);
	}
	close(fd);
	return (1);
}

int	verif_namearg(int argc, char **argv)
{
	char	*filename;
	size_t	len;

	if (argc < 2 || (argc > 2))
	{
		write(2, "Nb Argument non valide\n",24);
		return (0);
	}
	filename = argv[1];
	len = ft_strlen(filename);
	if (len < 4 || ft_strcmp(filename + len - 4, ".ber") != 0)
	{
		write(2, ".ber non valide\n", 17);
		return (0);
	}
	return (1);
}

void	ft_free_all(t_data *img)
{
	unsigned int	i;

	i = 0;
	while (img->map[i])
	{
		free(img->map[i]);
		i++;
	}
	free(img->map);
	free(img);
}

void	ft_free(char **map)
{
	int i;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

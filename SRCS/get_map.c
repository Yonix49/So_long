/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:15:01 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/28 19:00:30 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
char	**get_map(t_data *img, char **argv)
{
	int		fd;
	char	*line;
	char	*tmp;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
		{
			free(tmp);
			break ;
		}
		line = ft_strjoin_1(line, tmp);
		free(tmp);
	}
	close(fd);
	if ((is_char_sett(line)) == 0)
	{
		free(line);
		return (NULL);
	}
	img->map = ft_split(line, '\n');
	free(line);
	return (img->map);
}


char	**copy_map(t_data *img)
{
	char	**copy;
	int		i;

	img->cord = get_map_ligne(img->map, img->cord);
	printf("ligne = img.cord == %i            ", img->cord.lig);
		copy = malloc(sizeof(char *) * (img->cord.lig + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (img->map[i])
	{
		copy[i] = ft_strdup(img->map[i]);
		i++;
	}
	copy[i] = NULL;// Si jenleve je regle invalid read size mais 
	return (copy);
}
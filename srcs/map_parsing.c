/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/13 14:14:25 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *file)
{
	char	*line;
	int		fd;
	int		count;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("ERROR: Map file opening failed!\n");
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	return (count);
}

static char	*set_line_data(char *map, char *line)
{
	int	x;

	x = 0;
	while (x < ft_strlen(line))
	{
		if (line[x] != '\n')
			map[x] = line[x];
		else
			break ;
		x++;
	}
	map[x] = '\0';
	return (map);
}

static char	**set_map_data(char **map, char *file, int nb_lines)
{
	char	*line;
	int		fd;
	int		y;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("ERROR: Map file opening failed!\n");
	y = 0;
	while (y < nb_lines)
	{
		line = get_next_line(fd);
		map[y] = (char *)malloc(sizeof(char) * ft_strlen(line));
		if (!map[y])
			exit_error("ERROR: Malloc failed!\n");
		map[y] = set_line_data(map[y], line);
		free(line);
		y++;
	}
	map[y] = NULL;
	close(fd);
	return (map);
}

char	**parse_map(char *file)
{
	char	**map;
	int		nb_lines;

	nb_lines = count_lines(file);
	if (!nb_lines)
		exit_error("ERROR: Map file is empty!\n");
	map = (char **)malloc(sizeof(char *) * (nb_lines + 1));
	if (!map)
		exit_error("ERROR: Malloc failed!\n");
	map = set_map_data(map, file, nb_lines);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:36:57 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/14 15:30:43 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	rectangular_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (ft_strlen(map[y]) != ft_strlen(map[0]))
			return (0);
		y++;
	}
	return (1);
}

static int	closed_map(char **map)
{
	int	x;
	int y;

	x = 0;
	while (x < ft_strlen(map[0]))
	{
		if (map[0][x] != '1' || map[get_map_size(map) - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < get_map_size(map))
	{
		if (map[y][0] != '1' || map[y][ft_strlen(map[0]) - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	valid_items(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'C'
				&& map[y][x] != 'E' && map[y][x] != 'P')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	check_valid_map(char **map)
{
	if (!rectangular_map(map))
		exit_free_error("ERROR: Map is not rectangular!\n", map);
	if (!closed_map(map))
		exit_free_error("ERROR: Map is not closed by walls!\n", map);
	if (!valid_items(map))
		exit_free_error("ERROR: Map contains invalid items!\n", map);
}

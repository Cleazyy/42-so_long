/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:36:57 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/15 12:05:32 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	int	y;

	x = 0;
	while (map[0][x])
	{
		if (map[0][x] != '1' || map[get_map_size(map) - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (map[y])
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
				&& map[y][x] != 'E' && map[y][x] != 'P' && map[y][x] != 'M')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	count_items(char **map, char item)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == item)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	check_valid_map(char **map)
{
	if (!rectangular_map(map))
		exit_free_error("ERROR: Map is not rectangular!\n", map);
	else if (!closed_map(map))
		exit_free_error("ERROR: Map is not closed by walls!\n", map);
	else if (!valid_items(map))
		exit_free_error("ERROR: Map contains invalid items!\n", map);
	else if (count_items(map, 'C') < 1)
		exit_free_error("ERROR: Map does not have at least one item!\n", map);
	else if (count_items(map, 'E') < 1)
		exit_free_error("ERROR: Map does not have at least one exit!\n", map);
	else if (count_items(map, 'P') != 1)
		exit_free_error("ERROR: Map does not exactly have a spawn!\n", map);
}

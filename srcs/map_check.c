/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:36:57 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/14 14:11:14 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	rectangular_map(char **map)
{
	int	y;

	y = 0;
	while (y < get_map_size(map))
	{
		if (ft_strlen(map[y]) != ft_strlen(map[0]))
			return (0);
		y++;
	}
	return (1);
}

void	check_valid_map(char **map)
{
	if (!rectangular_map(map))
		exit_free_error("ERROR: Map is not rectangular!\n", map);
}

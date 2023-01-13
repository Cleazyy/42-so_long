/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:31 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/13 14:12:04 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_size(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int	get_map_height(char **map)
{
	int	size;

	size = get_map_size(map) * 32;
	return (size);
}

int	get_map_width(char **map)
{
	int	size;

	size = ft_strlen(map[0]) * 32;
	return (size);
}

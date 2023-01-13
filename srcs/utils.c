/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/13 14:14:36 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '\n' || str[j] == '\0')
			return (j);
		j++;
	}
	return (j);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	exit(EXIT_SUCCESS);
}

static void	ft_putstr_fd(char *str, int fd)
{
	int	len;

	if (!str || !fd)
		return ;
	len = ft_strlen(str);
	write(fd, str, len);
}

int	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (0);
}

void	exit_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

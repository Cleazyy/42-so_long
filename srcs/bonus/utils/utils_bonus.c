/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/15 11:03:18 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_putstr_fd(char *str, int fd)
{
	int	len;

	if (!str || !fd)
		return ;
	len = ft_strlen(str);
	write(fd, str, len);
}

int	ft_strlen(char *str)
{
	int	j;

	j = 0;
	while (str[j])
		j++;
	return (j);
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

void	exit_free_error(char *str, char **map)
{
	free_map(map);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

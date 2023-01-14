/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/14 10:19:31 by fluchten         ###   ########.fr       */
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
}

void	exit_game(t_mlx *mlx, char *str)
{
	int	i;

	i = 0;
	while (i < NB_SPRITES)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.mat[i]);
		i++;
	}
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free_map(mlx->map);
	ft_printf("%s Total of moves : %d.\n", str, mlx->player.moves);
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

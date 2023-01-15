/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/15 11:03:00 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	ft_printf("%s Total of moves : %d\n", str, mlx->player.moves);
	exit(EXIT_SUCCESS);
}

int	close_window(t_mlx *mlx)
{
	exit_game(mlx, "Game closed.");
	exit(EXIT_SUCCESS);
}

int	key_pressed(int key, t_mlx *mlx)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move_player(key, mlx);
	else if (key == CLOSE)
		close_window(mlx);
	return (0);
}

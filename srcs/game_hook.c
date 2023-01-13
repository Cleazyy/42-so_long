/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/13 14:14:17 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closewindow(t_mlx *mlx)
{
	ft_printf("Game closed. Number of moves : %d\n", mlx->player.moves);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free_map(mlx->map);
	exit(EXIT_SUCCESS);
}

int	key_pressed(int key, t_mlx *mlx)
{
	if ((key >= 0 && key <= 2) || key == 13)
		move_player(key, mlx);
	else if (key == 53)
		closewindow(mlx);
	return (0);
}

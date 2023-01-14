/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/14 10:23:25 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_set_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/15 11:42:29 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_floor_sprite(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mat[0],
		x * SPRITES_SIZE, y * SPRITES_SIZE);
}

void	set_wall_sprite(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mat[1],
		x * SPRITES_SIZE, y * SPRITES_SIZE);
}

void	set_collectible_sprite(t_mlx *mlx, int x, int y)
{
	mlx->player.items++;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mat[0],
		x * SPRITES_SIZE, y * SPRITES_SIZE);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mat[2],
		x * SPRITES_SIZE, y * SPRITES_SIZE);
}

void	set_exit_closed_sprite(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mat[3],
		x * SPRITES_SIZE, y * SPRITES_SIZE);
}

void	set_player_sprite(t_mlx *mlx, int x, int y)
{
	mlx->player.moves = 0;
	mlx->player.x = x;
	mlx->player.y = y;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mat[0],
		x * SPRITES_SIZE, y * SPRITES_SIZE);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mat[4],
		x * SPRITES_SIZE, y * SPRITES_SIZE);
}

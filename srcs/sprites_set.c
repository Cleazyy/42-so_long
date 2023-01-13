/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/13 17:09:17 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_wall(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.wall,
		x * 32, y * 32);
}

void	set_floor(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.floor,
		x * 32, y * 32);
}

void	set_player(t_mlx *mlx, int x, int y)
{
	mlx->player.moves = 0;
	mlx->player.x = x;
	mlx->player.y = y;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.floor,
		x * 32, y * 32);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.player,
		x * 32, y * 32);
}

void	set_collectible(t_mlx *mlx, int x, int y)
{
	mlx->player.items++;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.floor,
		x * 32, y * 32);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.collectible,
		x * 32, y * 32);
}

void	set_exit(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.exit,
		x * 32, y * 32);
}

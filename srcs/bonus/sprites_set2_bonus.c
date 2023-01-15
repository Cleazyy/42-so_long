/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_set2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:13:11 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/15 12:04:52 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_exit_opened_sprite(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->img.mat[3] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			EXIT_OPENED_PATH, &mlx->img.w, &mlx->img.h);
	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->img.mat[3], x * SPRITES_SIZE, y * SPRITES_SIZE);
			x++;
		}
		y++;
	}
}

void	set_enemy_sprite(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mat[5],
		x * SPRITES_SIZE, y * SPRITES_SIZE);
}

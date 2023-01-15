/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/14 17:40:39 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_mlx *mlx)
{
	mlx->img.mat[0] = mlx_xpm_file_to_image(mlx->mlx_ptr, FLOOR_PATH,
			&mlx->img.w, &mlx->img.h);
	mlx->img.mat[1] = mlx_xpm_file_to_image(mlx->mlx_ptr, WALL_PATH,
			&mlx->img.w, &mlx->img.h);
	mlx->img.mat[2] = mlx_xpm_file_to_image(mlx->mlx_ptr, COLLECTIBLE_PATH,
			&mlx->img.w, &mlx->img.h);
	mlx->img.mat[3] = mlx_xpm_file_to_image(mlx->mlx_ptr, EXIT_CLOSED_PATH,
			&mlx->img.w, &mlx->img.h);
	mlx->img.mat[4] = mlx_xpm_file_to_image(mlx->mlx_ptr, PLAYER_DOWN_PATH,
			&mlx->img.w, &mlx->img.h);
}

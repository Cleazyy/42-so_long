/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/13 14:35:07 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_mlx *mlx)
{
	int	width;
	int	height;

	mlx->img.wall = mlx_xpm_file_to_image(mlx->mlx_ptr, WALL_PATH,
			&width, &height);
	mlx->img.floor = mlx_xpm_file_to_image(mlx->mlx_ptr, FLOOR_PATH,
			&width, &height);
	mlx->img.collectible = mlx_xpm_file_to_image(mlx->mlx_ptr, ITEM_PATH,
			&width, &height);
	mlx->img.exit = mlx_xpm_file_to_image(mlx->mlx_ptr, EXIT_PATH,
			&width, &height);
	mlx->img.exit_open = mlx_xpm_file_to_image(mlx->mlx_ptr, EXIT_OPEN_PATH,
			&width, &height);
	mlx->img.player = mlx_xpm_file_to_image(mlx->mlx_ptr, PLAYER_DOWN_PATH,
			&width, &height);
}

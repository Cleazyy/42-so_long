/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/14 10:18:41 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_exit(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->img.mat[4], x * 32, y * 32);
			x++;
		}
		y++;
	}
}

static void	move_to_new_pos(t_mlx *mlx, int new_posx, int new_posy)
{
	int		posx;
	int		posy;

	posx = mlx->player.x;
	posy = mlx->player.y;
	if (mlx->map[posy][posx] == '0' || mlx->map[posy][posx] == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mat[0],
			posx * 32, posy * 32);
	else if (mlx->map[posy][posx] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mat[3],
			posx * 32, posy * 32);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mat[5],
		new_posx * 32, new_posy * 32);
	mlx->player.y = new_posy;
	mlx->player.x = new_posx;
}

static void	check_next_pos(t_mlx *mlx, int new_posx, int new_posy)
{
	if (mlx->map[new_posy][new_posx] == '1')
		move_to_new_pos(mlx, mlx->player.x, mlx->player.y);
	else
	{
		mlx->player.moves++;
		ft_printf("Number of moves : %d\n", mlx->player.moves);
		move_to_new_pos(mlx, new_posx, new_posy);
		if (mlx->map[new_posy][new_posx] == 'C')
		{
			mlx->player.items--;
			if (mlx->player.items == 0)
				open_exit(mlx);
			mlx->map[new_posy][new_posx] = '0';
		}
		else if (mlx->map[new_posy][new_posx] == 'E')
		{
			if (mlx->player.items == 0)	
				exit_game(mlx, "You have won!");
			else
				ft_printf("There are still %d items!\n", mlx->player.items);
		}
	}
}

void	move_player(int key, t_mlx *mlx)
{
	if (key == UP)
	{
		mlx->img.mat[5] = mlx_xpm_file_to_image(mlx->mlx_ptr,
				PLAYER_UP_PATH, &mlx->img.w, &mlx->img.h);
		check_next_pos(mlx, mlx->player.x, mlx->player.y - 1);
	}
	else if (key == DOWN)
	{
		mlx->img.mat[5] = mlx_xpm_file_to_image(mlx->mlx_ptr,
				PLAYER_DOWN_PATH, &mlx->img.w, &mlx->img.h);
		check_next_pos(mlx, mlx->player.x, mlx->player.y + 1);
	}
	else if (key == LEFT)
	{
		mlx->img.mat[5] = mlx_xpm_file_to_image(mlx->mlx_ptr,
				PLAYER_LEFT_PATH, &mlx->img.w, &mlx->img.h);
		check_next_pos(mlx, mlx->player.x - 1, mlx->player.y);
	}
	else if (key == RIGHT)
	{
		mlx->img.mat[5] = mlx_xpm_file_to_image(mlx->mlx_ptr,
				PLAYER_RIGHT_PATH, &mlx->img.w, &mlx->img.h);
		check_next_pos(mlx, mlx->player.x + 1, mlx->player.y);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/13 14:14:15 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_to_new_pos(t_mlx *mlx, int new_posx, int new_posy)
{
	int		posx;
	int		posy;

	posx = mlx->player.posx;
	posy = mlx->player.posy;
	if (mlx->map[posy][posx] == '0' || mlx->map[posy][posx] == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.floor,
			posx * 32, posy * 32);
	else if (mlx->map[posy][posx] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.exit,
			posx * 32, posy * 32);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.player,
		new_posx * 32, new_posy * 32);
	mlx->player.posy = new_posy;
	mlx->player.posx = new_posx;
}

static void	check_next_pos(t_mlx *mlx, int new_posx, int new_posy)
{
	if (mlx->map[new_posy][new_posx] == '1')
		move_to_new_pos(mlx, mlx->player.posx, mlx->player.posy);
	else
	{
		mlx->player.moves++;
		ft_printf("Number of moves : %d\n", mlx->player.moves);
		move_to_new_pos(mlx, new_posx, new_posy);
		if (mlx->map[new_posy][new_posx] == 'C')
		{
			mlx->player.items--;
			mlx->map[new_posy][new_posx] = '0';
		}
		else if (mlx->map[new_posy][new_posx] == 'E')
		{
			if (mlx->player.items == 0)
			{		
				ft_printf("You have won!\n");
				free_map(mlx->map);
			}
			else
				ft_printf("There are still %d items!\n", mlx->player.items);
		}
	}
}

void	move_player(int key, t_mlx *mlx)
{
	if (key == 13)
	{
		mlx->img.player = mlx_xpm_file_to_image(mlx->mlx_ptr,
				PLAYER_UP_PATH, &mlx->player.width, &mlx->player.height);
		check_next_pos(mlx, mlx->player.posx, mlx->player.posy - 1);
	}
	else if (key == 1)
	{
		mlx->img.player = mlx_xpm_file_to_image(mlx->mlx_ptr,
				PLAYER_DOWN_PATH, &mlx->player.width, &mlx->player.height);
		check_next_pos(mlx, mlx->player.posx, mlx->player.posy + 1);
	}
	else if (key == 0)
	{
		mlx->img.player = mlx_xpm_file_to_image(mlx->mlx_ptr,
				PLAYER_LEFT_PATH, &mlx->player.width, &mlx->player.height);
		check_next_pos(mlx, mlx->player.posx - 1, mlx->player.posy);
	}
	else if (key == 2)
	{
		mlx->img.player = mlx_xpm_file_to_image(mlx->mlx_ptr,
				PLAYER_RIGHT_PATH, &mlx->player.width, &mlx->player.height);
		check_next_pos(mlx, mlx->player.posx + 1, mlx->player.posy);
	}
}

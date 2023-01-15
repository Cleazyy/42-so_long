/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/15 11:03:01 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (!check_args(ac, av))
		exit(EXIT_FAILURE);
	mlx.map = parse_map(av[1]);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, get_map_width(mlx.map),
			get_map_height(mlx.map), "so_long");
	init_map(mlx.map, &mlx);
	mlx_key_hook(mlx.win_ptr, key_pressed, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}

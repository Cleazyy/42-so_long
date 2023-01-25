/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/15 11:02:55 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_args(int ac, char **av)
{
	char	*str;
	int		len;

	if (ac != 2)
		return (print_error("ERROR: Wrong number of arguments!\n"));
	str = av[1];
	len = ft_strlen(str);
	if (len < 5 || str[len - 4] != '.' || str[len - 3] != 'b'
		|| str[len - 2] != 'e' || str[len - 1] != 'r')
		return (print_error("ERROR: Invalid map format!\n"));
	return (1);
}

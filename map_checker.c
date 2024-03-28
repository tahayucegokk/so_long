/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:35:16 by muyucego          #+#    #+#             */
/*   Updated: 2024/03/29 02:22:23 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>

void	ft_put_error(int err_no)
{	
	if (err_no == 0)
		write(2, "\e[0;31mInvalid Argument!\n", 25);
	if (err_no == 1)
		write(2, "\e[0;31mMap is imposible!\n", 25);	
	if (err_no == 3)
		write(2, "\e[0;31mBad map inputs\n", 22);
	if (err_no == 4)
		write(2, "\e[0;31mBad extension\n", 21);
	if (err_no == 5)
		write(2, "\e[0;31mMap outline bad\n", 23);
	if (err_no == 6)
		write(2, "\e[0;31mMap not malloc\n", 22);
	if (err_no == 7)
		write(2, "\e[0;31mMap not read\n", 21);
	if (err_no == 8)
		write(2, "\e[0;31mMap not valid\n", 20);
    if (err_no == 9)
		write(2, "\e[0;31mERROR!\n", 14);
	exit(EXIT_FAILURE);
}

void	ft_check_map_name(t_data_map *data)
{
	if (ft_strcmp(&data->txt[ft_strlen(data->txt) - 4], ".ber") != 0
		|| ft_strlen(data->txt) <= 4)
			ft_put_error(4);
}

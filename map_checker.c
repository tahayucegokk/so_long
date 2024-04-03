/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:35:16 by muyucego          #+#    #+#             */
/*   Updated: 2024/04/02 03:16:04 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

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

void	ft_check_outline(t_data_map *data)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < data->width)
	{
		if (data->map[0][i] != '1' || data->map[data->height - 1][i] != '1')
			err = 1;
		i++;
	}
	i = 0;
	while (i < data->height)
	{
		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
			err = 1;
		i++;
	}
	if (err != 0)
		ft_put_error(5);
}

void	ft_check_map_inputs(t_data_map *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] != '1' && data->map[j][i] != '0'
				&& data->map[j][i] != 'C' && data->map[j][i] != 'P'
				&& data->map[j][i] != 'E')
				ft_put_error(3);
			else
				i++;
		}
		j++;
	}
}

void	ft_check_map_objects(t_data_map *data)
{
	int	j;
	int	i;
	int	end;

	end = 0;
	j = -1;
	while (data->map[++j])
	{
		i = -1;
		while (data->map[j][++i])
		{
			if (data->map[j][i] == 'P')
				data->player_count++;
			if (data->map[j][i] == 'C')
				data->coin_count++;
			if (data->map[j][i] == 'E')
				end++;
		}
	}
	if (data->player_count != 1 || data->coin_count < 1 || end != 1)
		ft_put_error(3);
}

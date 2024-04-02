/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:27:01 by muyucego          #+#    #+#             */
/*   Updated: 2024/04/03 00:05:57 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	move_w(t_data_map *data)
{
	if (data->map[data->y - 1][data->x] != '1'
		&& data->map[data->y - 1][data->x] != 'E')
	{
		if (data->map[data->y - 1][data->x] == 'C'
				|| data->map[data->y - 1][data->x] == '0')
		{
			if (data->map[data->y - 1][data->x] == 'C')
				data->coin_count--;
			data->map[data->y][data->x] = '0';
			data->map[data->y - 1][data->x] = 'P';
		}
		data->y--;
		data->step++;
        write(1, "Number of step: ", 16);
		ft_putnbr(data->step);
        write(1, "\n", 1);
	}
	else if (data->map[data->y - 1][data->x] == 'E'
		&& data->coin_count == 0)
		data->finish = 1;
}

void	move_s(t_data_map *data)
{
	if (data->map[data->y + 1][data->x] != '1'
		&& data->map[data->y + 1][data->x] != 'E')
	{
		if (data->map[data->y + 1][data->x] == 'C'
				|| data->map[data->y + 1][data->x] == '0')
		{
			if (data->map[data->y + 1][data->x] == 'C')
				data->coin_count--;
			data->map[data->y][data->x] = '0';
			data->map[data->y + 1][data->x] = 'P';
		}
		data->y++;
		data->step++;
        write(1, "Number of step: ", 16);
		ft_putnbr(data->step);
        write(1, "\n", 1);
	}
	else if (data->map[data->y + 1][data->x] == 'E'
		&& data->coin_count == 0)
		data->finish = 1;
}

void	move_a(t_data_map *data)
{
	if (data->map[data->y][data->x - 1] != '1'
		&& data->map[data->y][data->x - 1] != 'E')
	{
		if (data->map[data->y][data->x - 1] == 'C'
				|| data->map[data->y][data->x - 1] == '0')
		{
			if (data->map[data->y][data->x - 1] == 'C')
				data->coin_count--;
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x - 1] = 'P';
		}
		data->x--;
		data->step++;
        write(1, "Number of step: ", 16);
		ft_putnbr(data->step);
        write(1, "\n", 1);
	}
	else if (data->map[data->y][data->x - 1] == 'E'
		&& data->coin_count == 0)
		data->finish = 1;
}

void	move_d(t_data_map *data)
{
	if (data->map[data->y][data->x + 1] != '1'
		&& data->map[data->y][data->x + 1] != 'E')
	{
		if (data->map[data->y][data->x + 1] == 'C'
				|| data->map[data->y][data->x + 1] == '0')
		{
			if (data->map[data->y][data->x + 1] == 'C')
				data->coin_count--;
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x + 1] = 'P';
		}
		data->x++;
		data->step++;
        write(1, "Number of step: ", 16);
		ft_putnbr(data->step);
        write(1, "\n", 1);
	}
	else if (data->map[data->y][data->x + 1] == 'E'
		&& data->coin_count == 0)
		data->finish = 1;
}
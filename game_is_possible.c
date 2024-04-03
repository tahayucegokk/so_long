/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_is_possible.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:29:39 by muyucego          #+#    #+#             */
/*   Updated: 2024/04/03 17:00:20 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_data_map *data, int pos_x, int pos_y, char **map)
{
	static int		found_exit = 0;

	if (map[pos_y][pos_x] == '1')
		return (0);
	else if (map[pos_y][pos_x] == 'C')
		data->check_coin_count += 1;
	else if (map[pos_y][pos_x] == 'E')
		found_exit = 1;
	map[pos_y][pos_x] = '1';
	flood_fill(data, pos_x + 1, pos_y, map);
	flood_fill(data, pos_x - 1, pos_y, map);
	flood_fill(data, pos_x, pos_y + 1, map);
	flood_fill(data, pos_x, pos_y - 1, map);
	return (found_exit);
}

void	ft_find_player_loc(t_data_map *data)
{
	int		x;
	int		y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->x = x;
				data->y = y;
			}
			x++;
		}
		y++;
	}
}

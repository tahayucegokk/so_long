/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 23:29:16 by muyucego          #+#    #+#             */
/*   Updated: 2024/03/31 23:31:56 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player_img(t_game *game, int *j, int *i)
{
	mlx_put_image_to_window(game.game, game->window,
		game->img_data.wall, (*j) * 40, (*i) * 40);
}

void	ft_draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_data->map[i])
	{
		j = 0;
		while (game->map_data->map[i][j])
		{
			if (data->map[i][j] == '1')
				put_wall_img(data, &j, &i);
			else if (data->map[i][j] == '0')
				put_empty_img(data, &j, &i);
			else if (data->map[i][j] == 'P')
				put_player_img(data, &j, &i);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images->collect, j * 40, i * 40);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images->exit, j * 40, i * 40);
			j++;
		}
		i++;
	}
}
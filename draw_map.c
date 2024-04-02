/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 23:29:16 by muyucego          #+#    #+#             */
/*   Updated: 2024/04/02 02:45:34 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_game *game, int j, int i, char obj)
{
	if (obj == 'W')
		mlx_put_image_to_window(game->game, game->window,
			game->img_data.wall, (j) * 40, (i) * 40);
	if (obj == 'P')
		mlx_put_image_to_window(game->game, game->window,
			game->img_data.player, (j) * 40, (i) * 40);
	if (obj == 'C')
		mlx_put_image_to_window(game->game, game->window,
			game->img_data.coin, (j) * 40, (i) * 40);
	if (obj == 'E')
		mlx_put_image_to_window(game->game, game->window,
			game->img_data.exit, (j) * 40, (i) * 40);
	if (obj == 'e')
		mlx_put_image_to_window(game->game, game->window,
			game->img_data.empty, (j) * 40, (i) * 40);
}

void	ft_check_img(t_game *game, int i, int j)
{
	if (game->map_data.map[i][j] == '1')
		put_img(game, j, i, 'W');
	else if (game->map_data.map[i][j] == '0')
		put_img(game, j, i, 'e');
	else if (game->map_data.map[i][j] == 'P')
		put_img(game, j, i, 'P');
	else if (game->map_data.map[i][j] == 'C')
		put_img(game, j, i, 'C');
	else if (game->map_data.map[i][j] == 'E')
		put_img(game, j, i, 'E');
}

void	ft_draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_data.map[i])
	{
		j = 0;
		while (game->map_data.map[i][j])
		{
			ft_check_img(game, i, j);
			j++;
		}
		i++;
	}
}
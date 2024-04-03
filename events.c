/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:11:52 by muyucego          #+#    #+#             */
/*   Updated: 2024/04/03 17:13:01 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_images(t_game *game)
{
	mlx_destroy_image(game->game, game->img_data.coin);
	mlx_destroy_image(game->game, game->img_data.empty);
	mlx_destroy_image(game->game, game->img_data.exit);
	mlx_destroy_image(game->game, game->img_data.wall);
	mlx_destroy_image(game->game, game->img_data.player);
}

int	ft_exit(t_game *game)
{
	clear_images(game);
	mlx_destroy_window(game->game, game->window);
	ft_free_map(&game->map_data);
	free(game);
	exit(1);
}

int	ft_key_event(int key, t_game *game)
{
	if (key == ESC)
		ft_exit(game);
	else if (key == W && game->map_data.finish == 0)
		move_w(&game->map_data);
	else if (key == S && game->map_data.finish == 0)
		move_s(&game->map_data);
	else if (key == A && game->map_data.finish == 0)
		move_a(&game->map_data);
	else if (key == D && game->map_data.finish == 0)
		move_d(&game->map_data);
	return (1);
}

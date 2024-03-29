/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:11:52 by muyucego          #+#    #+#             */
/*   Updated: 2024/03/30 00:16:08 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_game *game)
{
	mlx_destroy_image(game->game, game->img);
	//mlx_clear_window(game.game, game.window);
	mlx_destroy_window(game->game, game->window);
	free(game);
	system("leaks so_long");
	exit(1);
}

int	ft_key_event(int key, t_game *game)
{
	if (key == 53)
		ft_exit(game);
	return(1);
}

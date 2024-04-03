/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:52:41 by muyucego          #+#    #+#             */
/*   Updated: 2024/04/03 17:02:52 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_control(t_game *game)
{
	ft_check_map_inputs(&game->map_data);
	ft_check_outline(&game->map_data);
	ft_check_map_objects(&game->map_data);
	ft_find_player_loc(&game->map_data);
	if (!flood_fill(&game->map_data, game->map_data.x,
			game->map_data.y, game->map_data.dup_map))
		ft_put_error(3);
	if (game->map_data.check_coin_count != game->map_data.coin_count)
		ft_put_error(3);
}

void	ft_setup_game(t_game *game)
{
	game->game = mlx_init();
	game->width = game->map_data.width * 40;
	game->height = game->map_data.height * 40;
	game->window = mlx_new_window(game->game, game->width,
			game->height, "so_long");
	game->img_data.height = 40;
	game->img_data.width = 40;
	game->map_data.coin_count = 0;
	game->map_data.player_count = 0;
	game->map_data.finish = 0;
	game->map_data.step = 0;
	game->map_data.x = 0;
	game->map_data.y = 0;
	game->map_data.check_coin_count = 0;
}

int	ft_frame(t_game *game)
{
	mlx_clear_window(game->game, game->window);
	ft_draw_map(game);
	if (game->map_data.coin_count == 0 && game->map_data.player_count == 1
		&& game->map_data.finish == 1)
		ft_exit(game);
	return (0);
}

void	ft_xpm_to_image(t_game *game)
{
	game->img_data.wall = mlx_xpm_file_to_image(game->game, "images/wall.xpm",
			&game->img_data.width, &game->img_data.height);
	game->img_data.coin = mlx_xpm_file_to_image(game->game, "images/coin.xpm",
			&game->img_data.width, &game->img_data.height);
	game->img_data.empty = mlx_xpm_file_to_image(game->game, "images/empty.xpm",
			&game->img_data.width, &game->img_data.height);
	game->img_data.player = mlx_xpm_file_to_image(game->game,
			"images/player.xpm", &game->img_data.width, &game->img_data.height);
	game->img_data.exit = mlx_xpm_file_to_image(game->game, "images/exit.xpm",
			&game->img_data.width, &game->img_data.height);
	if (!game->img_data.wall || !game->img_data.player || !game->img_data.empty
		|| !game->img_data.exit || !game->img_data.coin)
		ft_put_error(9);
}

int	main(int ac, char **av)
{
	t_game		*game;

	if (ac == 2)
	{
		game = malloc(sizeof(t_game));
		game->map_data.txt = av[1];
		ft_check_map_name(&game->map_data);
		ft_length_map_data(&game->map_data);
		ft_setup_game(game);
		ft_xpm_to_image(game);
		ft_malloc_map(&game->map_data);
		ft_dup_map(&game->map_data);
		ft_map_control(game);
		ft_draw_map(game);
		mlx_hook(game->window, 17, 0L << 0, ft_exit, game);
		mlx_hook(game->window, 2, 0, ft_key_event, game);
		mlx_loop_hook(game->game, ft_frame, game);
		mlx_loop(game->game);
		return (0);
	}
	else
		ft_put_error(4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:52:41 by muyucego          #+#    #+#             */
/*   Updated: 2024/04/02 20:39:11 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_map_control(t_game *game)
{
    ft_check_map_inputs(&game->map_data);
    ft_check_outline(&game->map_data);
    ft_check_map_objects(&game->map_data);
    if (ft_check_row(&game->map_data, 'P') && ft_check_col(&game->map_data, 'P'))
        ft_put_error(3);
    if (ft_check_row(&game->map_data, 'C') && ft_check_col(&game->map_data, 'C'))
        ft_put_error(3);
    if (ft_check_row(&game->map_data, 'E') && ft_check_col(&game->map_data, 'E'))
        ft_put_error(3);
}

void    ft_setup_game(t_game *game)
{
    // MiniLibX Window
    game->game = mlx_init();
    game->width = game->map_data.width * 40;
    game->height = game->map_data.height * 40;
    game->window = mlx_new_window(game->game, game->width, game->height, "so_long");
    game->img_data.height = 40;
    game->img_data.width = 40;
    game->map_data.coin_count = 0;
    game->map_data.player_count = 0;
}

void    ft_xpm_to_image(t_game *game)
{
    game->img_data.wall = mlx_xpm_file_to_image(game->game, "images/wall.xpm", 
        &game->img_data.width, &game->img_data.height);
    game->img_data.player = mlx_xpm_file_to_image(game->game, "images/player.xpm", 
        &game->img_data.width, &game->img_data.height);
    game->img_data.coin = mlx_xpm_file_to_image(game->game, "images/coin.xpm", 
        &game->img_data.width, &game->img_data.height);
    game->img_data.exit = mlx_xpm_file_to_image(game->game, "images/exit.xpm", 
        &game->img_data.width, &game->img_data.height);
    game->img_data.empty = mlx_xpm_file_to_image(game->game, "images/empty.xpm", 
        &game->img_data.width, &game->img_data.height);
    if (!game->img_data.wall || !game->img_data.player || !game->img_data.empty 
        || !game->img_data.exit || !game->img_data.coin)
        ft_put_error(9);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        t_game *game;
        game = malloc(sizeof(t_game));
        game->map_data.txt = av[1];
        ft_check_map_name(&game->map_data);
        ft_lenght_map_data(&game->map_data);
        ft_setup_game(game);
        ft_xpm_to_image(game);
		ft_malloc_map(&game->map_data);
        ft_map_control(game);
        ft_draw_map(game);
        mlx_hook(game->window, 17, 0L << 0, ft_exit, game);
        mlx_hook(game->window, 2, 0, ft_key_event, game);
        mlx_loop(game->game);
        return (0);
    }
    else
        ft_put_error(4);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:52:41 by muyucego          #+#    #+#             */
/*   Updated: 2024/03/30 00:13:17 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        t_game *game;
        game = malloc(sizeof(t_game));
        // MiniLibX Window
        game->game = mlx_init();
        game->width = 500;
        game->height = 500;
        game->window = mlx_new_window(game->game, game->width, game->height, "so_long");
        // Map Check
        game->map_data.txt = av[1];
        ft_check_map_name(&game->map_data);
        // Map Read
        ft_lenght_map_data(&game->map_data);
        // XPM
        game->img_data.height = 40;
        game->img_data.width = 40;
        game->img = mlx_xpm_file_to_image(game->game, "images/player.xpm", &game->img_data.width, &game->img_data.height);
        // Check IMG
        if (!game->img)
            ft_put_error(9);
        // Print IMG
        mlx_put_image_to_window(game->game, game->window, game->img, game->img_data.height, game->img_data.width);
        // Execute
        mlx_hook(game->window, 17, 0L << 0, ft_exit, game);
        mlx_hook(game->window, 2, 0, ft_key_event, game);
        mlx_loop(game->game);
        return (0);
    }
    else
        ft_put_error(4);
}
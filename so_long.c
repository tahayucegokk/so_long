/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:52:41 by muyucego          #+#    #+#             */
/*   Updated: 2024/03/29 01:31:34 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
    t_game game;

    // MiniLibX Window
    game.width = 500;
    game.height = 500;
    game.game = mlx_init();
    game.window = mlx_new_window(game.game, game.width, game.height, "so_long");
    // XPM
    game.img_data.height = 40;
    game.img_data.width = 40;
    game.img = mlx_xpm_file_to_image(game.game, "images/player.xpm", &game.img_data.width, &game.img_data.height);
    // Check
    if (!game.img)
        exit(1);
    // Print IMG
    mlx_put_image_to_window(game.game, game.window, game.img, game.img_data.height, game.img_data.width);

    // Execute
    mlx_loop(game.game);

    return (0);
}
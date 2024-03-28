/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:52:41 by muyucego          #+#    #+#             */
/*   Updated: 2024/03/29 00:57:53 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "learning.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void    circle(void *img, int x, int y, int radius)
{
    int i;
    int j;
    
    i = -radius;
    while (i <= radius)
    {
        j = -radius;
        while (j <= radius)
        {
            if (i * i + j * j <= radius * radius)
                 my_mlx_pixel_put(img,  x + i, y + j, 0x00FF0000);
            j++;
        }
        i++;
    }
}

void    reverse_triangle(t_data *img, int size)
{
    int x;
    int y;
    x = 0;
    while (x < size)
    {
        y = 0;
        while (y < x)
        {
            my_mlx_pixel_put(img,  x, y, 0x00FF0000);
            y++;
        }
        x++;
    }
}

void    triangle(t_data *img, int size)
{
    int x;
    int y;

    x = 0;
    while (x < size)
    {
       y = x;
        while (y < size)
        {
            my_mlx_pixel_put(img, x, y, 0x00FF0000);
           y++;    
        }
         x++;
    }
}

void    squares(t_data *img, int size)
{
    int x;
    int y;

    x = 0;
    while (x < size)
    {
       y = 0;
        while (y < size)
        {
            my_mlx_pixel_put(img, x, y, 0x00FF0000);
           y++;    
        }
         x++;
    }
}


int main()
{
    t_game game;
    t_data	img;
    game.width = 500;
    game.height= 500;
    game.game = mlx_init();
    game.window = mlx_new_window(game.game, game.height, game.width, "Practice");
	img.img = mlx_new_image(game.game, game.width, game.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    // triangle(&img, 250);
    // reverse_triangle(&img, 250);
    // squares(&img, 250);
    //  circle(&img, 250, 250, 100);
    mlx_put_image_to_window(game.game, game.window, img.img, 0,0);
    mlx_loop(game.game);
}

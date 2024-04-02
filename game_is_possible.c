/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_is_possible.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:29:39 by muyucego          #+#    #+#             */
/*   Updated: 2024/04/02 20:35:30 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    ft_check_row(t_data_map *data, char obj)
{
    int x;
    int y;
    int k;
    
    y = 0;
    while (data->map[y])
    {
        x = 0;
        k = x + 1;
        while (data->map[y][x])
        {
            if (data->map[y][x] == obj)
                if (data->map[y][x + 1] == '1' && data->map[y][x + 1])
                    if (data->map[y][x - 1] == '1' && data->map[y][x - 1])
                        return (1);
            x++;
        }
        y++;
    }
    return (0);
}

int    ft_check_col(t_data_map *data, char obj)
{
    int x;
    int y;

    y = 0;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == obj)
                if (data->map[y + 1][x] == '1' && data->map[y + 1][x])
                    if (data->map[y - 1][x] == '1' && data->map[y - 1][x])
                        return (1);
            x++;
        }
        y++;
    }
    return (0);
}
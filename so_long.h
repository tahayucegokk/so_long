/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:52:06 by muyucego          #+#    #+#             */
/*   Updated: 2024/03/29 02:22:00 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include <stdlib.h>
#include "./get_next_line/get_next_line.h"

typedef struct	s_img {
    int height;
    int width;
}				t_data_img;

typedef struct	s_map {
    	char			*txt;
}				t_data_map;

typedef struct s_game
{
    void *window;
    void *game;
    int width;
    int height;
    void	*img;
    t_data_img img_data;
    t_data_map map_data;
} t_game;

int	    ft_strlen(char *str);
int     ft_strcmp(char *s1, char *s2);
void    ft_put_error(int err_no);
void	ft_check_map_name(t_data_map *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:52:06 by muyucego          #+#    #+#             */
/*   Updated: 2024/03/30 00:12:10 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include <stdlib.h>
#include "./get_next_line/get_next_line.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_img {
    int height;
    int width;
}				t_data_img;

typedef struct	s_map {
    	char			*txt;
        int             height;
        int             width;
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

int	    ft_exit(t_game *game);
int	    ft_key_event(int key, t_game *game);
int	    key_events(t_game game, int key);
int	    ft_strlen(char *str);
int     ft_strcmp(char *s1, char *s2);
void    ft_put_error(int err_no);
void	ft_check_map_name(t_data_map *data);
void	ft_lenght_map_data(t_data_map *data);

#endif
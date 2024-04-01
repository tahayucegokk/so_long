/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:52:06 by muyucego          #+#    #+#             */
/*   Updated: 2024/03/31 23:27:04 by muyucego         ###   ########.fr       */
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
    void	*player;
    void	*exit;
    void	*coin;
    void	*wall;
    void	*empty;

}				t_data_img;

typedef struct	s_map {
    	char			*txt;
        int             height;
        int             width;
        char			**map;
}				t_data_map;

typedef struct s_game
{
    void *window;
    void *game;
    int width;
    int height;
    t_data_img img_data;
    t_data_map map_data;
} t_game;

int	    ft_exit(t_game *game);
int	    ft_key_event(int key, t_game *game);
void	ft_free_map(t_data_map *data);
int	    key_events(t_game game, int key);
int	    ft_strlen(char *str);
char	*ft_strcpy(char *s1, char *s2);
void	ft_malloc_map(t_data_map *data);
char	*ft_strdup(char *str);
int     ft_strcmp(char *s1, char *s2);
void    ft_put_error(int err_no);
void	ft_check_map_name(t_data_map *data);
void	ft_lenght_map_data(t_data_map *data);

#endif
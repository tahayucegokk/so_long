/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:52:06 by muyucego          #+#    #+#             */
/*   Updated: 2024/03/29 01:27:50 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>

#define GREEN_PIXEL 0xFF00

typedef struct	s_img {
    int height;
    int width;
}				t_data_img;

typedef struct s_game
{
    void *window;
    void *game;
    int width;
    int height;
    void	*img;
    t_data_img img_data;
} t_game;
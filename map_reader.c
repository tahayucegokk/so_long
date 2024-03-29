/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 03:20:18 by muyucego          #+#    #+#             */
/*   Updated: 2024/03/29 03:24:25 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

void	ft_lenght_map_data(t_data_map *data)
{
	char	*file_path;
	char	*line;
	int fd;

	file_path = data->txt;
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_put_error(7);
	data->width = ft_strlen(line) - 1;
	data->height = 0;
	while (line)
	{
		if (ft_strlen(line) - 1 != data->width)
			ft_put_error(8);
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
}

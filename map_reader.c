/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 03:20:18 by muyucego          #+#    #+#             */
/*   Updated: 2024/03/31 22:56:23 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

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

void	ft_free_map(t_data_map *data)
{
	int i;

	i = 0;
	while(data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	ft_malloc_map(t_data_map *data)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(data->txt, O_RDONLY);
	i = 0;
	data->map = (char **)malloc(sizeof (char *) * (data->height + 1));
	if (!data->map)
		ft_put_error(6);
	while (i < data->height)
	{
		line = get_next_line(fd);
		if (!line)
			ft_put_error(6);
		data->map[i] = ft_strdup(line);
		if (!data->map[i])
			ft_put_error(6);
		data->map[i][data->width] = '\0';
		i++;
		free(line);
	}
	data->map[i] = NULL;
	close(fd);
}

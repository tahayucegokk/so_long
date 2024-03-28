/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:24:15 by muyucego          #+#    #+#             */
/*   Updated: 2024/03/29 01:56:30 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *stack, char *buffer);
char	*gnl_strdup(char *s1);
size_t	gnl_strlen(char *s);
char	*get_lines(char *str);
char	*read_line(int fd, char *str);
char	*update_str(char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:48:42 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/11 20:16:10 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// static int	fill_line(char **line, char *stock, int fd)
// {
// 	int		nb_read;
// 	char	buf[BUFFER_SIZE + 1];
// 	char	*tmp;

// 	buf[0] = '\0';
// 	nb_read = 1;
// 	*line = ft_strdup(stock);
// 	if (*line == NULL)
// 		return (0);
// 	while (ft_strchr(buf, '\n') == NULL && nb_read > 0)
// 	{
// 		nb_read = read(fd, buf, BUFFER_SIZE);
// 		buf[nb_read] = '\0';
// 		tmp = ft_strjoin(*line, buf);
// 		if (tmp == NULL)
// 			return (free(*line), 0);
// 		free(*line);
// 		*line = tmp;
// 	}
// 	return (1);
// }


// int	get_next_line(int fd, char **line)
// {
// 	static char	stock[BUFFER_SIZE + 1] = "";
// 	char		*tmp;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || !fill_line(line, stock, fd) || !(**line))
// 		return (0);
// 	auto char *new_stock = ft_strchr(*line, '\n');
// 	if (new_stock)
// 	{
// 		new_stock++;
// 		ft_strlcpy(stock, new_stock, ft_strlen(new_stock) + 1);
// 		tmp = ft_substr(*line, 0, new_stock - *line);
// 		if (tmp == NULL)
// 			return (free(*line), 0);
// 		free(*line);
// 		*line = tmp;
// 	}
// 	else
// 		ft_bzero(stock, ft_strlen(stock));
// 	return (1);
// }

// static int	readline(int fd, char **line)
// {
// 	char	buf[BUFFER_SIZE + 1];
// 	char	*line;
// 	char	*temp;
// 	ssize_t	nb_bytes;

// 	while (1)
// 	{
// 		nb_bytes = read(fd, buf, BUFFER_SIZE);
// 		if (nb_bytes < 0)
// 			return (free(line), NULL );
// 		buf[nb_bytes] = '\0';
// 		temp = ft_strjoin(line, buf);
// 		if (temp == NULL)
// 	}
// 	return (line);
// }

// int	get_next_line(int fd, char **line)
// {
// 	static char	stock[BUFFER_SIZE + 1] = "";
// 	char		*line;
// 	ssize_t		nb_bytes;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (0);
// 	*line = ft_strdup(stock);
// 	if (line == NULL)
// 		return (0);
// }


/*

	Hello



*/

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {};
	char	*line;
	ssize_t	nb_bytes;
	size_t	pos;

	line = ft_strdup("");
	if (line == NULL)
		return (NULL);
	while (1)
	{
		pos = ft_strcspn(buffer, "\n");
		pos += buffer[pos] == '\n';
		line = realloc(line, ft_strlen(line) + pos + 1);
		if (line == NULL)
			return (NULL);
		ft_strncpy(line + ft_strlen(line), buffer, pos);
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nb_bytes == -1)
			return (free(line), NULL);
		if (nb_bytes == 0)
			break;
		buffer[nb_bytes] = '\0';
	}
	if (*line == '\0')
		return (free(line), NULL);
	ft_strcpy(buffer, buffer + pos + (buffer[pos] == '\n'));
	return (line);
}

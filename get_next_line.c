/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:02:45 by jareste-          #+#    #+#             */
/*   Updated: 2023/05/20 00:23:16 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*new_line(char *buffer)
{
	int		len;
	char	*newline;
	char	*aux;

	aux = ft_strchr(buffer, '\n');
	len = (aux - buffer) + 1;
	newline = ft_substr(buffer, 0, len);
	if (!newline)
		return (NULL);
	return (newline);
}

char	*ft_find_line(int fd, char *buffer)
{
	char	*temp;
	int		aux;

	aux = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (ft_free(&buffer));
	temp[0] = '\0';
	while (aux > 0 && !ft_strchr(temp, '\n'))
	{
		aux = read(fd, temp, BUFFER_SIZE);
		if (aux > 0)
		{
			temp[aux] = '\0';
			buffer = ft_strjoin(buffer, temp);
		}
	}
	free(temp);
	if (aux == -1)
		return (ft_free(&buffer));
	return (buffer);
}

char	*empty_prev_line(char *buffer)
{
	char	*n_buffer;
	char	*aux;
	int		len;

	aux = ft_strchr(buffer, '\n');
	if (!aux)
	{
		n_buffer = NULL;
		return (ft_free(&buffer));
	}
	else
		len = (aux - buffer) + 1;
	if (!buffer[len])
		return (ft_free(&buffer));
	n_buffer = ft_substr(buffer, len, ft_strlen(buffer) - len);
	ft_free(&buffer);
	if (!n_buffer)
		return (NULL);
	return (n_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = {0};
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!buffer || (buffer && !ft_strchr(buffer, '\n')))
		buffer = ft_find_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = new_line(buffer);
	if (!line)
		return (ft_free(&buffer));
	buffer = empty_prev_line(buffer);
	return (line);
}
/*
#include <fcntl.h> //OPEN LIBRARY
int	main(int argc, char **argv)
{
	int	fd;
	int i = 6;
	char *str;

	if (argc == 50)
		return (2);
	fd = open(argv[1], O_RDONLY);
	while (i-- > 0)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
	close(fd);
	return (0);
}*/

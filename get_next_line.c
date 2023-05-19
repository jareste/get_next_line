/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:02:45 by jareste-          #+#    #+#             */
/*   Updated: 2023/05/19 19:55:19 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

#define BUFFER_SIZE 300

char	*new_line(char *buffer)
{
	int		len;
	char	*newline;
	char	*aux;
	
	aux = ft_strchr(buffer, '\n');
	len = (aux - buffer) + 1;
	return (ft_substr(newline, 0, len));
}

char	*ft_find_line(int fd, char *buffer)
{
	char	*temp;
	int		aux;

	printf("hola\n");
	aux = 1;
	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (0);
	temp[0] = '\0';
	printf("2hola\n");
	while (!ft_strchr(buffer, '\n') && aux > 0)
	{
		aux = read(fd, temp, BUFFER_SIZE);
		if (aux > 0)
		{
			temp[aux] = '\0';
			buffer = ft_strjoin(buffer, temp);
		}
	}
	free(temp);
	return (buffer);
}

char	*empty_prev_line(char *buffer)
{
	char	*n_buffer;
	char	*aux;
	int		len;
	
	aux = ft_strchr(buffer, '\n');
//	printf("sadge");
	if (!aux)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	len = aux - buffer + 1;
	n_buffer = ft_substr(buffer, len, ft_strlen(buffer) - len);
//	free(buffer);
//	buffer = NULL;
	if (!n_buffer)
		return (NULL);
	return(n_buffer);

}

char	*get_next_line(int fd)
{
	static char	*buffer = {0};
	char		*line;
	
	if (fd < 0)
		return (0);
	if (!buffer)
	{
		buffer = malloc(1 * sizeof(char));
		buffer = ft_find_line(fd, buffer);
	}
	line = new_line(buffer);
	buffer = empty_prev_line(buffer);
	return(line);
}

#include <fcntl.h> //OPEN LIBRARY
int	main(int argc, char **argv)
{
	int	fd;
	int i = 5;
	char *str;

	if (argc == 50)
		return (2);
	fd = open(argv[1], O_RDONLY);
	while (i-- > 0)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
	}
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:31:17 by jareste-          #+#    #+#             */
/*   Updated: 2023/05/20 00:23:23 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500000000
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*new_line(char *buffer);
char	*ft_find_line(int fd, char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_free(char **buffer);

#endif

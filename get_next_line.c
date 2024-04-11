/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:22:37 by aestrell          #+#    #+#             */
/*   Updated: 2024/03/21 18:22:37 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>

static char *ft_next_ln(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	J = 0;
	if (buffer[i] == NULL)
		return (free(buffer), NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc((ft_strlen(buffer) - i) + 1);
	if (line == NULL)
		return (free(line), NULL);
	while (line[i] != '\0')
	{
		
	}
}
/*
static char	*create_substring(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*str)
		return (free(str), NULL);
	i = find_next_line_break(str, i);
	new_str = (char *)malloc((ft_strlen(str) - i) + 1);
	if (!new_str)
		return (free(new_str), NULL);
	while (*(str + i))
		*(new_str + j++) = *(str + i++);
	*(new_str + j) = '\0';
	if (!*new_str)
		return (free(str), free(new_str), NULL);
	free(str);
	return (new_str);
}*/

static char	*ft_read_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || buffer[i] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_read_file(int fd, char *buffer)
{
	char	*content_file;
	int		read_bytes;

	read_bytes = 1;
	content_file = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (content_file == NULL)
		return (NULL);
	while (!(ft_strchr(buffer, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, content_file, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(content_file);
			return (NULL);
		}
		content_file[read_bytes] = '\0';
		buffer = ft_strjoin(buffer, content_file);
	}
	free(content_file);
	return (buffer);
}

// Función principal get_next_line
char	*get_next_line(int fd)
{
	static char	*read_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	read_buffer = ft_read_file(fd, read_buffer);
	if (!read_buffer)
		return (NULL);
	line = ft_read_line(read_buffer);
	read_buffer = create_substring(read_buffer);
	return (line);
}

/*
int	main(void)
{
	int	fd1;

	fd1 = open("test.txt", O_RDONLY);
	if (fd1 == -1)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	printf("%s", get_next_line(fd1));
	return (0);
}
*/

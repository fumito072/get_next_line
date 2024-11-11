/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:53:53 by fhoshina          #+#    #+#             */
/*   Updated: 2024/11/09 19:26:25 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *rest;
	char *line;
	static char *buffer = NULL;

	rest = NULL;
	if (buffer == NULL)
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	line = get_buffer(fd, rest, buffer);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char *get_buffer(int fd, char *rest, char *buffer)
{
	static char *buffer_tail = NULL;
	char *line;
	char *found;
	static int flag = 1;
	ssize_t bytes_read;

	if (buffer_tail == NULL)
		buffer_tail = buffer;
	line = NULL;
	found = NULL;
	while (found == NULL)
	{
		found = ft_strchr(buffer_tail, '\n'); 
		if (found)
		{
			line = ft_strnjoin(line, buffer_tail, found - buffer_tail + 1);
			buffer_tail = found + 1;
			return (line);
		}
		else 
			line = ft_strnjoin(line, buffer_tail,BUFFER_SIZE - (buffer_tail - buffer));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if ((line && bytes_read == 0) && flag == 1)
			{
				flag = 0;
				return (line);
			}
			free(line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		buffer_tail = buffer;
	}
	return (line);
}

int main()
{
	int fd;
	char *s;

	

	fd = open("./text.txt", O_RDONLY);
	for (int i=0; i < 5; i++)
	{
		s = get_next_line(fd);
		printf("%s", s);
	}
}
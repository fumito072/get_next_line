/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:54:00 by fhoshina          #+#    #+#             */
/*   Updated: 2024/11/07 22:43:27 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char *ft_strdup(const char *s)
{
	char *dup;
	char *sub;
	int i;
	int size;

	i = 0;
	sub = (char *)s;
	size = ft_strlen(sub);
	dup = malloc(sizeof(char) * size + 1);
	if (!dup)
		return (NULL);
	while (sub[i])
	{
		dup[i] = sub[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char *ft_strnjoin(char *line, char *buffer, ssize_t length)
{
	size_t line_len;
	size_t buffer_len;
	int i;
	int j;
	char *marge;

	i = 0;
	j = 0;
	line_len = ft_strlen(line);
	buffer_len = ft_strlen(buffer);
	marge = malloc(sizeof(char) * line_len + length + 1);
	while (i < line_len)
		marge[j++] = line[i++];
	i = 0;
	while (i < length)
		marge[j++] = buffer[i++];
	marge[j] = '\0';
	return (marge);
}

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	unsigned char	*d;
// 	unsigned char	*s;

// 	d = (unsigned char *)dest;
// 	s = (unsigned char *)src;
// 	while (n)
// 	{
// 		*d = *s;
// 		d++;
// 		s++;
// 		n--;
// 	}
// 	return (dest);
// }

// void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char	*ptr;

// 	ptr = s;
// 	while (n != 0)
// 	{
// 		*ptr = 0;
// 		ptr++;
// 		n--;
// 	}
// }

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*ptr;

// 	if (nmemb != 0 && size > __SIZE_MAX__ / nmemb)
// 		return (NULL);
// 	ptr = malloc(nmemb * size);
// 	if (!ptr)
// 		return (NULL);
// 	ft_bzero(ptr, nmemb * size);
// 	return (ptr);
// }


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:41:43 by fluchten          #+#    #+#             */
/*   Updated: 2022/11/17 10:31:35 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Read the file descriptor to add characters to the stash */
static char	*ft_read_and_stash(int fd, char *stash)
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_bytes;

	if (!stash)
	{
		stash = malloc(sizeof(char) + 1);
		if (!stash)
			return (ft_free_stash(&stash));
		stash[0] = '\0';
	}
	read_bytes = 1;
	while (!ft_is_newline(stash) && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (ft_free_stash(&stash));
		buf[read_bytes] = '\0';
		stash = ft_strjoin_gnl(stash, buf);
	}
	return (stash);
}

/* Add all characters from the cache and stores them in the line.
Stopping after the first \n it encounters */
static char	*ft_extract_in_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

/* This function cleans up the stash.
Only the characters not returned at the end remain in our static stash. */
static char	*ft_clean_stash(char *stash)
{
	char	*new_stash;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stash)
		return (ft_free_stash(&stash));
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	j = 0;
	if (!stash[i])
		return (ft_free_stash(&stash));
	while (stash[i + j])
		j++;
	new_stash = malloc(sizeof(char) * (j + 1));
	if (!new_stash)
		return (ft_free_stash(&stash));
	j = 0;
	while (++j && stash[i + j - 1])
		new_stash[j - 1] = stash[i + j - 1];
	new_stash[j - 1] = '\0';
	free(stash);
	return (new_stash);
}

/* The main function used to get the next line string of a file descriptor */
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_and_stash(fd, stash);
	line = ft_extract_in_line(stash);
	if (!line)
		return (ft_free_stash(&stash));
	stash = ft_clean_stash(stash);
	return (line);
}

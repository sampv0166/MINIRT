/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 05:26:16 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/10 03:16:53 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static char	*ft_strjoin_get(char *saved_line, char *buffer)
{
	char	*new_string;
	int		total_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	total_len = ft_strlen(saved_line) + ft_strlen(buffer) + 1;
	new_string = (char *) malloc(sizeof(char) * (total_len));
	if (new_string == NULL)
		return (free_memmory(&new_string));
	while (saved_line[i])
		new_string[i++] = saved_line[j++];
	j = 0;
	while (buffer[j])
		new_string[i++] = buffer[j++];
	new_string[i] = '\0';
	free_memmory(&saved_line);
	return (new_string);
}

static char	*save_the_rest(char *saved_line)
{
	char	*new_string;
	size_t	length_of_save;
	size_t	i;

	i = get_current_line_size(saved_line);
	length_of_save = ft_strlen(saved_line + i);
	new_string = (char *)malloc(sizeof(char) * (length_of_save + 1));
	if (new_string == NULL)
	{
		free(new_string);
		return (NULL);
	}
	length_of_save = 0;
	while (saved_line && saved_line[i])
	{
		new_string[length_of_save] = saved_line[i];
		i++;
		length_of_save++;
	}
	new_string[length_of_save] = '\0';
	free(saved_line);
	saved_line = new_string;
	return (saved_line);
}

static char	*get_current_line(char *saved_line, char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	line = malloc(sizeof(char) * (get_current_line_size(saved_line) + 1));
	if (line == NULL)
		return (free_memmory(&line));
	while (saved_line[j] && saved_line[j] != '\n')
	{
		line[i] = saved_line[j];
		j++;
		i++;
	}
	if (saved_line[j] == '\n')
	{
		line[i++] = '\n';
		j++;
	}
	line[i++] = '\0';
	return (line);
}

static char	*get_temp_line(int fd, char *saved_line, int read_return)
{
	char	*buffer;

	buffer = (char *) malloc(sizeof(char) * (1 + 1));
	if (buffer == NULL)
		return (free_memmory(&buffer));
	buffer[0] = '\0';
	while (read_return > 0 && ft_strchr(saved_line, '\n') == NULL)
	{
		read_return = read(fd, buffer, 1);
		if (read_return > 0)
		{
			buffer[read_return] = '\0';
			saved_line = ft_strjoin_get(saved_line, buffer);
		}
	}
	if (read_return <= 0)
	{
		free(buffer);
		if (ft_strlen(saved_line) > 0)
			return (saved_line);
		free_memmory(&saved_line);
		return (NULL);
	}
	free(buffer);
	return (saved_line);
}

char	*get_next_line(int fd)
{
	static char		*saved_line;
	char			*next_line;

	next_line = NULL;
	if (fd < 0)
		return (0);
	if (!saved_line)
	{
		saved_line = (char *) malloc(sizeof(char) * 1);
		*saved_line = '\0';
		if (saved_line == NULL)
			return (free_memmory(&saved_line));
	}
	saved_line = get_temp_line(fd, saved_line, 1);
	if (!saved_line)
		return (free_memmory(&saved_line));
	next_line = get_current_line(saved_line, next_line);
	saved_line = save_the_rest(saved_line);
	return (next_line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:43:37 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/10 03:16:21 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minirt.h"

size_t	get_current_line_size(char *saved_line)
{
	size_t	i;

	i = 0;
	while (saved_line[i] && saved_line[i] != '\n')
	{
		i++;
	}
	if (saved_line[i] == '\n')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if (c == '\0')
		return ((char *)str + i);
	return (0);
}

char	*free_memmory(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

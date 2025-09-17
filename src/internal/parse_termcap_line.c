/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_termcap_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:03:15 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/17 16:27:28 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "core/string/ft_string.h"
#include "internal/ft_termcap_internal.h"

t_ft_termcap_entry	*g_capabilities = NULL;
size_t				g_num_capabilities = 0;

static void	free_termcap_entries(void)
{
	if (g_capabilities)
	{
		free(g_capabilities);
		g_capabilities = NULL;
		g_num_capabilities = 0;
	}
}

static void	add_capability(char *token)
{
	char	*equal_sign;
	char	*hash_sign;
	char	*name;
	char	*value;

	equal_sign = ft_strchr(token, '=');
	hash_sign = ft_strchr(token, '#');
	name = token;
	value = NULL;
	if (equal_sign)
	{
		*equal_sign = '\0';
		value = equal_sign + 1;
	}
	else if (hash_sign)
	{
		*hash_sign = '\0';
		value = hash_sign + 1;
	}
	else
		value = (char *)(__intptr_t)"1";
	g_capabilities[g_num_capabilities].name = name;
	g_capabilities[g_num_capabilities].value = value;
	g_num_capabilities++;
}

static bool	cleanup(void)
{
	free(g_capabilities);
	g_capabilities = NULL;
	g_num_capabilities = 0;
	return (false);
}

// TODO: recode strtok_r
bool	parse_termcap_line(const char *line)
{
	char	*line_copy;
	char	*save_ptr;
	char	*token;

	if (!line || *line == '\0')
		return (false);
	free_termcap_entries();
	g_capabilities = malloc(MAX_CAPABILITIES * sizeof(t_ft_termcap_entry));
	if (!g_capabilities)
		return (false);
	line_copy = ft_strdup(line);
	if (!line_copy)
		return (cleanup());
	save_ptr = NULL;
	token = __strtok_r(NULL, ":", &save_ptr);
	while (token != NULL && g_num_capabilities < MAX_CAPABILITIES)
	{
		add_capability(token);
		token = __strtok_r(NULL, ":", &save_ptr);
	}
	free(line_copy);
	return (g_num_capabilities > 0);
}

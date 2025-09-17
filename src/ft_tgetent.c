/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tgetent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:14:41 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/17 15:09:15 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_termcap.h"
#include "core/string/ft_string.h"
#include "internal/ft_termcap_internal.h"
#include "io/ft_io.h"

static char	*g_termcap_data = NULL;

static void	free_if_needed(void)
{
	if (g_capabilities)
	{
		free(g_capabilities);
		g_capabilities = NULL;
		g_num_capabilities = 0;
	}
	if (g_termcap_data)
	{
		free(g_termcap_data);
		g_termcap_data = NULL;
	}
}

static t_ft_file	*open_termcap_file(const char **path)
{
	*path = getenv("TERMCAP");
	if (!*path)
		*path = "/etc/termcap";
	return (ft_fopen(*path, "r"));
}

static int32_t	load_term_entry(const char *line, const char *name)
{
	char	*term_name;

	term_name = ft_strtok((char *)line, "|:");
	if (term_name && ft_strcmp(term_name, name) == 0)
	{
		g_termcap_data = ft_strdup(line);
		if (!g_termcap_data)
			return (0);
		if (parse_termcap_line(g_termcap_data))
			return (1);
	}
	return (0);
}

int32_t	ft_tgetent(const char *bp, const char *name)
{
	char		line[FT_TERMCAP_BUFSIZ];
	const char	*path;
	t_ft_file	*fp;

	(void)bp;
	free_if_needed();
	fp = open_termcap_file(&path);
	if (!fp)
		return (0);
	while (ft_fgets(line, sizeof(line), fp))
	{
		if (line[0] == '#' || line[0] == '\n' || line[0] == ':')
			continue ;
		if (load_term_entry(line, name))
		{
			ft_fclose(fp);
			return (1);
		}
	}
	ft_fclose(fp);
	return (0);
}

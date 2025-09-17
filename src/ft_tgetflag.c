/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tgetflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:25:06 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/17 16:38:58 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "core/string/ft_string.h"
#include "internal/ft_termcap_internal.h"

bool	ft_tgetflag(const char *id)
{
	size_t	i;

	if (!g_capabilities || !id)
		return (false);
	i = 0;
	while (i < g_num_capabilities)
	{
		if (ft_strcmp(g_capabilities[i].name, id) == 0)
		{
			if (ft_strcmp(g_capabilities[i].value, "1") == 0)
				return (true);
			return (false);
		}
		i++;
	}
	return (false);
}

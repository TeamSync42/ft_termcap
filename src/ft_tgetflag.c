/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tgetflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:25:06 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/17 16:29:22 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "core/string/ft_string.h"
#include "internal/ft_termcap_internal.h"

int32_t	ft_tgetflag(const char *id)
{
	size_t	i;

	if (!g_capabilities || !id)
		return (0);
	i = 0;
	while (i < g_num_capabilities)
	{
		if (ft_strcmp(g_capabilities[i].name, id) == 0)
		{
			if (ft_strcmp(g_capabilities[i].value, "1") == 0)
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}

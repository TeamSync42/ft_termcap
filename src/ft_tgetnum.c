/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tgetnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:25:20 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/17 16:32:12 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "core/string/ft_string.h"
#include "internal/ft_termcap_internal.h"

int32_t	ft_tgetnum(const char *id)
{
	size_t	i;

	if (!g_capabilities || !id)
		return (-1);
	i = 0;
	while (i < g_num_capabilities)
	{
		if (ft_strcmp(g_capabilities[i].name, id) == 0)
			return (ft_atoi(g_capabilities[i].value));
		i++;
	}
	return (-1);
}

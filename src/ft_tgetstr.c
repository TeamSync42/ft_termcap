/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tgetstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:25:23 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/17 16:37:25 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "core/memory/ft_memory.h"
#include "core/string/ft_string.h"
#include "internal/ft_termcap_internal.h"

char	*ft_tgetstr(const char *id, char **area)
{
	size_t	i;
	size_t	len;
	char	*value_ptr;
	char	*result;

	if (!g_capabilities || !id || !area)
		return (NULL);
	i = 0;
	while (i < g_num_capabilities)
	{
		if (ft_strcmp(g_capabilities[i].name, id) == 0)
		{
			value_ptr = g_capabilities[i].value;
			len = ft_strlen(value_ptr) + 1;
			result = *area;
			ft_memcpy(*area, value_ptr, len);
			*area += len;
			return (result);
		}
		i++;
	}
	return (NULL);
}

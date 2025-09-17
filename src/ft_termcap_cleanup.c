/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap_cleanup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:23:59 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/17 17:25:50 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_termcap.h"
#include "internal/ft_termcap_internal.h"

void	ft_termcap_cleanup(void)
{
	if (g_capabilities)
	{
		free(g_capabilities);
		g_capabilities = NULL;
	}
	if (g_termcap_data)
	{
		free(g_termcap_data);
		g_termcap_data = NULL;
	}
	g_num_capabilities = 0;
}

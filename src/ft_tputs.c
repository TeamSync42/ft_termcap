/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:00:19 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/17 17:20:42 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_termcap.h"
#include "core/stdlib/ft_stdlib.h"
#include "io/ft_io.h"

static int32_t	print_until_dollar(const char *str, int32_t (*outc)(int32_t),
					size_t *i)
{
	while (str[*i] && str[*i] != '$')
	{
		if (outc((int32_t)str[*i]) == FT_EOF)
			return (-1);
		(*i)++;
	}
	return (0);
}

static void	handle_padding(const char *str, const int32_t affcnt, size_t *i)
{
	char	*end_ptr;
	int64_t	padding_ms;

	padding_ms = ft_strtol(str + *i, &end_ptr, 10);
	*i = (size_t)(end_ptr - str);
	if (str[*i] == '*' || str[*i] == '/')
	{
		padding_ms *= affcnt;
		(*i)++;
	}
	if (padding_ms > 0)
		usleep((uint32_t)(padding_ms * 1000));
}

int32_t	ft_tputs(const char *str, const int32_t affcnt,
					int32_t (*outc)(int32_t))
{
	size_t	i;

	if (!str || !outc)
		return (-1);
	i = 0;
	if (print_until_dollar(str, outc, &i) == -1)
		return (-1);
	if (str[i] == '$')
	{
		i++;
		handle_padding(str, affcnt, &i);
	}
	while (str[i])
	{
		if (outc((int32_t)str[i]) == FT_EOF)
			return (-1);
		i++;
	}
	return (0);
}

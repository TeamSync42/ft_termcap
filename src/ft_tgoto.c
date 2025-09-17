/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tgoto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:40:19 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/17 16:59:37 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "core/string/ft_string.h"
#include "io/ft_printf.h"

#define FT_TGOTO_BUFSIZE 256

static void	write_value(char **result, int32_t *col, int32_t *row,
				const char fmt)
{
	int32_t	value;
	int32_t	tmp;
	size_t	size;

	if (fmt == 'i')
		value = *col + 1;
	else
		value = *col;
	size = FT_TGOTO_BUFSIZE - (size_t)(*result - (char *)(__intptr_t) * result);
	*result += ft_snprintf(*result, size, "%d", value);
	tmp = *col;
	*col = *row;
	*row = tmp;
}

char	*ft_tgoto(const char *cap, int32_t col, int32_t row)
{
	static char	result_buffer[FT_TGOTO_BUFSIZE];
	char		*result;

	if (!cap)
		return (NULL);
	result = result_buffer;
	while (*cap)
	{
		if (*cap == '%' && *(cap + 1) != '\0')
		{
			cap++;
			if (*cap == 'd' || *cap == 'i')
			{
				write_value(&result, &col, &row, *cap),
				cap++;
				continue ;
			}
		}
		*result = *cap;
		result++;
		cap++;
	}
	*result = '\0';
	return (result_buffer);
}

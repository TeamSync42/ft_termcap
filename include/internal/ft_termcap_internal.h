/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:29:56 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/17 16:27:28 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMCAP_INTERNAL_H
# define FT_TERMCAP_INTERNAL_H

# include <stdbool.h>

# ifndef MAX_CAPABILITIES
#  define MAX_CAPABILITIES 256
# endif // MAX_CAPABILITIES

typedef struct s_ft_termcap_entry {
	char	*name;
	char	*value;
}	t_ft_termcap_entry;

extern t_ft_termcap_entry	*g_capabilities;
extern size_t				g_num_capabilities;

bool	parse_termcap_line(const char *line);

#endif // FT_TERMCAP_INTERNAL_H

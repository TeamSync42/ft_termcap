/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:12:47 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/17 16:53:16 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMCAP_H
# define FT_TERMCAP_H

# include <stdbool.h>
# include <stdint.h>

# define FT_TERMCAP_BUFSIZ 4096

int32_t	ft_tgetent(const char *bp, const char *name);
char	*ft_tgetstr(const char *id, char **area);
int32_t	ft_tgetnum(const char *id);
bool	ft_tgetflag(const char *id);
int32_t	ft_tputs(const char *str, int32_t affcnt, int32_t (*outc)(int32_t));
char	*ft_tgoto(const char *cap, int32_t col, int32_t row);
void	ft_termcap_cleanup(void);

#endif // FT_TERMCAP_H

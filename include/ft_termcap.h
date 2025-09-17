/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:12:47 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/17 13:34:26 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMCAP_H
# define FT_TERMCAP_H

# include <stdint.h>

int32_t	ft_tgetent(char *bp, const char *name);
char	*ft_tgetstr(const char *id, char **area);
int32_t	ft_tgetnum(const char *id);
int32_t	ft_tgetflag(const char *id);
int32_t	ft_tputs(const char *str, int32_t affcnt, int32_t (*outc)(int32_t));
char	*ft_tgoto(const char *cap, int32_t row, int32_t col);
void	ft_termcap_cleanup(void);

#endif // FT_TERMCAP_H

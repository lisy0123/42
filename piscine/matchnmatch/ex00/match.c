/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:50:28 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/02 18:03:24 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		match(char *s1, char *s2)
{
	if (*s1 && *s2 && *s2 == '*')
		return (match(s1, s2 + 1));
	else if (*s1 && *s2 && *s1 == '*')
		return (match(s1 + 1, s2));
	else if (!(*s1) && *s2 == '*')
		return (match(s1, s2 + 1));
	else if (*s1 && *s2 && *s1 != *s2)
		return (match(s1 + 1, s2));
	else if (*s2 && *s1 && *s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	else if (!(*s2) && *s1)
		return (match(s1 + 1, s2));
	else if (!(*s1) && !(*s2))
		return (1);
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:35:03 by sanlee            #+#    #+#             */
/*   Updated: 2020/02/23 20:07:46 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
		node->content = NULL;
	else
	{
		node->content = ft_memalloc(content_size);
		if (!content)
		{
			free(node);
			return (NULL);
		}
		ft_memcpy(node->content, content, content_size);
	}
	node->content_size = (content == NULL) ? 0 : content_size;
	node->next = NULL;
	return (node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:43:51 by olcherno          #+#    #+#             */
/*   Updated: 2025/07/14 17:23:38 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ns;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	ns = (char *)malloc((sizeof(char) * (len + 1)));
	if (ns == NULL)
		return (NULL);
	i = 0;
	while (len--)
	{
		ns[i] = s[i];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}

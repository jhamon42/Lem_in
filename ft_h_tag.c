/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h_tag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 07:35:59 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/20 09:17:38 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int ft_is_com(char *line, t_lem *p)
{
	if (line || p)
		;
	return (0);
}

static int ft_is_cmd(char *line, t_lem *p)
{
	if (line || p)
		;
	return (0);
}

int ft_h_tag(char *line, t_lem *p)
{
	if (ft_strnequ("#", line, 1))
	{
		if (ft_strnequ("##", line, 2))
			ft_is_cmd(line, p);
		else
			ft_is_com(line, p);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:58:33 by piliegeo          #+#    #+#             */
/*   Updated: 2018/05/25 14:46:38 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_init_nlien(t_lem *p)
{
	t_salle		*s;

	s = p->sal;
	while (s)
	{
		s->n_lien = p->n_salle;
		s = s->next;
	}
}

void		ft_fill_struct(t_lem *p)
{
	t_link		*l;
	t_salle		*s;
	int			count[2];

	count[1] = 0;
	s = p->sal;
	while (s && count[1]++ > -1)
	{
		s->first = p->sal;
		count[0] = 0;
		l = s->lien;
		while (l && count[0]++ > -1)
		{
			l->first = s->lien;
			l = l->next;
		}
		s->n_lien = count[0];
		s = s->next;
	}
	p->n_salle = count[1];
	ft_init_nlien(p);
	if (p->n_salle < 1)
		ft_error("y'a pas de salle lol\n");
}

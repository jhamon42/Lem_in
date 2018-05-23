/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:58:33 by piliegeo          #+#    #+#             */
/*   Updated: 2018/05/23 15:46:43 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_first_link(t_salle *s)
{
	t_link	*l;

	while (s)
	{
		l = s->lien;
		if (l)
			l->first = l;
		s = s->next;
	}
}


void		ft_fill_struct(t_lem *p)
{
	t_link		*t;
	t_salle		*s;
	int			count[2];

	count[1] = 0;
	s = p->sal;
	while (s)
	{
		count[1]++;
		count[0] = 0;
		t = s->lien;
		while (t)
		{
			count[0]++;
			t = t->next;
		}
		s->n_lien = count[0];
		printf("*****************il y a |%d| liens dans la salle |%s|***\n", s->n_lien, s->name);
		s = s->next;
	}
	p->n_salle = count[1];
	if (p->n_salle < 1)
		ft_error("y'a pas de salle lol\n");
	ft_first_link(p->sal);
}

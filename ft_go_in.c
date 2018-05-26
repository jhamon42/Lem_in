/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 08:01:37 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/26 07:49:22 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_go_in(t_salle *s, t_lem *p)
{
	t_link *l;

	l = s->lien;
	if (s->atrib == 1)
	{
		s = s->end;
		p->ok = 1;
	}
	if (s->statu == -1)
		return (0);
	p->ct_lien++;
	while (s->lien)
	{
		if (s->n_lien >= p->ct_lien)
			s->n_lien = p->ct_lien;
		s->statu = -1;
		ft_go_in(s->lien->link, p);
		s->lien = s->lien->next;
	}
	p->ct_lien--;
	s->lien = l;
	if (p->ok && s->atrib == 2)
		return (1);
	return (0);
}

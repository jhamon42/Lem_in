/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plc_frmi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:31:48 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/26 10:51:33 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_prt_fr(t_salle *s, t_lem *p, int *a)
{
	static int f = 1;
	t_link *l;

	l = s->lien;
	if (s->atrib == 2 || s->frmi == 0)
	{
		if (l->link->atrib == 1 && f <= p->frmi)
			l->link->frmi = f++;
		if (l->link->frmi && (l->link->n_lien == s->n_lien + 1))
		{
			if (*a)
				ft_printf(" ");
			*a = 1;
			ft_printf("L%d-%s", l->link->frmi, s->name);
			s->frmi = l->link->frmi;
			l->link->frmi = 0;
			if (s->atrib == 2)
				p->frmi_arv++;
		}
	}
}

void	ft_prc_chm(t_salle *s, t_link *l, t_lem *p, int *a)
{
	t_salle *sb;
	t_link *lb;

	sb = p->sal;
	while (sb->atrib != 1)
	{
		if (sb->atrib != 2)
			sb->statu--;
		lb = sb->lien;
		while (lb)
		{
			
			lb = lb->next;
		}
	}
}

void	ft_plc_frmi(t_lem *p)
{
	int v = 0;
	int a;
	t_salle *s;
	t_link *l;

	s = p->sal; // pointe sur end
	l = p->sal->lien;
	ft_printf("\n");
	while (p->frmi_arv < p->frmi && v++ < 10)
	{
		a = 0;
		ft_prc_chm(s, s->lien, p, &a);
		s->statu--;
		ft_printf("\n");
	}
}

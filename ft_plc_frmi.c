/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plc_frmi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:31:48 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/25 18:24:26 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_prt_fr(t_salle *s, t_lem *p, int *a)
{
	static int f = 1;
	t_link *l;

	l = s->lien;
	while (l)
	{
		if (s->atrib == 2 || s->frmi == 0)
		{
			if (l->link->atrib == 1 && f <= p->frmi)
				l->link->frmi = f++;
			if (l->link->frmi && l->link->n_lien > s->n_lien)
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
		l = l->next;
	}
}

void	ft_prc_chm(t_salle *s, t_link *l, t_lem *p, int *a)
{
	t_link *lb;

	lb = l;
	//CH(2)
	while (s->atrib != 1 && l)
	{
		ft_prt_fr(s, p, a);
		if (s->statu == l->link->statu)
		{
			if (s->n_lien > l->link->n_lien)
			{
				if (s->atrib != 2)
					s->statu--;
				ft_prc_chm(l->link, l->link->lien, p, a);
				s->statu++;
			}
		}
		l = l->next;
	}
	if (s->atrib == 1)
		s = s->end;
}

void	ft_plc_frmi(t_salle *s, t_lem *p)
{
	int a;
	t_link *l;
	int v = 0;

	l = s->lien;
	ft_printf("\n");
	while (p->frmi_arv < p->frmi && v++ < 50)
	{
		a = 0;
		while (l)
		{
			//CH(1)
			ft_prc_chm(l->link, l->link->lien, p, &a);
			l = l->next;
		}
		l = s->lien;
		ft_printf("\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plc_frmi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:31:48 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/23 15:35:00 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_prt_fr(t_salle *s, t_lem *l, int a)
{
	static int f = 1;
	t_link *n;

	n = s->lien;
	//printf("nom de la salle pointer par lien = %s\n", n->link->name);
	while (n)
	{
		ft_printf("check\n");
		if (s->atrib == 2 || s->frmi == 0)
		{
			ft_printf("check1 : %s\n", s->name);
			if (n->link->atrib == 1 && f <= l->frmi)
				n->link->frmi = f++;
			if (n->link->frmi)
			{
				if (a > 1)
					ft_printf(" ");
				ft_printf("L%d-%s", n->link->frmi, s->name);
				s->frmi = n->link->frmi;
				n->link->frmi = 0;
				if (s->atrib == 2)
					l->frmi_arv++;
			}
		}
		n = n->next;
	}
}

void	ft_plc_frmi(t_salle *s, t_lem *l)
{
	int i;
	int a;

	while (l->frmi_arv < l->frmi)
	{
		a = 0;
		i = -1;
		while (++i <= l->ct_lien)
		{
			while (s->next)
			{
				CH
				if (s->n_lien == i)
					ft_prt_fr(s, l, ++a);
				s = s->next;
			}
			s = s->first;
			ft_printf("\n");
		}
		l->frmi_arv++;
	}
}

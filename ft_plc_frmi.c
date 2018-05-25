/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plc_frmi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:31:48 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/25 16:11:49 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_prt_fr(t_salle *s, t_lem *l, int *a)
{
	static int f = 1;
	t_link *n;

	n = s->lien;
	while (n)
	{
		if (s->atrib == 2 || s->frmi == 0)
		{
			if (n->link->atrib == 1 && f <= l->frmi)
				n->link->frmi = f++;
			if (n->link->frmi && n->link->n_lien > s->n_lien)
			{
				if (*a)
					ft_printf(" ");
				*a = 1;
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

	ft_printf("\n");
	while (l->frmi_arv < l->frmi)
	{
		a = 0;
		i = 0;
		while (++i <= l->n_salle)
		{
			while (s->next)
			{
				if (s->n_lien == i && s->statu == -1)
					ft_prt_fr(s, l, &a);
				s = s->next;
			}
			s = s->first;
		}
		ft_printf("\n");
	}
}

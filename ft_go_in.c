/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 08:01:37 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/21 17:12:12 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int ft_go_in(t_salle *p, t_lem *l)
{
	int n;

	n = -1;
	if (p->n_lien == 1 && !p->atrib)
		return (0);
	if (p->atrib == 2)
		return (1);
	while (++n < p->n_lien)
	{
		if (!p->lien[n]->statu)
		{
			l->n_lien++;
			if (ft_go_in(p->lien[n], l))
			{
				if (l->n_lien_2 <= l->n_lien)
					l->n_lien_2 = l->n_lien;
				p->statu = l->n_chmn++;
				return (0);
			}
			l->n_lien--;
		}
	}
	return (0);
}

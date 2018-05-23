/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 08:01:37 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/23 15:25:58 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_go_in(t_salle *p, t_lem *l)
{
	if (p->atrib == 1)
		return (l->ok = 1);
	if (p->statu == -1 || !p->lien)
		return (0);
	while (p->lien)
	{
		if (p->n_lien > l->ct_lien)
			p->n_lien = l->ct_lien++;
		p->statu = -1;
		ft_go_in(p->lien->link, l);
		p->statu = 0;
		p->lien = p->lien->next;
	}
	if (l->ok)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 06:19:57 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/20 08:20:40 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



int main(void)
{
	t_lem stct;
	t_lem *p;
	char *line;
	int i;

	p = &stct;
	ft_bzero(p, 2);
	i = 0;
	while (get_next_line(0, &line))
	{
		if (ft_h_tag(line, p)) // pour verif les comm et les cmd
		{
			if (i != 0)
			{
				/*
				**on recup d'abort les salles {nom coord_x coord_y},
				**puis pour les liens. {nom1-nom2}
				*/
				if (!line)
					break; //normalment si il n'y a pas de line c'est fini
			}
			if (++i == 1 /*on recup le nombre de fourmis*/)
				p->frmi = ft_atoi(line);
			else
				exit(1); //normalment on peux exit aven quand on trouve l'erreur, mais c'est pour la comprention
		}
		ft_memdel((void *)&line);
	}
	ft_go_in(p);
	return (0);
}
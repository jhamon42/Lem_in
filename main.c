/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 06:19:57 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/23 15:25:56 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int last_check(t_lem *p)
{
	if (p)
		;
	return (0);
}


void    ft_error(char *str)
{
        ft_putstr_fd(str, 2);
        exit(EXIT_FAILURE);
}


int main(void)
{
	t_lem stct;
	t_lem *p;
	t_link *t;
	char *line;
	int i;

	p = &stct;
	ft_bzero(p, sizeof(t_lem));
	i = 0;
	p->check = 0;
	while (get_next_line(0, &line))
	{
		if (p->check == 1 || p->check == 2)
		{
			if (ft_get_data(line, p) == -1)
				break ;
		}
		else if (ft_h_tag(line, p) == -1)
			break ;
		ft_memdel((void *)&line);
	}
	ft_fill_struct(p);
	t = p->sal->lien->first;
	if (ft_go_in(p->sal, p)) // p->sal pointe sur end
	{
		//printf("ok\n");
		p->sal->lien = t;
		ft_plc_frmi(p->sal, p);
	}
	else
		ft_printf("pas de soluce\n");
	return (0);
}
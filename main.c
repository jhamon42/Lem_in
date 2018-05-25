/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 06:19:57 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/25 18:12:33 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void ft_this_is_the_end(t_lem *p)
{
	t_salle *s;

	if (p)
	{
		while (p->sal)
		{
			if (p->sal->atrib == 2)
				break;
			else
				p->sal = p->sal->next;
		}
		s = p->sal;
		p->sal = p->sal->first;
		while (p->sal->next)
		{
			p->sal->end = s;
			p->sal = p->sal->next;
		}
		p->sal->end = s;
		p->sal = p->sal->end;
	}
}

void    ft_error(char *str)
{
        ft_putstr_fd(str, 2);
        exit(EXIT_FAILURE);
}

void 	ft_reset_lien(t_lem *p)
{
	t_salle *s;

	p->sal = p->sal->first;
	s = p->sal;
	if (s)
	{
		while (s)
		{
			if (s->lien)
				s->lien = s->lien->first;
			s = s->next;
		}
	}
	p->sal = p->sal->end;
}

void	ft_check_params(t_lem *p)
{
	t_lem *pb;
	t_salle *sb;
	t_link *lb;

	pb = p;
	N
	ft_printf("-------------------------------------------------\n");
	if (pb)
	{
		ft_printf("--- struct p : %p ---\n", pb);
		ft_printf("frmi = %d\n", pb->frmi);
		ft_printf("frmi_arv = %d\n", pb->frmi_arv);
		ft_printf("start = %d\n", pb->start);
		ft_printf("end = %d\n", pb->end);
		ft_printf("ct_lien = %d\n", pb->ct_lien);
		ft_printf("n_chmn = %d\n", pb->n_chmn);
		ft_printf("n_lien_max = %d\n", pb->n_lien_max);
		ft_printf("n_salle = %d\n", pb->n_salle);
		ft_printf("ok = %d\n", pb->ok);
		ft_printf("check = %d\n", pb->check);
		ft_printf("sal_head = %p\n", pb->sal);
		sb = p->sal;
		while (sb)
		{
			N
			ft_printf("	--- struct p->sal : %p ---\n", sb);
			ft_printf("	name = %s\n", sb->name);
			ft_printf("	statu = %d\n", sb->statu);
			ft_printf("	n_lien = %d\n", sb->n_lien);
			ft_printf("	atrib = %d\n", sb->atrib);
			ft_printf("	frmi = %d\n", sb->frmi);
			ft_printf("	next = %p\n", sb->next);
			ft_printf("	prev = %p\n", sb->prev);
			ft_printf("	first = %p\n", sb->first);
			lb = sb->lien;
			while (lb)
			{
				N
				ft_printf("		--- struct p->sal->lien : %p ---\n", lb);
				ft_printf("		link = %p\n", lb->link);
				if (lb->link)
					ft_printf("		link->name = %s\n", lb->link->name);
				ft_printf("		next = %p\n", lb->next);
				ft_printf("		first = %p\n", lb->first);
				lb = lb->next;
			}
			sb = sb->next;
			ft_printf("	----------------------------------------\n");
		}
	}
}

int main(void)
{
	t_lem stct;
	t_lem *p;
	char *line;
	int i;

	p = &stct;
	ft_bzero(p, sizeof(t_lem));
	i = 0;
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
	CH(9)
	ft_fill_struct(p);
//	N
//	ft_check_params(p);
	ft_this_is_the_end(p);
	CH(0)
	if (ft_go_in(p->sal, p))
	{
		ft_reset_lien(p);
		ft_check_params(p);
		ft_plc_frmi(p->sal, p);
	}
	else
		ft_printf("pas de soluce\n");
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piliegeo <piliegeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:51:12 by piliegeo          #+#    #+#             */
/*   Updated: 2018/05/22 19:31:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			ft_next_data(char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	return (i);
}

static	int			ft_check_same_name(char *str, t_lem *p)
{
	t_salle *s;

	s = p->sal;
	while (s)
	{
		if (ft_strcmp(s->name, str) == 0)
		return (1);
		s = s->next;
	}
	return (0);
}

static void			ft_creat_room(char *str, t_lem *p)
{
	t_salle		*new;

	if (ft_check_same_name(ft_strsub(str, 0, ft_next_data(str, ' ')), p))
		ft_error("meme nom de room ....\n");
	new = ft_memalloc(sizeof(t_salle));
	new->name = ft_strsub(str, 0, ft_next_data(str, ' '));
	if (p->check)
	{
		new->atrib = p->check == 1? 1 : 2;
		p->check = 0;
	}
	else
		new->atrib = 0;
	new->next = NULL;
	new->prev = NULL;
	new->lien = NULL;
	if (p->sal == NULL)
	{
		p->sal = new;
		p->sal->first = p->sal;
	}
	else
	{
		new->next = p->sal;
		p->sal->prev = new;
		p->sal = new;
	}
	printf("nom de la salle = %s et entre ou sortie = %d\n", new->name, new->atrib);
}

static void			ft_get_nb_frmi(char *str, t_lem *p)
{
	size_t i;
	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (i != ft_strlen(str))
		ft_error("nimp dans comptage fourmi\n");
	p->frmi = ft_atoi(str);
	if (p->frmi < 1)
		ft_error("Envoie des fourmis allo\n");
	if (p->frmi > 10000000)
		ft_error("Abuse pas non plus ...\n");


	printf("p->frmi = %d\n", p->frmi);
}

int			ft_get_data(char *str, t_lem *p)
{
	int		i;
	char	*tmp;

	i = 1;
	if (str[0] && str[1] && str[0] == '#' && str[1] == '#')
		ft_error("tu fais nimp avec les cmd\n");
	else if (str[0] && str[0] == '#')
		return (0);
	else if (str && ft_charnumb(str, ' ') != 2)
	{
		printf("tenvoies de la merde apres un ##start ou ##end\n");
		return (-1);
	}
	tmp = ft_strstr(str, " ");
	while (tmp[i] && ft_isdigit(tmp[i]))
		i++;
	if (!tmp[i] || tmp[i] != ' ')
		ft_error("mauvaise data room1\n");
	i++;
	while (tmp[i] && ft_isdigit(tmp[i]))
		i++;
	if (tmp[i])
		ft_error("mauvaise data room2\n");
	ft_creat_room(str, p);
	return (0);
}

static void			ft_check_cmd(char *str, t_lem *p)
{
	if (ft_strcmp(str, "##start") == 0)
		p->check = 1;
	else if (ft_strcmp(str, "##end") == 0)
		p->check = 2;
}

static void			ft_creat_link(t_salle *s1, t_salle *s2)
{
	printf("JE CREE UN LIEN entre la salle %s et %s\n", s1->name, s2->name);


	t_link	*new1;
	t_link	*new2;

	new1 = ft_memalloc(sizeof(t_link));
	new1->next = s1->lien;
	s1->lien = new1;
	new1->link = s2;

	new2 = ft_memalloc(sizeof(t_link));
	new2->next = s2->lien;
	s2->lien = new2;
	new2->link = s1;
	printf("address de s1 pointe vers %s\n", new1->link->name);
	printf("address de s2 pointe vers %s\n", new2->link->name);
}

static int			ft_read_link(char *str, t_lem *p)
{
	t_salle		*s1;
	t_salle		*s2;
	char		*tmp[2];

	s1 = p->sal;
	s2 = p->sal;
	tmp[0] = ft_strsub(str, 0, ft_next_data(str, '-'));
	tmp[1] = ft_strsub(str, ft_next_data(str, '-') + 1, ft_strlen(str));
	if (ft_strcmp(tmp[0], tmp[1]) == 0)
	{
		printf("TU MENVOIES UN LIEN VERS LA MEME SALLE TDB\n");
		free(tmp[0]);
		free(tmp[1]);
		return (-1);
	}
	printf("tmp 0 = %s && tmp 1 = %s\n", tmp[0], tmp[1]);

	while (s1->next && ft_strcmp(s1->name, tmp[0]))
		s1 = s1->next;
	printf("nom s1 = %s\n", s1->name);
	while (s2->next && ft_strcmp(s2->name, tmp[1]))
		s2 = s2->next;
	printf("noms2 = %s\n", s2->name);
	if (ft_strcmp(s1->name, tmp[0]) || ft_strcmp(s2->name, tmp[1]))
	{
		printf("T'AS MIS UN MAUVAIS NOM DE SALLE DEBILE DONC JE BREAK LE GNL ET ON VOIT CE QUON FAIT\n");
		free(tmp[0]);
		free(tmp[1]);
		return (-1);
	}

	printf("JE CREE UN LIEN entre la salle %s et %s\n", s1->name, s2->name);
	ft_creat_link(s1, s2);
	free(tmp[0]);
	free(tmp[1]);
	return (0);
}
/*
 * check 1 ou 2 = start end
 * check 5 = lecture de salle apres avoir lu des liens
 * */
int					ft_h_tag(char *str, t_lem *p)
{
	static int frmi = 0;

	if (!str[0] || str[0] == '\n')
		return (-1);
	if (str[0] && str[1] && str[0] == '#' && str[1] == '#')
	{
		if (frmi == 0)
			ft_error("cmd avant le nbr de fourmis... really?\n");
		else
			ft_check_cmd(str, p);
	}
	else if (str[0] && str[0] == '#')
		return (0);
	else if (frmi == 0)
	{
		ft_get_nb_frmi(str, p);
		frmi = 1;
	}
	else if (ft_charnumb(str, ' ') == 2)
	{
		if (p->check == 3)
		{
			ft_putstr("envoie de salle apres avoir envoyedes liens#######################\n");
			return (-1);
		}
		if (ft_get_data(str, p) < 0)
			return (-1);
	}
	else if (ft_charnumb(str, ' ') == 0 && ft_charnumb(str, '-') == 1)
	{
		p->check = 3;
		if (ft_read_link(str, p) < 0)
			return (-1);
	}
	else
	{
		printf("TA ENVOYE DE LA MERDE DONC JE BREAK LE GNL");
		return (-1);
	}
	return (0);
}

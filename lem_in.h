/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 06:20:32 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/21 16:53:22 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct	s_salle
{
	char *name;
	int statu; // -1 fade, 0 : normal, 1 : ok chemin1 2 : ok chemin2, ...
	int n_lien; // nombre de liens
	int atrib; // 1 : start, 2 : end, 0 : salle
	struct s_salle **lien; // tableau d'adresse des liens
	struct s_salle *next;
	struct s_salle *betw;
}				t_salle;

typedef struct	s_lem
{
	int frmi; // nbr de fourmis
	int start; // pour signaler que la prochaine salle est la start
	int end; // pour signaler que la prochaine salle est la end
	int n_lien; // nb de lien pour un chemin
	int n_chmn; // nb de chemin
	int n_lien_2; // pour compare
	t_salle *sal;
}				t_lem;

int ft_h_tag(char *line, t_lem *p);
int ft_go_in(t_salle *p, t_lem *l);

#endif

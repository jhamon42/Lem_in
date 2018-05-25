/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 06:20:32 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/25 15:34:09 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

#define CH(X) ft_printf("CHECK %d\n", X);
#define PTR(X) ft_printf("%p\n", X);
#define NAME(X) ft_printf("salle : %s\n", X);
#define NB(X) ft_printf("%d\n", X);
#define N ft_printf("\n");

typedef struct	s_link
{
	struct s_salle	*link;
	struct s_link	*next;
	struct s_link	*first;
}				t_link;

typedef struct	s_salle
{
	char *name;
	int statu; // -1 fade, 0 : normal
	int n_lien; // nombre de liens
	int atrib; // 1 : start, 2 : end, 0 : salle
	int frmi; // 1 ou plus : nom de la frmi 0: pas frmi
	struct s_link *lien; // tableau d'adresse des liens
	struct s_salle *next;
	struct s_salle *prev;
	struct s_salle *first;
	struct s_salle *end;
}				t_salle;

typedef struct	s_lem
{
	int frmi; // nbr de fourmis
	int frmi_arv; // nbr de fourmis arriver
	int start; // pour signaler que la prochaine salle est la start
	int end; // pour signaler que la prochaine salle est la end
	int ct_lien; // nb de lien pour un chemin
	int n_chmn; // nb de chemin
	int n_lien_max; // pour co
	int n_salle;
	int ok;
	int	check;
	t_salle *sal;
}				t_lem;

int 	ft_h_tag(char *line, t_lem *p);
int 	ft_go_in(t_salle *s, t_lem *p);
int		ft_get_data(char *str, t_lem *p);
void	ft_fill_struct(t_lem *p);
void	ft_error(char *str);
void	ft_plc_frmi(t_salle *p, t_lem *l);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 10:33:41 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/12 17:46:00 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

# define HASH_SZ 1009
# define BUF_SZ 125

typedef enum				e_etat
{
	ETAT_FOURMI,
	ETAT_SALLE,
	ETAT_TUBE
}							t_etat;

typedef struct				s_room
{
	int						ant;
	int						lvl;
	int						path;
	char					name[BUF_SZ + 1];
	struct s_room			**child;
	int						child_nb;
	int						nb_max;
}							t_room;

typedef struct				s_hashlist
{
	struct s_hashlist		*next;
	t_room					*room;
}							t_hashlist;

typedef struct				s_hashtable
{
	t_hashlist				*tab[HASH_SZ];
}							t_hashtable;

typedef struct				s_struct
{
	t_room					*start;
	t_room					*end;
	int						ant_total;
	int						flag;
	char					*input;
}							t_struct;

typedef struct				s_node
{
	t_room					*room;
	struct s_node			*next;
}							t_node;

int							ft_get_ant(char *line, t_struct *pos);
int							ft_get_room(char *line, t_struct *pos, t_hashtable
																*hashtable);
int							ft_get_tube(char *line, t_hashtable *hashtable);
int							ft_get_com(char *line, t_struct *pos);
t_struct					*ft_get_infos(t_hashtable *hashtable,
																t_struct *pos);
t_room						*ft_parse_room(t_room *room, char *line,
													t_hashtable *hashtable);
int							ft_hash(char *name);
t_room						*hash_get(t_hashtable *hashtable, char *name);
t_hashtable					*hash_create(void);
void						hash_delete(t_hashtable *hashtable);
t_hashlist					*ft_new_hashlist(t_room *room);
t_struct					*lem_in(t_struct *pos);
void						delete_queue(t_node **node);
t_node						*add_queue(t_node *node, t_room *room);
void						move_ants(t_struct *pos);

#endif

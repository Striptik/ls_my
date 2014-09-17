/*
** liste.h for liste.h in /home/loisel_k/travail/Librairie/liblistec/doubchaine
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Nov  2 12:28:15 2013 kevin loiseleur
** Last update Sun Dec  1 20:05:46 2013 kevin loiseleur
*/

#ifndef LISTE_H_
# define LISTE_H_

typedef struct		s_dlc
{
  void			*data;
  struct s_dlc		*next;
  struct s_dlc		*prev;
}			t_dlc;

typedef struct		s_pos
{
  t_dlc			*pbeg;
  t_dlc			*pend;
  int			size;
}			t_pos;

/*
** INITIALISATION
*/

void			init_list(t_pos *);
t_dlc			*create_list(const void *);

/*
** INSERTION ELEMENT
*/

int			ins_elem(t_pos *, void *, int);
int			ins_elem_empty_list(t_pos *, void *);
int			ins_elem_beg_list(t_pos *, void *);
int			ins_elem_end_list(t_pos *, void *);
int			ins_before_elem(t_pos *, void *, int);
int			ins_after_elem(t_pos *, void *, int);

/*
** SUPPRESSION ELEMENT
*/

int			del_elem(t_pos *, int);
void			del_first_elem(t_pos *);
void			del_last_elem(t_pos *);
void			del_N_elem(t_pos *, int);

/*
** AFFICHAGE LISTE
*/

void			disp_list(t_pos *);
void			rev_disp_list(t_pos *);

/*
** SUPPRESSION LISTE
*/

void			del_list(t_pos *);

/*
** OUTILS LISTE
*/

unsigned int		lenght_list(t_pos *list);
t_pos			*search_elem_in_list(t_pos *list, void *data);
t_pos			*search_elems_in_list(t_pos *list, void *data);
t_pos			*reverse_list(t_pos *list);

#endif /* LISTE_H_ */

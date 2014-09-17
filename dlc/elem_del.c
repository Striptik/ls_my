/*
** del_elem.c for del_elem in /home/loisel_k/travail/Librairie/liblistec/doubchaine
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Mon Nov  4 14:39:20 2013 kevin loiseleur
** Last update Sat Nov 30 14:39:27 2013 kevin loiseleur
*/

#include <stdlib.h>
#include "liste.h"

int			del_elem(t_pos *list, int pos)
{
  if (list->size == 0)
    return (-1);
  else if (pos == 1)
    del_first_elem(list);
  else if (pos == list->size)
    del_last_elem(list);
  else
    del_N_elem(list, pos);
  return (0);
}

void			del_first_elem(t_pos *list)
{
  t_dlc			*del_elem;

  del_elem = list->pbeg;
  list->pbeg = list->pbeg->next;
  if (list->pbeg == NULL)
    list->pend = NULL;
  else
    list->pbeg->prev = NULL;
  free(del_elem->data);
  free(del_elem);
  list->size--;
  return ;
}

void			del_last_elem(t_pos *list)
{
  t_dlc			*del_elem;

  del_elem = list->pend;
  list->pend->prev->next = NULL;
  list->pend = list->pend->prev;
  free(del_elem->data);
  free(del_elem);
  list->size--;
  return ;
}

void			del_N_elem(t_pos *list, int pos)
{
  t_dlc			*del_elem;
  t_dlc			*current_elem;
  int			i;

  i = 1;
  current_elem = list->pbeg;
  while (i < pos)
    {
      current_elem = current_elem->next;
      i++;
    }
  del_elem = current_elem;
  current_elem->prev->next = current_elem->next;
  current_elem->next->prev = current_elem->prev;
  free(del_elem->data);
  free(del_elem);
  list->size--;
  return ;
}

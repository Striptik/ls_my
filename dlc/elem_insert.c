/*
** insert_elem.c for inserer un element dans la liste in /home/loisel_k/travail/Librairie/liblistec/doubchaine
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Nov  2 17:57:37 2013 kevin loiseleur
** Last update Sat Nov 30 14:39:26 2013 kevin loiseleur
*/

#include <stdlib.h>
#include "liste.h"

int			ins_elem(t_pos *list, void *data, int pos)
{
  t_dlc			*new_elem;

  if (list->size == 0)
    ins_elem_empty_list(list, data);
  else if (pos > list->size)
    {
      return (-1);
      my_putst("Mauvaise position connard");
    }
  else if (pos == 1)
    ins_elem_beg_list(list, data);
  else if (pos == list->size)
    ins_elem_end_list(list, data);
  else
    ins_before_elem(list, data, pos);
  return (0);
}

int			ins_elem_empty_list(t_pos *list, void *data)
{
  t_dlc			*new_elem;

  if (!(new_elem = malloc(sizeof(*new_elem))))
    return (-1);
  new_elem->data = data;
  new_elem->next = list->pbeg;
  new_elem->prev = list->pend;
  list->pbeg = new_elem;
  list->pend = new_elem;
  list->size++;
  return (0);
}

int			ins_elem_beg_list(t_pos *list, void *data)
{
  t_dlc			*new_elem;

  if (!(new_elem = malloc(sizeof(*new_elem))))
    return (-1);
  new_elem->data = data;
  new_elem->prev = NULL;
  new_elem->next = list->pbeg;
  list->pbeg->prev = new_elem;
  list->pbeg = new_elem;
  list->size++;
  return (0);
}

int			ins_elem_end_list(t_pos *list, void *data)
{
  t_dlc			*new_elem;

  if (!(new_elem = malloc(sizeof(*new_elem))))
    return (-1);
  new_elem->data = data;
  new_elem->next = NULL;
  new_elem->prev = list->pend;
  list->pend->next = new_elem;
  list->pend = new_elem;
  list->size++;
  return (0);
}

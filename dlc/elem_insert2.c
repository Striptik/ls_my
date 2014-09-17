/*
** insert_elem2.c for suite insertion element in /home/loisel_k/travail/Librairie/listech/doubchaine/dlc
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Nov  5 00:58:38 2013 kevin loiseleur
** Last update Sat Nov 30 14:39:25 2013 kevin loiseleur
*/

#include <stdlib.h>
#include "liste.h"

int			ins_before_elem(t_pos *list, void *data, int pos)
{
  int			i;
  t_dlc			*new_elem;
  t_dlc			*current_elem;

  i = 1;
  if (!(new_elem = malloc(sizeof(*new_elem))))
    return (-1);
  new_elem->data = data;
  current_elem = list->pbeg;
  while (i < pos)
    {
      current_elem = current_elem->next;
      i++;
    }
  new_elem->next = current_elem;
  new_elem->prev = current_elem->prev;
  if (current_elem->prev == NULL)
    list->pbeg = new_elem;
  else
    current_elem->prev->next = new_elem;
  current_elem->prev = new_elem;
  list->size++;
  return (0);
}

int			ins_after_elem(t_pos *list, void *data, int pos)
{
  int			i;
  t_dlc			*new_elem;
  t_dlc			*current_elem;

  i = 1;
  if (!(new_elem = malloc(sizeof(*new_elem))))
    return (-1);
  new_elem->data = data;
  current_elem = list->pbeg;
  while (i < pos)
    {
      current_elem = current_elem->next;
      i++;
    }
  new_elem->next = current_elem->next;
  new_elem->prev = current_elem;
  if (current_elem->next == NULL)
    list->pend = new_elem;
  else
    current_elem->next->prev = new_elem;
  current_elem->next = new_elem;
  list->size++;
  return (0);
}

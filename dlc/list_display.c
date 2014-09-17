/*
** display_list.c for affichage de la liste in /home/loisel_k/travail/Librairie/listech/doubchaine
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Mon Nov  4 16:09:42 2013 kevin loiseleur
** Last update Sat Nov 30 14:39:27 2013 kevin loiseleur
*/

#include <stdlib.h>
#include "liste.h"

void		my_put(char c)
{
  write(1, &c, 1);
}

int		my_strlent(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void		my_putst(char *str)
{
  write(1, str, my_strlent(str));
}

void		disp_list(t_pos *list)
{
  t_dlc		*current_elem;

  current_elem = list->pbeg;
  while (current_elem != NULL)
    {
      my_putst(current_elem->data);
      my_put('\n');
      current_elem = current_elem->next;
    }
  return ;
}

void		rev_disp_list(t_pos *list)
{
  t_dlc		*current_elem;

  current_elem = list->pend;
  while (current_elem != NULL)
    {
      my_putst(current_elem->data);
      my_put('\n');
      current_elem = current_elem->prev;
    }
  return ;
}

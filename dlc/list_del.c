/*
** del_list.c for supprimer une liste in /home/loisel_k/travail/Librairie/listech/doubchaine
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Mon Nov  4 16:44:00 2013 kevin loiseleur
** Last update Sat Nov 30 04:24:59 2013 kevin loiseleur
*/

#include "liste.h"

void			del_list(t_pos *list)
{
  while (list->size > 0)
    del_elem(list, 1);
  return ;
}

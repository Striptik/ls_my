/*
** init_list.c for initialisation liste in /home/loisel_k/travail/Librairie/liblistec/doubchaine
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Nov  2 17:53:40 2013 kevin loiseleur
** Last update Sat Nov 30 14:34:09 2013 kevin loiseleur
*/

#include <stdlib.h>
#include "liste.h"

void			init_list(t_pos *list)
{
  list->pbeg = NULL;
  list->pend = NULL;
  list->size = 0;
}

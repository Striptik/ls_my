/*
** tools_element.c for tools for manipulations of the list in /home/loisel_k/travail/Librairie/listech/doubchaine/dlc
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Nov 30 14:22:44 2013 kevin loiseleur
** Last update Sun Dec  1 20:04:55 2013 kevin loiseleur
*/

#include <stdlib.h>
#include "liste.h"

unsigned int	       lenght_list(t_pos *list)
{
  unsigned int	       ret;

  ret = 0;
  if (list)
    ret = list->size;
  return (ret);
}


t_pos			*search_elem_in_list(t_pos *list, void *data)
{
  t_pos			*ret_list;
  t_dlc			*current_elem;
  int			found;

  ret_list = NULL;
  if (list)
    {
      current_elem = list->pbeg;
      found = 0;
      while (current_elem && !found)
	{
	  if (current_elem->data == data)
	    {
	      init_list(ret_list);
	      if ((ins_elem(ret_list, data, 1)) == -1)
		return (NULL);
	      found == 1;
	    }
	  else
	    current_elem = current_elem->next;
	}
    }
  return (ret_list);
}

t_pos			*search_elems_in_list(t_pos *list, void *data)
{
  t_pos			*ret_list;
  t_dlc			*current_elem;
  int			pos;

  pos = 1;
  ret_list = NULL;
  if (list)
    {
      current_elem = list->pbeg;
      while (current_elem)
	{
	  if (current_elem->data == data)
	    {
	      if (!ret_list)
		init_list(ret_list);
	      if ((ins_elem(ret_list, data, pos)) == -1)
		return (NULL);
	      pos++;
	    }
	  current_elem = current_elem->next;
	}
    }
  return (ret_list);
}

t_pos			*reverse_list(t_pos *list)
{
  t_pos			*rev_list;
  t_dlc			*current_elem;

  rev_list = NULL;
  if (list)
    {
      current_elem = list->pend;
      init_list(rev_list);
      while (current_elem)
	{
	  ins_elem(rev_list, current_elem->data, 1);
	  current_elem = current_elem->prev;
	}
    }
  return (rev_list);
}

void			*list_current(t_pos *list)
{
  if (!list || !(list->pbeg))
    return (NULL);
  return (list->pbeg);
}


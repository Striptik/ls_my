/*
** ls_aff.c for aff opt in /home/loisel_k/travail/Systeme-Unix/my_ls/src
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sun Dec  1 19:56:08 2013 kevin loiseleur
** Last update Sun Dec  1 19:59:03 2013 kevin loiseleur
*/

#include <stdlib.h>
#include "../include/my_ls.h"
#include "../include/my.h"
#include "../include/liste.h"

void			gere_aff_options(t_lsopt *opt_path, t_pos *list)
{
  t_pos			*tmp;

  init_list(tmp);
  if (list == NULL)
      return ;
  if (opt_path->opt_d == Y)
    {
     tmp = gere_opt_d(opt_path, list);
      return ;
    }
  else if (opt_path->opt_R == N)
    {
      if (opt_path->opt_r == Y)
	tmp = gere_opt_r(opt_path, list);
    }
  else
    {
      my_printf("je ne gere pas la recursivite\n\n\nDesole ...\n");
      return ;
    }
  aff_ls(opt_path, tmp);
  return ;
}

void			aff_ls(t_lsopt *opt_path, t_pos *tmp)
{
  if (opt_path->opt_l == Y)
    {
      my_printf("%c%s %d% %s %s %d %s %s\n", tmp->pbeg->data->mode,
	  tmp->pbeg->data->right, tmp->pbeg->data->NbLkH,
	  tmp->pbeg->data->uid, tmp->data->pbeg->gid,
	  tmp->pbeg->data->size, tmp->pbeg->data->time
	  tmp->pbeg->data->name);
    }
  else
    my_printf("%s\n", tmp->pbeg->data->name);
  return ;
}

t_pos			*gere_opt_r(t_lsopt *opt_path, t_pos *list)
{
  t_pos			*tmp;

  init_list(tmp);
  tmp = reverse_list(list);
  return (tmp);
}

t_pos			*gere_opt_d(t_lsopt *opt_path, t_pos *list)
{
  t_pos			*tmp;

  init_list(tmp);
  tmp = search_elem_in_list(list, ".");
  return (tmp);
}

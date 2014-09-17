/*
** my_ls.c for my_ls main fonction in /home/loisel_k/travail/Systeme-Unix/my_ls/src
**
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
**
** Started on  Sat Nov 30 18:01:39 2013 kevin loiseleur
** Last update Sun Dec  1 19:59:12 2013 kevin loiseleur
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include "../include/liste.h"
#include "../include/my_ls.h"
#include "../include/my.h"

int			my_ls(int ac, char **av)
{
  t_lsopt		*opt_path;
  t_pos			*list;
  int			i;

  i = 0;
  if (!(opt_path = malloc(sizeof(*opt_path))))
    {
      my_printf("Error on Malloc\n");
      return (ERROR);
    }
  if (ac = 1)
    my_ls_only(opt_path, ac);
  else
    {
      opt_path = lex_options_path(ac, av);
      while (opt_path->path[i])
	{
	  init_list(list);
	  list = my_ls_parser(path[i++]);
	  gere_aff_options(opt_path, list);
	  del_list(list);
	  i++;
	}
    }
  return (SUCCES);
}

void			my_ls_only(t_lsopt *opt_path, int ac)
{
  t_pos			*list;

  init_lsopt(opt_path, ac);
  opt_path->path[0][0] = ".";
  init_list(list);
  gere_aff_options(opt_path, list);
  del_list(list);
  return ;
}

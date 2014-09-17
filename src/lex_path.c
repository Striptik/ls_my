/*
** lex_path.c for lexer main and path in /home/loisel_k/travail/Systeme-Unix/my_ls/src
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Nov 30 22:33:53 2013 kevin loiseleur
** Last update Sat Nov 30 22:42:28 2013 kevin loiseleur
*/

#include <stdlib.h>
#include "../include/my_ls.h"

t_lsopt			*lex_options_path(int ac, char *av)
{
  char			*path;
  t_lsopt		*opt_path;

  if (ac > 2)
    {
      init_lsopt(opt_path, ac);
      what_options(av, ac, opt_path);
      what_paths(av, ac, opt_path);
    }
}

void			init_lsopt(t_lsopt *opt_path, int ac)
{
  if (!(opt_path->path = malloc(sizeof(char *) * ac)))
    {
      my_printf("Error on Malloc\n");
      exit(3);
    }
  opt_path->opt_l = N;
  opt_path->opt_R = N;
  opt_path->opt_d = N;
  opt_path->opt_r = N;
  opt_path->opt_t = N;
  return ;
}

void			what_paths(char **av, int ac, t_lsopt *opt_path)
{
  int			i;

  i = 1;
  while (av && av[i])
    {
      if (av[i][0] != '-')
	assign_paths(opt_path, av[i]);
      i++;
    }
  return ;
}


void			assign_paths(t_lsopt *opt_path, char *path)
{
  int			i;
  int			j;
  static int		ac = 0;
  char			*tmp;

  i = 0;
  if (!(tmp = malloc(sizeof(char) * my_strlen(path))))
    {
      my_printf("Error on Malloc\n");
      exit(3);
    }
  while (path[i])
    tmp[i] = path[i++];
  opt_path->path[j] = tmp;
  j++;
  free(tmp);
  return ;
}

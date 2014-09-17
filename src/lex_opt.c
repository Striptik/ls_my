/*
** lex_opt.c for lexer suit and options in /home/loisel_k/travail/Systeme-Unix/my_ls/src
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Nov 30 22:40:34 2013 kevin loiseleur
** Last update Sun Dec  1 20:47:25 2013 kevin loiseleur
*/

#include <stdlib.h>
#include "../include/my_ls.h"

void			what_options(char **av, int ac, t_lsopt *opt_path)
{
  int			i;
  int			j;

  i = 1;
  while (av && av[i])
    {
      if (av[i][0] = '-')
	{
	  j = 1;
	  while (av[i][j])
	    {
	      assign_options(opt_path, av[i]);
	      j++;
	    }
	}
      i++;
    }
}

void			assign_options(t_lsopt *opt_path, char *opt)
{
  char			*opt_avaible[NB_OPT + 1];
  int			i;
  int			j;

  i = 1;
  opt_avaible = "lRdrt";
  opt_avaible[NB_OPT + 1] = 0;
  while (opt[i])
    {
      j = 0;
      while(opt_avaible[j] && opt_avaible[j] != opt[i])
	j++;
      if (!(opt_avaible[j]))
	{
	  my_printf("ls: invalid option -- '%c'\n", opt[i]);
	  exit(3);
	}
      else
	moove_lsopt(path_opt, opt[i]);
      i++;
    }
  return ;
}

void			moove_lsopt(t_lsopt *opt_path, char opt)
{
  if (opt == 'l')
    opt_path->opt_l = Y;
  else if (opt == 'R')
    opt_path->opt_R = Y;
  else if (opt == 'd')
    opt_path->opt_d = Y;
  else if (opt == 'r')
    opt_path->opt_r = Y;
  else if (opt == 't')
    opt_path->opt_t = Y;
  return ;
}

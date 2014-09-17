/*
** my_files.c for my_files in /home/loisel_k/travail/Systeme-Unix/my_ls/TP
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Nov 27 12:57:03 2013 kevin loiseleur
** Last update Fri Nov 29 00:53:16 2013 kevin loiseleur
*/

#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/my_ls.h"

int		*my_files(const char *name)
{
  DIR		*dir;
  t_dirent	*element;
  int		nb_files;

  nb_files = 0;
  if (!(dir = my_opendir(name)))
    return (0);
  while ((element = my_readdir(dir)))
    {
      if (element->d_name[0] != '.')
	my_printf("%s  ", element->d_name);
      nb_elem++;
    }
  return (nb_elem);
}

int		main(int ac, char **av)
{
  t_dirent	*element;
  DIR		*dir;
  int		res;

  if (ac == 1)
    my_files(".");
  else
    my_files(av[1]);
  if ((res = my_closedir(dir)) != 0)
    return (-1);
  return (0);
}

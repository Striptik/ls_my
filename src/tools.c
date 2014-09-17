/*
** open.c for open in /home/loisel_k/travail/Systeme-Unix/my_ls/TP
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Nov 26 17:14:36 2013 kevin loiseleur
** Last update Sun Dec  1 20:25:17 2013 kevin loiseleur
*/

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/my_ls.h"
#include "../include/my.h"

void			*my_malloc(int len)
{
  void			*data;

  data = malloc(sizeof(*data) * len);
  if (data == NULL)
    {
      my_printf("Error on Malloc\n");
      exit(3);
    }
  return (data);
}

t_dirent		*my_readdir(DIR *dir)
{
  t_dirent		*element;

  element = readdir(dir);
  if (element == NULL && errno != 0)
    {
      perror("Readdir error ");
      exit(3);
    }
  return (element);
}

int			my_closedir(DIR *dir)
{
  int			res;

  res = closedir(dir);
  if (res != 0 && errno != 0)
    {
      perror("Closedir error ");
      exit(3);
    }
  return (res);
}

int			my_stat(const char *name, t_stat *info)
{
  int			res;

  res = lstat(name, info);
  if (res != 0 && errno != 0)
    {
      perror("Stat error ");
      exit(3);
    }
  return (res);
}

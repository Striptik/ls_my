/*
** find_comp2.c for find composantes for element file 2 in /home/loisel_k/travail/Systeme-Unix/my_ls/src
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Nov 30 00:25:05 2013 kevin loiseleur
** Last update Sun Dec  1 19:59:16 2013 kevin loiseleur
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "../include/my_ls.h"
#include "../include/my.h"

t_elem		*get_info(t_elem *elem, t_dirent *element)
{
  t_stat	*info;

  if (!(info = malloc(sizeof(t_stat))))
    return (-1);
  elem->name = find_name(element);
  my_stat(elem->name, info);
  elem->mode = find_mode(info);
  elem->right = find_right(info);
  elem->NbLkH = info->st_nlink;
  elem->uid = find_uid(info);
  elem->gid = find_gid(info);
  elem->size = find_size(info);
  elem->time = find_time(info);
  free(info);
  return (elem);
}

char		*find_time(t_stat *info)
{
  char		*tmp;
  char		*time1;
  time_t	res;
  int		i;
  int		j;

  i = 4;
  j = 0;
  tmp = ctime(&info->st_mtime);
  time1 = my_malloc(13);
  while (i < 16)
    time1[j++] = tmp[i++];
  time1[j] = '\0';
  return (time1);
}

int		find_size(t_stat *info)
{
  off_t		len;
  long long int size;

  len = info->st_size;
  size = (long long int)len;
  return (size);
}

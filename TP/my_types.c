/*
** my_types.c for my_types avec stat in /home/loisel_k/travail/Systeme-Unix/my_ls/TP
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Thu Nov 28 13:11:51 2013 kevin loiseleur
** Last update Sun Dec  1 03:03:47 2013 kevin loiseleur
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include "../include/my.h"
#include "../include/my_ls.h"

int		my_ls(const char *path)
{
  DIR		*dir;
  t_dirent	*element;
  t_elem	*elem;
  t_list	*list;

  dir = my_opendir(path);
  while ((element = my_readdir(dir)))
    {
      init_elem(elem);
      elem = get_info(elem);
      list = //foutre l'elem dans la liste
    }
}

t_elem		*get_info(t_elem *elem)
{
  t_stat	*info;

  while ((element = my_readdir(dir)))
    {
      if (element->d_name[0] != '.')
	{
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
	}
    }
  return (elem);
}
/*
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

char		*find_gid(t_stat *info)
{
  struct group	*grp;
  char		*gid;
  int		i;

  i = 0;
  if (!(grp = getgrgid(info->st_gid)))
    {
      perror("Error getgrgid ");
      exit(3);
    }
  gid = my_malloc(my_strlen(grp->gr_name));
  while (grp->gr_name[i])
    gid[i] = grp->gr_name[i++];
  gid[i] = '\0';
  return (gid);
}

char		*find_uid(t_stat *info)
{
  struct passwd *pwd;
  char		*uid;
  int		i;

  i = 0;
  if (!(pwd = getpwuid(info->st_uid)))
    {
      perror("Error getpwuid ");
      exit(3);
    }
  uid = my_malloc(my_strlen(pwd->pw_name));
  while (pwd->pw_name[i])
    uid[i] = pwd->pw_name[i++];
  uid[i] = '\0';
  return (uid);
}

char		*find_name(t_dirent *element)
{
  char		*name;
  int		i;

  i = 0;
  name = my_malloc(my_strlen(element->d_name));
  while (element->d_name[i])
    name[i] = element->d_name[i++];
  name[i] = '\0';
  return (name);
}

char		find_mode(t_stat *info)
{
  if ((S_ISREG(info->st_mode)))
    return (MOD_FILE);
  else if (S_ISLNK(info->st_mode))
    return (MOD_LINK);
  else if (S_ISDIR(info->st_mode))
    return (MOD_DIR);
  else if (S_ISCHR(info->st_mode))
    return (MOD_CHAR);
  else if (S_ISBLK(info->st_mode))
    return (MOD_BLOK);
  else if (S_ISFIFO(info->st_mode))
    return (MOD_FIFO);
  else if (S_ISSOCK(info->st_mode))
    return (MOD_SOCK);
  else
    return (MOD_ERROR);
}

char		*find_right(t_stat *info)
{
  char		*str;

  str = my_malloc(10);
  str[0] = (S_IRUSR ? 'r' : '-');
  str[1] = (S_IWUSR ? 'w' : '-');
  str[2] = (S_IXUSR ? 'x' : '-');
  str[3] = (S_IRGRP ? 'r' : '-');
  str[4] = (S_IWGRP ? 'w' : '-');
  str[5] = (S_IXGRP ? 'x' : '-');
  str[6] = (S_IROTH ? 'r' : '-');
  str[7] = (S_IWOTH ? 'w' : '-');
  str[8] = (S_IXOTH ? 'x' : '-');
  str[9] = '\0';
  return (str);
}
*/
int		main(int ac, char **av)
{
  if (ac == 1)
    my_type(".");
  else
    my_type(av[1]);
  return (0);
}

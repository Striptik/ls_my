/*
** find_comp.c for find composants of element in /home/loisel_k/travail/Systeme-Unix/my_ls/src
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Nov 30 00:06:51 2013 kevin loiseleur
** Last update Sun Dec  1 19:59:15 2013 kevin loiseleur
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include "../include/my.h"
#include "../include/my_ls.h"

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

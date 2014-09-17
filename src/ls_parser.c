/*
** ls_parser.c for parser.c in /home/loisel_k/travail/Systeme-Unix/my_ls/src
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sun Dec  1 19:54:36 2013 kevin loiseleur
** Last update Sun Dec  1 19:59:14 2013 kevin loiseleur
*/

t_pos			*my_ls_parser(const char *path)
{
  DIR			*dir;
  t_dirent		*element;
  t_elem		*elem;
  t_pos			*list;


  if (!(dir = opendir(path)))
    {
      my_printf("ls: cannot acces %s", path);
      perror("");
      return (NULL);
    }
  while ((element = my_readdir(dir)))
    {
      init_elem(elem);
      elem = get_info(elem, element);
      create_list_ls(elem, list);
    }
  return (list);
}

void		create_list_ls(t_elem *elem, t_pos *list)
{
  static int	i;

  if ((ins_elem(list, elem, 1)) == -1)
    {
      my_printf("Erreur insertion element\n");
      exit(3);
    }
  return ;
}

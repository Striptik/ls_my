/*
** my_ls.h for my_ls in /home/loisel_k/travail/Systeme-Unix/my_ls/include
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Nov 26 12:54:39 2013 kevin loiseleur
** Last update Sun Dec  1 20:47:22 2013 kevin loiseleur
*/

#ifndef MY_LS_H
# define MY_LS_H

# define MOD_FILE	'-'
# define MOD_DIR	'd'
# define MOD_CHAR	'c'
# define MOD_BLOK	'b'
# define MOD_FIFO	'p'
# define MOD_LINK	'l'
# define MOD_SOCK	's'
# define MOD_ERROR	'\0'

# define SUCCES	        0
# define ERROR		1

# define NB_OPT		5

# define Y		0
# define N		1

typedef struct dirent	t_dirent;
typedef struct stat	t_stat;

typedef struct		s_elem
{
  char			*name;
  char			mode;
  char			*right;
  char			*uid;
  char			*gid;
  char			*time;
  nlink_t		NbLkH;
  int			size;
}			t_elem;

typedef struct		s_lsopt
{
  char			**path;
  int			opt_l;
  int			opt_d;
  int			opt_R;
  int			opt_t;
  int			opt_r;
}			t_lsopt;

/*
** Tools
*/

void			*my_malloc(int len);
t_dirent		*my_readdir(DIR *dir);
int			my_closedir(DIR *dir);
int			my_stat(const char *name, t_stat *info);


/*
** Main functions
*/

int			my_ls(int ac, char **av);
void			my_ls_only(t_lsopt *opt_path, int ac);


/*
** Lexer
*/

t_lsopt			*lex_options_path(int ac, char *av);
void			init_lsopt(t_lsopt *opt_path, int ac);
void			what_paths(char **av, int ac, t_lsopt *opt_path);
void			what_paths(char **av, int ac, t_lsopt *opt_path);
void			what_options(char **av, int ac, t_lsopt *opt_path);
void			assign_options(t_lsopt *opt_path, char *opt);
void			moove_lsopt(t_lsopt *opt_path, char opt)

/*
** Get info
*/

t_elem			*get_info(t_elem *elem, t_dirent *element);
char			*find_name(t_dirent *info);
char			find_mode(t_stat *info);
char			*find_right(t_stat *info);
char			*find_uid(t_stat *info);
char			*find_gid(t_stat *info);
char			*find_time(t_stat *info);
int			find_size(t_stat *info);

/*
** Parser
*/

t_pos			*my_ls_parser(const char *path);
void			create_list_ls(t_elem *elem, t_pos *list);

/*
** Display
*/

void			gere_aff_options(t_lsopt *opt_path, t_pos *list);
void			aff_ls(t_lsopt *opt_path, t_pos *tmp);
t_pos			*gere_opt_r(t_lsopt *opt_path, t_pos *list);
t_pos			*gere_opt_d(t_lsopt *opt_path, t_pos *list);

#endif /* MY_LS_H_ */

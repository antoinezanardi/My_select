/*
** my_select.h for my_select in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_my_select
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Jan  5 10:22:51 2015 Antoine Zanardi
** Last update Wed Jan  7 17:02:00 2015 Antoine Zanardi
*/

#include		<unistd.h>
#include		<termios.h>

#ifndef			MY_SELECT_H_
# define		MY_SELECT_H_

# define		DEL		126
# define		BACKSPACE	127
# define		UP		65
# define		LEFT		68
# define		RIGHT		67
# define		DOWN		66
# define		ENTER		10
# define		REFRESH		114

int			fd;

typedef struct		s_list
{
  char			*arg;
  int			select;
  int			del;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

typedef struct		s_dim
{
  int			haut;
  int			larg;
}			t_dim;

void			my_putstr_error(int);
void			my_show_list(t_list *);
void			my_select(struct termios *, int, t_list *);
void			select_arg(t_list **);
void			del_arg(t_list **, int *, struct termios *, t_list **);
void			my_putchar2(char);
void			my_putstr2(char *);
int			mk_clear(void);
int			highlight(t_list *);
int			put_in_c_list(t_list **, char **);
int			init_term(char **, struct termios *);
int			add_top_list(t_list **, char *);
int			add_bot_list(t_list **, char *);
int			check_select_l(t_list *, int);
int			underline(t_list *);
int			put_in_term(int);

#endif			/* !MY_SELECT_H_ */

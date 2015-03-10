/*
** main.c for main in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_my_select
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sun Jan  4 18:15:01 2015 Antoine Zanardi
** Last update Tue Jan 13 12:26:26 2015 Antoine Zanardi
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<term.h>
#include	<termios.h>
#include	<unistd.h>
#include	<curses.h>
#include	<ncurses/curses.h>
#include	"my_select.h"

int			check_args(char **argv)
{
  int			compt_arg;

  compt_arg = 1;
  while (argv[compt_arg] != '\0')
    {
      if (argv[compt_arg][0] != '\0')
	return (1);
      else
	compt_arg++;
    }
  my_putstr_error(1);
  return (0);
}

void			put_raw(struct termios *term)
{
  term->c_lflag &= ~(ICANON | ECHO);
  term->c_cc[VMIN] = 1;
  term->c_cc[VTIME] = 0;
  if (tcsetattr(0, 0, term) == -1)
    my_putstr_error(6);
  if ((fd = open("/dev/tty", O_RDWR)) == -1)
    my_putstr_error(2);
}

int			main(int argc, char **argv, char **env)
{
  t_list		*list;
  int			compt_arg;
  struct termios	term;
  struct termios	ori;

  if (argc == 1)
    my_putstr_error(1);
  check_args(argv);
  list = NULL;
  compt_arg = put_in_c_list(&list, argv);
  init_term(env, &term);
  ori = term;
  put_raw(&term);
  my_select(&ori, compt_arg, list);
  return (0);
}

/*
** fc_term.c for fc_term in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_my_select
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Jan  6 10:30:18 2015 Antoine Zanardi
** Last update Mon Feb  9 13:59:33 2015 Antoine Zanardi
*/

#include	<ncurses/curses.h>
#include	<term.h>
#include	<stdlib.h>
#include	"my_select.h"

int		put_in_term(int c)
{
  write(fd, &c, 1);
  return (0);
}

int		mk_clear()
{
  char		*clean;

  if ((clean = tgetstr("cl", NULL)) == NULL)
    return (1);
  if (tputs(clean, 0, &put_in_term) <= 0)
    return (1);
  return (0);
}

void		select_arg(t_list **list)
{
  if ((*list)->select == 1)
    (*list)->select = 0;
  else if ((*list)->select == 0)
    {
      (*list)->select = 1;
      (*list) = (*list)->next;
    }
}

void		del_compt(int *co, struct termios *ori)
{
  *co = *co - 1;
  if (*co == 0)
    {
      if (tcsetattr(0, 0, ori) == -1)
	my_putstr_error(6);
      exit(1);
    }
}

void		del_arg(t_list **li, int *co, struct termios *ori, t_list **tmp)
{
  del_compt(co, ori);
  if ((*tmp)->next == *li && (*tmp)->prev == *li)
    {
      *tmp = (*tmp)->next;
      (*tmp)->next = *tmp;
      (*tmp)->prev = *tmp;
    }
  else if (*tmp == *li && (*tmp)->prev == (*tmp)->next)
    {
      *tmp = (*tmp)->next;
      *li = (*li)->next;
      (*tmp)->next = *tmp;
      (*tmp)->prev = *tmp;
    }
  else if (*tmp == *li && (*tmp)->prev != (*tmp)->next)
    {
      *li = (*li)->next;
      *tmp = (*tmp)->next;
    }
  else
    {
      (*tmp)->prev->next = (*tmp)->next;
      (*tmp)->next->prev = (*tmp)->prev;
      *tmp = (*tmp)->next;
    }
}

/*
** my_select.c for my_select in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_my_select
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Jan  5 15:40:26 2015 Antoine Zanardi
** Last update Thu Jan  8 14:35:54 2015 Antoine Zanardi
*/

#include		<termios.h>
#include		<term.h>
#include		<stdlib.h>
#include		"my_select.h"
#include		"my.h"

void			select_down_up(t_list **list, int mode)
{
  if (mode == 0)
    *list = (*list)->next;
  else if (mode == 1)
    *list = (*list)->prev;
}

int			gere_key(char *buffer, struct termios *ori, int esc)
{
  if (buffer[0] == 27 && esc == 1)
    {
      if (tcsetattr(0, 0, ori) == -1)
	my_putstr_error(6);
      exit(1);
    }
  if (buffer[0] == BACKSPACE || buffer[0] == DEL)
    return (1);
  if (buffer[0] == 27 && buffer[2] == DOWN)
    return (2);
  if (buffer[0] == 27 && buffer[2] == UP)
    return (3);
  if (buffer[0] == ENTER)
    return (4);
  if (buffer[0] == 32)
    return (5);
  return (-1);
}

void			print_arg(t_list *list, int compt_arg, t_list *tmp)
{
  int			compt;

  compt = 0;
  while (compt < compt_arg)
    {
      if (tmp == list)
	underline(list);
      else if (list->select == 1)
	highlight(list);
      else
	my_putstr2(list->arg);
      list = list->next;
      my_putchar2('\n');
      compt++;
    }
}

void			final_print(t_list *list, int co, struct termios *ori)
{
  int			compt;

  compt = 0;
  if (check_select_l(list, co) == 1)
    {
      while (compt < co)
	{
	  if (list->select == 1)
	    {
	      my_putstr(list->arg);
	      my_putchar(' ');
	    }
	  list = list->next;
	  compt++;
	}
      my_putchar('\n');
    }
  else
    my_putstr("Aucun élément n'a été choisi...\n");
  if (tcsetattr(0, 0, ori) == -1)
    my_putstr_error(6);
  exit(1);
}

void			my_select(struct termios *ori, int co, t_list *list)
{
  char			buff[3];
  int			esc;
  t_list		*tmp;

  tmp = list;
  while (42)
    {
      mk_clear();
      print_arg(list, co, tmp);
      if ((esc = read(0, buff, 3)) == -1)
	my_putstr_error(6);
      if (gere_key(buff, ori, esc) == 1)
	del_arg(&list, &co, ori, &tmp);
      if (gere_key(buff, ori, esc) == 2)
	select_down_up(&tmp, 0);
      if (gere_key(buff, ori, esc) == 3)
       	select_down_up(&tmp, 1);
      if (gere_key(buff, ori, esc) == 5)
	select_arg(&tmp);
      if (gere_key(buff, ori, esc) == 4)
	final_print(list, co, ori);
    }
}

/*
** police.c for police in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_my_select
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Jan  6 17:09:54 2015 Antoine Zanardi
** Last update Wed Jan  7 18:39:10 2015 Antoine Zanardi
*/

#include	<term.h>
#include	<stdlib.h>
#include	"my_select.h"
#include	"my.h"

void		my_putchar2(char c)
{
  write(fd, &c, 1);
}

void		my_putstr2(char *str)
{
  int		compt_str;

  compt_str = 0;
  while (str[compt_str] != '\0')
    {
      write(fd, &str[compt_str], 1);
      compt_str++;
    }
}

int		highlight(t_list *list)
{
  char		*sur;

  if ((sur = tgetstr("so", NULL)) == NULL)
    return (0);
  if (tputs(sur, 0, &put_in_term) < 0)
    return (0);;
  my_putstr2(list->arg);
  if ((sur = tgetstr("se", NULL)) == NULL)
    return (0);
  if (tputs(sur, 0, &put_in_term) < 0)
    return (0);
  return (0);
}

int		underline(t_list *list)
{
  char		*tam;

  tam = tgetstr("us", NULL);
  if (tputs(tam, 0, &put_in_term) < 0)
    return (0);
  if (list->select == 1)
    highlight(list);
  else
    my_putstr2(list->arg);
  if ((tam = tgetstr("ue", NULL)) == NULL)
    return (0);
  if (tputs(tam, 0, &put_in_term) < 0)
    return (0);
  return (0);
}

int		check_select_l(t_list *list, int compt_arg)
{
  t_list	*tmp;
  int		compt;

  compt = 0;
  tmp = list;
  while (compt_arg > compt)
    {
      if (tmp->select == 1)
	return (1);
      else
	tmp = tmp->next;
      compt++;
    }
  return (0);
}

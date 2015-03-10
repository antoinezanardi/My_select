/*
** lists.c for my_select in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_my_select
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Jan  5 10:20:24 2015 Antoine Zanardi
** Last update Wed Jan  7 13:14:59 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my_select.h"

void		make_c_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = list;
  list->prev = tmp;
}

int		put_in_c_list(t_list **list, char **arg)
{
  int		compt_arg;
  int		real_compt;

  compt_arg = 1;
  real_compt = 0;
  while (arg[compt_arg] != '\0')
    {
      if (arg[compt_arg][0] != '\0')
	{
	  add_bot_list(list, arg[compt_arg]);
	  real_compt++;
	}
      compt_arg++;
    }
  make_c_list(*list);
  return (real_compt);
}

/*
** term.c for my_select in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_my_select
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Jan  5 13:15:40 2015 Antoine Zanardi
** Last update Mon Feb  9 14:12:36 2015 Antoine Zanardi
*/

#include	<curses.h>
#include	<term.h>
#include	<termios.h>
#include	<stdlib.h>
#include	"my_select.h"
#include	"my.h"

int		my_strcmp(char *str, char *str2, int compt2)
{
  int		compt;

  compt = 0;
  while (str[compt] != '\0')
    {
      if (str2[compt2] == '\0' || str[compt] != str2[compt2])
	return (1);
      else
	{
	  compt++;
	  compt2++;
	}
    }
  return (0);
}

char		*real_term(char *term)
{
  char		*name;
  int		compt_term;
  int		compt_name;

  compt_term = 0;
  compt_name = 0;
  while (term[compt_term] != '=')
    compt_term++;
  compt_term++;
  name = term;
  while (term[compt_term] != '\0')
    {
      name[compt_name] = term[compt_term];
      compt_name++;
      compt_term++;
    }
  name[compt_name] = '\0';
  return (name);
}

char		*term_name(char **env)
{
  int		compt_env;
  char		*term;
  char		*name;

  compt_env = 0;
  if (env[compt_env] == '\0')
    my_putstr_error(3);
  while (env[compt_env] != '\0')
    {
      if (my_strcmp("TERM=", env[compt_env], 0) == 0)
	term = (env[compt_env]);
      compt_env++;
    }
  name = real_term(term);
  return (name);
}

int		init_term(char **env, struct termios *term)
{
  char		*name;

  name = term_name(env)
  if (tgetent(NULL, name) != 1)
    my_putstr_error(4);
  if (tcgetattr(0, term) == -1)
    my_putstr_error(5);
  return (0);
}

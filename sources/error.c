/*
** error.c for my_select in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_my_select
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Jan  5 10:09:27 2015 Antoine Zanardi
** Last update Wed Jan  7 13:46:15 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"

void		my_putstr_error(int error)
{
  if (error == 1)
    my_putstr("The program needs at least one argument\n");
  else if (error == 2)
    my_putstr("The program has only one argument, choice is simple\n");
  else if (error == 3)
    my_putstr("The Term's name is unknown\n");
  else if (error == 4)
    my_putstr("The term's database can't be found\n");
  else if (error == 5)
    my_putstr("Termios couldn't be filled\n");
  else if (error == 6)
    my_putstr("Change couldn't be applied on term\n");
  exit(1);
}

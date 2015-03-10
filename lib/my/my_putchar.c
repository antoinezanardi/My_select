/*
** my_putchar.c for my_putchar in /home/zanard_a/rendu/Librairie tempo
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Oct  7 12:41:55 2014 Antoine Zanardi
** Last update Wed Dec 17 11:38:23 2014 Antoine Zanardi
*/

#include	<unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

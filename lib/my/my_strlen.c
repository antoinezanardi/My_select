/*
** my_strlen.c for my_strlen in /home/zanard_a/rendu/J4/ex3
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Oct  2 12:42:56 2014 Antoine Zanardi
** Last update Sat Oct 11 17:57:41 2014 Antoine Zanardi
*/

int	my_strlen(char *str)
{
  int	o;

  o = 0;
  while (str[o] != '\0')
    o++;
  return (o);
}

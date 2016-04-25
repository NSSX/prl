#include "my_printf.h"

void parsing(t_main *main)
{
  int i ;
 
  i = main->i;
 while(main->chaine[i] == '+' || main->chaine[i] == '-' || main->chaine[i] == '#' || main->chaine[i] == ' ')
    {
      main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
      i++;
    }
  while(main->chaine[i] <= '9' && main->chaine[i] >= '0')
    {
      main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
      i++;
    }
  if(main->chaine[i] == '.')
    {
     main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
      i++;
    }
  while(main->chaine[i] <= '9' && main->chaine[i] >= '0')
    {
      main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
      i++;
    }
   while(main->chaine[i] == 'l' || main->chaine[i] == 'h' || main->chaine[i] == 'j' || main->chaine[i] == 'z')
   {
      main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
      i++;
   }
  main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
}

int anothertry(t_main *main)
{
  int i;

  i = 0;
  while(main->parsed[i] == ' ')
    {
      i++;
    }
  if(main->parsed[i] == '%')
    {
      return(1);
    }
  return(0);
}

int spacenoplus(t_main *main)
{
  int i;

  i = 0;
  while(main->parsed[i] != '\0')
  {
    if(main->parsed[i] == '+')
      return(0);
    i++;
  }
return (1);
}

int flag_fiel(t_main *main)
{
  main->i++;
  parsing(main);
   if(main->chaine[main->i] == '0')
    {
      main->zeroetat = 1;
      flag_fiel(main);
    }
  if(main->chaine[main->i] == '+')
    {
      int i;
      int etat;

      etat = 0;
      i = 0;
      while(main->parsed[i] != '\0')
        {
          if(main->parsed[i] == 'u' || main->parsed[i] == 'c')
            {
              etat = 1;
            }
          i++;
        }
      if((int)main->elem >= 0 && etat == 0 && main->plusetat != 1)
        {
          main->taille++;
          main->size++;
	  //          main->print = ft_strjoin(main->print, "+");
	  main->plusetat = 1;
        }
      flag_fiel(main);
    }
  else if(main->chaine[main->i] == '#')
    {
      main->dietat = 1;
      flag_fiel(main);
    }
  else if(main->chaine[main->i] == '-')
    {
      main->moinetat = 1;
      flag_fiel(main);
    }
  else if(main->chaine[main->i] == ' ')
    {
      int i;
      int etat;
     
      etat = 0;
      i = 0;
      while(main->parsed[i] != '\0')
  	 {
      	  if(main->parsed[i] == 'u' || main->parsed[i] == 'c')
      	    {
      	      etat = 1;
      	    }
      	  i++;
	     }
      if((int)main->elem >= 0 && etat == 0 && anothertry(main) == 0)
        {
          if(spacenoplus(main) == 1)
          {
            main->taille++;
            main->size++;
            main->print = ft_strjoin(main->print, " ");
	         }
      while(main->chaine[main->i + 1] == ' ')
	    {
	      main->i++;
	    }
        }
      flag_fiel(main);
    }
  else
    main->i--;
  return (0);
}

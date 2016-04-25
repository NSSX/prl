#include "my_printf.h"
#define TYPE int
#include <wchar.h>

void accurate_d(int size, t_main *main)
{
	if(main->signemoin == 1)
	{
		main->accurate++;
	}
	if(find(main,'o') == 0)
	{
		while(size < main->accurate)
		{
			main->print = ft_strjoin(main->print, "0");
			size++;
			main->size++;
		}
	}
	else
	{
		while(size < main->accurate)
		{
			main->print = ft_strjoin("0", main->print);
			size++;
			main->size++;
		}
	}
}

void join_lld(t_main *main)
{
	char *number;
	int size;

	number = my_itoa((long long int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if(main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void join_ld(t_main *main)
{
	char *number;
	int size;

	number = my_itoa((long int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if(main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void join_hd(t_main *main)
{
	char *number;
	int size;

	number = my_itoa((short int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if(main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void join_hhd(t_main *main)
{
	char *number;
	int size;

	number = my_itoa((signed char)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if(main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void join_jd(t_main *main)
{
	char *number;
	int size;

	number = my_itoa((long long int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if(main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void join_zd(t_main *main)
{
	char *number;
	int size;

	number = my_itoa((long long int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if(main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void join_d(t_main *main)
{
	char *number;
	int size;

	number = my_itoa((int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if(main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void join_lu(t_main *main)
{
	char *number;
	int size;

	number = my_utoa((unsigned long int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if(main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void join_llu(t_main *main)
{
	char *number;
	int size;

	number = my_utoa((unsigned long long int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if(main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void join_hu(t_main *main)
{
	char *number;
	int size;

	number = my_utoa((unsigned short int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if(main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void join_hhu(t_main *main)
{
	char *number;
	int size;

	number = my_utoa((unsigned long long int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if(main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void join_ju(t_main *main)
{
	char *number;
	int size;

	number = my_utoa((uintmax_t)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if(main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void join_zu(t_main *main)
{
	char *number;
	int size;

	number = my_utoa((size_t)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if(main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void join_u(t_main *main)
{
	char *number;
	int size;

	number = my_utoa((unsigned int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if(main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}



// SDU
//http://personal.ee.surrey.ac.u           k/Personal/R.Bowden/C/printf.html
int manage_arg(t_main *main)
{
	main->i++;
	if(main->chaine[main->i] == 'd' || main->chaine[main->i] == 'i')
	{
		if((main->accurate == 0 && main->width != 0) || 
			(find(main,'.') == 1 && main->accurate < 1 && main->width != 0)||
			((int)main->elem == 0 && find(main,'.') == 1 && main->accurate < 1))
		{
			return(0);
		}

		long long int a;
		a = (long long int)main->elem;
		if ((int)a < 0 && main->type == 0)// || (long int)a < 0 || (long long int)a < 0)
			main->signemoin = 1;
		else if ((long int)a < 0 && main->type == 1)
			main->signemoin = 1;
		else if ((long long int)a < 0 && main->type == 2)
			main->signemoin = 1;
		if(main->type == 0)
			join_d(main);
		else  if(main->type == 1)
			join_ld(main);
		else  if(main->type == 2)
			join_lld(main);
		else if(main->type == 3)
			join_hd(main);
		else if(main->type == 4)
			join_hhd(main);
		else if(main->type == 5)
			join_jd(main);
		else if(main->type == 6)
			join_zd(main);

		if(main->signemoin == 1)
		{
			int i = 0;
			int i2 = 0;
			char *temp;
			temp = (char *)malloc(sizeof(char) + ft_strlen(main->print));
			while(main->print[i] != '\0')
			{
				if(main->print[i] != '-')
				{

					temp[i2] = main->print[i];
					i2++;
				}
				i++;
			}
			temp[i2] = '\0';
			main->print = temp;
			main->print = ft_strjoin("-", main->print);
		}

	}  
	else if(main->chaine[main->i] == 'D')
	{
		if(main->type > 0)
		{
			main->type++;
		}
		else
			main->type = 1;
		if(main->type == 1)
			join_ld(main);
		else  if(main->type == 2)
			join_lld(main);
		else if(main->type == 3)
			join_hd(main);
		else if(main->type == 4)
			join_hhd(main);
		else if(main->type == 5)
			join_jd(main);
		else if(main->type == 6)
			join_zd(main);
	}

	else if(main->chaine[main->i] == 'o')
	{
		if(((main->accurate == 0 && main->width != 0) || 
			(find(main,'.') == 1 && main->accurate < 1 && main->width != 0)||
			((unsigned int)main->elem == 0 && find(main,'.') == 1 && main->accurate < 1)) && main->dietat == 0)
		{
			return(0);
		}

		if(main->dietat == 1)
		{
			main->print = ft_strjoin(main->print, "0");
			main->size++;
		}
		if((unsigned long long int)main->elem != 0)
			base_converter(main, (unsigned long long int)main->elem, 8);
		else if(main->dietat == 0)
		{
			main->size++;
			main->print = ft_strjoin(main->print, "0");
		}
		accurate_d(ft_strlen(main->print), main);
	}
	else if(main->chaine[main->i] == 'u')
	{
		if(main->type == 0)
			join_u(main);
		else  if(main->type == 1)
			join_lu(main);
		else  if(main->type == 2)
			join_llu(main);
		else if(main->type == 3)
			join_hu(main);
		else if(main->type == 4)
			join_hhu(main);
		else if(main->type == 5)
			join_ju(main);
		else if(main->type == 6)
			join_zu(main);
	}
	else if(main->chaine[main->i] == 'U')
	{
		if(main->type > 0)
		{
			main->type++;
		}
		else
			main->type = 1;
		if(main->type == 1)
			join_lu(main);
		else  if(main->type == 2)
			join_llu(main);
		else if(main->type == 3)
			join_hu(main);
		else if(main->type == 4)
			join_hhu(main);
		else if(main->type == 5)
			join_ju(main);
		else if(main->type == 6)
			join_zu(main);
	}
	else if(main->chaine[main->i] == 's')
	{
		if((char *)main->elem)
		{
			if(main->accurate == -1)
				main->accurate = ft_strlen((char *)main->elem);
			int i;
			char *lp;

			lp = (char *)main->elem;
			lp = ft_strsub(lp, 0, main->accurate);
			i = 0;
			main->print = ft_strjoin(main->print, &lp[0]);
			if((size_t)main->accurate > ft_strlen(lp))
				main->size = ft_strlen(lp);
			else
				main->size += main->accurate;
		}
		else
		{
			char *null;
			int i;
			i = 0;
			null = "(null)";
			if(main->accurate > 0)
			{
				while(i < main->accurate && i < 6)
				{
					main->print= ft_strjoin_carac(main->print, null[i]);
					main->size++;
					i++;
				}
			}
			else
			{
				main->print= ft_strjoin(main->print, null);
				main->size += 6;
			}
		}
	}
	else if(main->chaine[main->i] == 'S')
	{
		if((wchar_t *)main->elem)
		{
			int i;
			wchar_t *chaine;

			chaine = (wchar_t *)main->elem;
			i=0;
			while(chaine[i] != '\0')
			{
				mywchar(main, chaine[i]);
				i++;
			}
		}
		else
		{
			char *null;
			int i;
			i = 0;
			null = "(null)";
			if(main->accurate > 0)
			{
				while(i < main->accurate && i < 6)
				{
					main->print= ft_strjoin_carac(main->print, null[i]);
					main->size++;
					i++;
				}
			}
			else
			{
				main->print= ft_strjoin(main->print, null);
				main->size += 6;
			}
		}

	}
	else if(main->chaine[main->i] == 'c')
	{
		if((int)main->elem != 0)
		{
			main->size++;
			main->print = ft_strjoin_carac(main->print, (int)main->elem);
		}
		else
		{
			main->size++;
		}
	}
	else if(main->chaine[main->i] == 'C')
	{
		if((wint_t)main->elem != 0)
			mywchar(main, (wint_t)main->elem);
		else
			main->size++;
	}
	else if(main->chaine[main->i] == '%')
	{
		main->size++;
		main->print = ft_strjoin_carac(main->print, '%');
	}
	else if(main->chaine[main->i] == 'p')
	{
		if((unsigned long long int)main->elem == 0)
		{
			main->size += 3;
			main->print = ft_strjoin(main->print, "0x0");
		}
		else
		{
			main->size += 2;
			main->print = ft_strjoin(main->print, "0x");
			base_converter(main, (unsigned long long int)main->elem, 16);
		}

	}
	else if(main->chaine[main->i] == 'x')
	{
			if((main->accurate == 0 && main->width != 0) || 
			(find(main,'.') == 1 && main->accurate < 1 && main->width != 0)||
			((unsigned int)main->elem == 0 && find(main,'.') == 1 && main->accurate < 1))
		{
			return(0);
		}

		if((unsigned long long int)main->elem != 4294967296 || main->type >= 1)
		{
			if(main->dietat == 1 && (unsigned long long int)main->elem != 0)
			{
				//      main->print = ft_strjoin(main->print, "0x");
				main->size += 2;
			}
			if((unsigned long long int)main->elem != 0)
			{
				if(main->type == 0)
					base_converter(main, (unsigned int)main->elem, 16);
				else  if(main->type == 1)
					base_converter(main, (unsigned long int)main->elem, 16);
				else  if(main->type == 2)
					base_converter(main, (unsigned long long int)main->elem, 16);
				else if(main->type == 3)
					base_converter(main, (unsigned short int)main->elem, 16);
				else if(main->type == 4)
					base_converter(main, (unsigned char)main->elem, 16);
				else if(main->type == 5)
					base_converter(main, (uintmax_t)main->elem, 16);
				else if(main->type == 6)
					base_converter(main, (size_t)main->elem, 16);
				if(main->print[0] == '\0')
				{
					main->size++;
					main->print = ft_strjoin(main->print, "0");
				}   
			}
			else
			{
				main->size++;
				main->print = ft_strjoin(main->print, "0");
			}
		}
		else
		{
			main->size++;
			main->print = ft_strjoin(main->print, "0");
		}
	}
	else if(main->chaine[main->i] == 'X')
	{
		if((unsigned long long int)main->elem != 4294967296 || main->type >= 1)
		{
			if(main->dietat == 1 && (unsigned long long int)main->elem != 0)
			{
				//	      main->print = ft_strjoin(main->print,"0X");
				main->size += 2;        
			}
			if((unsigned long long int)main->elem != 0)
			{
				if(main->type == 0)
					base_converter_upper(main, (unsigned int)main->elem, 16);
				else  if(main->type == 1)
					base_converter_upper(main, (unsigned long int)main->elem, 16);
				else  if(main->type == 2)
					base_converter_upper(main, (unsigned long long int)main->elem, 16);
				else if(main->type == 3)
					base_converter_upper(main, (unsigned short int)main->elem, 16);
				else if(main->type == 4)
					base_converter_upper(main, (unsigned char)main->elem, 16);
				else if(main->type == 5)
					base_converter_upper(main, (uintmax_t)main->elem, 16);
				else if(main->type == 6)
					base_converter_upper(main, (size_t)main->elem, 16);
				if(main->print[0] == '\0')
				{
					main->size++;
					main->print = ft_strjoin(main->print, "0");
				} 
			}
			else
			{
				main->size++;
				main->print = ft_strjoin(main->print, "0");
			}
		}
		else
		{
			main->size++;
			main->print = ft_strjoin(main->print, "0");
		}
	}
	else
		main->i--;
	return (1);
}

#include <stdarg.h>

typedef union	values
{
	int				int_val;
	char			*str_val;
	void			*ptr_val;
	unsigned char	char_val;
}val;

typedef struct informations
{
	int id;				//1, 2, 3, ...
	char type;			//cspdiuxX%
	val content;		//valeur
	int	precision;		//combien d'elements a ecrire
	char fill;			//elements a ecrire
}infos;

int is_conversion_specifier(char c)
{
	return (c == '%' && c == 'c' && c == 's' && c == 'p' && c == 'd'
			&& c == 'i' && c == 'u' && c == 'x' && c == 'X' && c == 0);
}

unsigned int ft_count_args(const char *str)
{
	int count;

	count = 0;
	while (*str != 0)
	{
		while (*str != '%' && *str)
			str++;
		if (!(*str++))
			break;
		while (!(is_conversion_specifier(*str)))
			str++;
		if (!(*str++))
			break;
		count++;
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list				ap;
	infos				*arguments;
	unsigned int		count;
	unsigned int		i;

	i = 0;
	count = ft_count_args(format);
	va_start(ap, format);
//	arguments = (val*)malloc(count * sizeof(val));
	while (i < count)
	{
		va_arg(ap, char*);
		i++;
	}
	va_end(ap);
	return (0);
}

int main()
{
	val ola;

	ola.char_val = 'c';
	printf("%x\n", ola.ptr_val);
	printf("%d\n", ola.int_val);
	printf("%c\n", ola.char_val);
//	ft_printf("hello", "these", "are", "my", "arguments");
	printf("nbre d'arguments %d\n", ft_count_args("%s, %s %d, %.4d:%.4d\n"));
	return 0;
}

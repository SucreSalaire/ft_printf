/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:44:10 by salmou            #+#    #+#             */
/*   Updated: 2024/12/13 18:54:19 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*arg_to_char(va_list ap, char s)
{
	char	*val;
	if (s == 'i' || s == 'd')
		val = ft_itoa(va_arg(ap, ssize_t));
	else if (s == 'u')
		val = ft_utoa(va_arg(ap, ssize_t));
	else if (s == 's')
		val = va_arg(ap, char *);
	else if (s == 'c')
		val = char_to_str(va_arg(ap, int));
	else if (s == 'x' || s == 'X')
		val = num_to_hex(va_arg(ap, int), ft_isupercase(s), 0);
	else if (s == '%')
		val = char_to_str('%');
	else if (s == 'p')
		val = num_to_hex(va_arg(ap, size_t), 0, 1);
	return (val);
}

char	*ft_utoa(ssize_t num)
{
	if (num || !num)
		return (NULL);
	return (NULL);
}
/*
char	*zero_dup(char *s, size_t n, char *c)
{
	size_t	i;
	char	*tmp;

i	if (n <= ft_strlen(s))
		return (s);
	i = 0;
	tmp = ft_strdup(s);
	while (i++ < n - ft_strlen(s))
		tmp = ft_strjoin(c, tmp);
	return (tmp);
}
*/
char	*num_to_hex(ssize_t num, int up, char format)
{
	char	*hex;
	size_t	mem;
	int		i;

	if (num < 0)
		num = UINT_MAX + num + 1;
	mem = num;
	i = 2;
	while (mem > 15)
	{
		mem /= 16;
		i++;
	}
	if (format)
	{
		i += 2;
		hex = (char *)malloc(sizeof(char) * (i--));
		hex[0] = '0';
		hex[1] = 'x' * (up == 0) + 'X' * (up == 1);
	}
	else
	{	
		hex = (char *)malloc(sizeof(char) * i--);
	}
	hex[i--] = 0;
	if (num == 0)
		hex[i] = '0';
	while (num)
	{
		if (up)
			hex[i--] = "0123456789ABCDEF"[num % 16];
		else
			hex[i--] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	return (hex);
}

int	ft_isupercase(char c)
{
	if (c >= 'A' && c <= 'Z')
			return (1);
	return (0);
}

char	*char_to_str(int c)
{
	char	*s;

	s = (char *)malloc(2 * sizeof(char));
	s[0] = (char)c;
	s[1] = 0;
	return (s);
}

int	ft_printf(const char *s, ...)
{
	va_list ap;
	char	*val[256];
	size_t		i;
	int		cnt;

	i = 0;
	cnt = 0;
	va_start(ap, s);
	while (i < ft_strlen(s))
	{
		if (s[i] == '%')
		{
			val[i] = arg_to_char(ap, s[i + 1]);
			cnt += ft_strlen(val[i]);
			ft_putstr_fd(val[i++], 1);
			if (s[i] != 's')
				free(val[i - 1]);
		}
		else
		{
			val[i] = char_to_str(s[i]);
			cnt += ft_strlen(val[i]);
			ft_putstr_fd(val[i], 1);
			free(val[i]);
		}
		i++;
	}
	va_end(ap);
	return (cnt);
}

int	main()
{
	char *ptr;
	char str[200] = "%i\n";

	ptr = malloc(1);
	printf("%p LMIN%p LMAX%p ULMAX%p -ULMAX%p %p\n", ptr, (void *)LONG_MIN, (void *)LONG_MAX, (void *)ULONG_MAX, (void *)-ULONG_MAX, NULL);
	ft_printf("%p LMIN%p LMAX%p ULMAX%p -ULMAX%p %p", ptr, LONG_MIN, LONG_MAX, ULONG_MAX, -ULONG_MAX, 0);
//	printf("%x, %x", UINT_MAX, INT_MIN);
	//printf("%6d", 123);
//	ft_printf("%s%s%s\n", "abc", "de", "fg");
//	ft_printf("min : %i , zero : %i, max : %i\n", INT_MIN, 0, INT_MAX);
//	ft_printf("max : %x, zero : %x, min : %x, MAX : %X, ZERO : %X, MIN : %X\n", UINT_MAX, -1, INT_MIN,  UINT_MAX, 0, INT_MIN);
//	ft_printf("hello first car is %c  sdfas %i %s\n", 'V', 123, "bcd");
//	ft_printf("%i%u%d%x%X%s%p%%", 0, 0, 0, 0, 0, "", str);
}

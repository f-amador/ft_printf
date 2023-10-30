/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <framador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:14:38 by framador          #+#    #+#             */
/*   Updated: 2023/10/30 16:48:28 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (*s)
	{
		i += ft_putchar(*s);
		s++;
	}
	return (i);
}

int	ft_putptr(long long n, char *base, int blen, int p)
{
	char	*num;
	int		len;

	len = 0;
	if (p == 2)
	{
		if (n == 0)
			return (ft_putstr("(nil)"));
		len += ft_putstr("0x");
	}
	if (n < 0 && p == 1)
	{
		len += ft_putchar(45);
		num = ft_itoa(-n, base, blen);
	}
	else
		num = ft_itoa(n, base, blen);
	len += ft_putstr(num);
	free(num);
	return (len);
}

int	ft_myspecifiers(char c, va_list ap)
{
	int	i;

	i = 0;
	if (c == '%')
		i += ft_putchar('%');
	else if (c == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (c == 'i' || c == 'd')
		i += ft_putptr(va_arg(ap, int), DEC, 10, 1);
	else if (c == 'p')
		i += ft_putptr(va_arg(ap, unsigned long), L_HEX, 16, 2);
	else if (c == 'x')
		i += ft_putptr(va_arg(ap, unsigned int), L_HEX, 16, 0);
	else if (c == 'X')
		i += ft_putptr(va_arg(ap, unsigned int), H_HEX, 16, 0);
	else if (c == 'u')
		i += ft_putptr(va_arg(ap, unsigned int), DEC, 10, 0);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	if (!s)
		return (-1);
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			i += ft_myspecifiers(*(s + 1), ap);
			s += 1;
		}
		else
			i += ft_putchar(*s);
		s++;
	}
	va_end(ap);
		return (i);
}
/*
#include <limits.h>
int	main()
{
	printf("%d\n", ft_printf("\nmine:%p\n%p\n", LONG_MIN, LONG_MAX));
	printf("%d\n", printf("\noriginal:%p\n%p\n", LONG_MIN, LONG_MAX));
	printf("%d\n", ft_printf("\nmine:%p\n%p\n", ULONG_MAX, -ULONG_MAX));
	printf("%d\n", printf("\noriginal%p\n%p\n", ULONG_MAX, -ULONG_MAX));
}
*/

/*
int main() {

	
    int custom_printf_result, printf_result;
    char c = 'A';
    char *str = "Hello, World!";
    void *ptr = &c;
    int num = 42;
    int hexNum = 255;
	
    // Test %c
	
    custom_printf_result = ft_printf("%%c: %c\n", c);
    printf_result = printf("%%c: %c\n", c);
    if (custom_printf_result != printf_result) {
        printf("Custom ft_printf and printf return different values for %%c\n");
    }

    // Test %s
	
    custom_printf_result = ft_printf("%%s: %s\n", str);
    printf_result = printf("%%s: %s\n", str);
    if (custom_printf_result != printf_result) {
        printf("Custom ft_printf and printf return different values for %%s\n");
    }
	
    // Test %p
	
    custom_printf_result = ft_printf("%%p: %p\n", ptr);
    printf_result = printf("%%p: %p\n", ptr);
	printf("%d, %d\n", custom_printf_result, printf_result);
    if (custom_printf_result != printf_result) {
        printf("Custom ft_printf and printf return different values for %%p\n");
    }

    // Test %d and %i
	
    custom_printf_result = ft_printf("%%d: %d\n", num);
    printf_result = printf("%%d: %d\n", num);
    if (custom_printf_result != printf_result) {
        printf("Custom ft_printf and printf return different values for %%d\n");
    }
    
    custom_printf_result = ft_printf("%%i: %i\n", num);
    printf_result = printf("%%i: %i\n", num);
    if (custom_printf_result != printf_result) {
        printf("Custom ft_printf and printf return different values for %%i\n");
    }

    // Test %x and %X
	
    custom_printf_result = ft_printf("%%x: %x\n", hexNum);
    printf_result = printf("%%x: %x\n", hexNum);
    if (custom_printf_result != printf_result) {
        printf("Custom ft_printf and printf return different values for %%x\n");
    }
	
    custom_printf_result = ft_printf("%%X: %X\n", hexNum);
    printf_result = printf("%%X: %X\n", hexNum);
    if (custom_printf_result != printf_result) {
        printf("Custom ft_printf and printf return different values for %%X\n");
    }

    // Test %%
	
    custom_printf_result = ft_printf("%%%%: %%\n");
    printf_result = printf("%%%%: %%\n");
    if (custom_printf_result != printf_result) {
        printf("Custom ft_printf and printf return different values for %%\n");
	}
	// Test maximum and minimum values
	
    custom_printf_result = ft_printf("%%d: %d\n", INT_MAX);
    printf_result = printf("%%d: %d\n", INT_MAX);
    if (custom_printf_result != printf_result) {
        printf("Custom ft_printf and printf return different values for maximum value of %%d\n");
    }
	
    custom_printf_result = ft_printf("%%d: %d\n", INT_MIN);
    printf_result = printf("%%d: %d\n", INT_MIN);
    if (custom_printf_result != printf_result) {
        printf("Custom ft_printf and printf return different values for minimum value of %%d\n");
    }
	
    custom_printf_result = ft_printf("%%u: %u\n", UINT_MAX);
    printf_result = printf("%%u: %u\n", UINT_MAX);
    if (custom_printf_result != printf_result) {
        printf("Custom ft_printf and printf return different values for maximum value of %%u\n");
    }
	
    custom_printf_result = ft_printf("%%x: %x\n", UINT_MAX);
    printf_result = printf("%%x: %x\n", UINT_MAX);
    if (custom_printf_result != printf_result) {
        printf("Custom ft_printf and printf return different values for maximum value of %%x\n");
    }
	
    custom_printf_result = ft_printf("%%X: %X\n", UINT_MAX);
    printf_result = printf("%%X: %X\n", UINT_MAX);
    if (custom_printf_result != printf_result) {
        printf("Custom ft_printf and printf return different values for maximum value of %%X\n");
    }
    return 0;
}
*/

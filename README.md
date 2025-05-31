![assets_task_01jwk0nwwnfq0bsgpc9kaej1tf_1748690007_img_0](https://github.com/user-attachments/assets/eb725157-f3f1-4cfd-8edf-f1b873f21cb7)



# 🖨️ ft_printf - 42 School Printf Implementation

## 📌 Overview
A simplified recreation of `printf` supporting `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, and `%X` conversions. Optimized with a single **`itoa_base`** function for all numerical outputs.

## 🌟 Key Features
- ✅ **Unified number handling**: Single `itoa_base` for integers, hexadecimals, and pointers
- ✅ **Minimalist design**: No bonus conversions, focused core implementation
- ✅ **Memory efficient**: No unnecessary allocations
- ✅ **Custom `write`-based output**: No `printf` or `puts` in core logic

## 🛠️ Technical Approach

### Core Function (`ft_printf`)
```c
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
	
```

### Unified Number Conversion (`itoa_base`)
```c
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


char	*ft_itoa(unsigned long n, char *base, int blen)
{
	char	*str;
	int		len;

	len = ft_lencount(n, blen);
	str = (char *)malloc((len-- + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len + 1] = 0;
	while (len >= 0)
	{
		str[len--] = base[n % blen];
		n = n / blen;
	}
	return (str);
}
```

## 📋 Supported Conversions

| Conversion | Description | Example Output |
|------------|-------------|----------------|
| `%c` | Single character | `A` |
| `%s` | String | `hello` |
| `%p` | Pointer address | `0x1a2b3c` |
| `%d` / `%i` | Signed integer | `-42` |
| `%u` | Unsigned integer | `123` |
| `%x` | Lowercase hex | `1a3f` |
| `%X` | Uppercase hex | `1A3F` |

## 🔧 Build & Usage

### Compilation
```bash
make        # Produces libftprintf.a
make clean  # Removes object files
```

### Integration
```c
#include "ft_printf.h"

int main(void) {
    ft_printf("Hex: %x, Pointer: %p\n", 255, &main);
}
```

## 🧠 Key Learnings
1. **Variadic Functions**: Mastery of `va_start`, `va_arg`, `va_end`
2. **Unified Design**: Single conversion path for all number types

## ⚠️ Limitations
- No floating point (`%f`, `%e`)
- No width/precision modifiers
- No `%n` conversion

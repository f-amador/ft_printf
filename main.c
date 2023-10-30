

#include <../include/ft_libft.h>

int main()
{
int num = 42;
double value = 3.14159;

printf("%d\n", num);         // Simple integer output
printf("%+d\n", num);        // Integer output with explicit sign
printf("% d\n", num);        // Integer output with space for positive numbers

printf("%f\n", value);       // Simple floating-point output
printf("%+f\n", value);      // Floating-point output with explicit sign
printf("%#f\n", value);      // Floating-point output with always-printed decimal point

}

#include <unistd.h>

/*
 * ft_atoi: converts a string to an integer (handles only positive numbers)
 */
int ft_atoi(char *str)
{
	int i = 0;
	int result = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return result;
}

/*
 * print_hex_rec: recursively prints the hex digits from most significant to least
 */
void print_hex_rec(unsigned int n)
{
	char *hex = "0123456789abcdef";

	if (n >= 16)
		print_hex_rec(n / 16); // recurse on the quotient
	write(1, &hex[n % 16], 1); // print the current digit
}

/*
 * main: parses the argument, calls conversion, prints result
 */
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int number = ft_atoi(argv[1]);
		print_hex_rec(number);
	}
	write(1, "\n", 1); // always end with a newline
	return 0;
}

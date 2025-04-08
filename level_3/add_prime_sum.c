#include <unistd.h>

/**
 * ft_atoi:
 * This function converts a string to an integer.
 * It only handles positive numbers and skips any leading whitespace
 * and an optional '+' sign.
 */
int ft_atoi(const char *str)
{
	int i = 0;
	int result = 0;

	// Skip whitespace characters (space, tab, etc.)
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;

	// Skip a plus sign if present (we don't process negative numbers)
	if (str[i] == '+')
		i++;

	// Convert each digit character into the corresponding integer value.
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return result;
}

/**
 * is_prime:
 * This function checks if a number is prime.
 * It returns 1 if 'n' is prime and 0 otherwise.
 *
 * A number less than 2 is not prime.
 * For numbers 2 and above, we check divisibility from 2 to n-1.
 * (Note: For efficiency, one could check up to sqrt(n), but here the input is small.)
 */
int is_prime(int n)
{
	int i;

	if (n < 2)
		return 0;

	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return 0; // Found a divisor, so n is not prime.
		i++;
	}
	return 1; // No divisors found, so n is prime.
}

/**
 * ft_putchar:
 * This function writes a single character to the standard output.
 */
void ft_putchar(char c)
{
	write(1, &c, 1);
}

/**
 * ft_putnbr:
 * This function prints an integer number to the standard output.
 * It works recursively by printing the higher order digits first.
 */
void ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);		// Recursively print the digits before the last one.
	ft_putchar((n % 10) + '0'); // Print the last digit.
}

/**
 * 
 * main:
 * The main function of the program.
 *
 * It checks the number of arguments and converts the argument to an integer.
 * If the input is valid and positive, it sums all prime numbers less than or equal to it.
 * Otherwise, it outputs "0" followed by a newline.
 */
int main(int argc, char **argv)
{
	int num;
	int i;
	int sum;

	// If the program does not receive exactly one argument, print "0" and exit.
	if (argc != 2)
	{
		ft_putchar('0');
		ft_putchar('\n');
		return 0;
	}

	// Convert the argument from a string to an integer.
	num = ft_atoi(argv[1]);

	// If the number is less than or equal to 0, print "0" and exit.
	if (num <= 0)
	{
		ft_putchar('0');
		ft_putchar('\n');
		return 0;
	}

	// Initialize sum to hold the total of prime numbers.
	sum = 0;

	// Loop through every number from 2 to 'num' (1 is not prime).
	i = 2;
	while (i <= num)
	{
		// If 'i' is a prime number, add it to the sum.
		if (is_prime(i))
			sum += i;
		i++;
	}

	// Output the sum of prime numbers.
	ft_putnbr(sum);
	// Print a newline at the end.
	ft_putchar('\n');

	return 0;
}

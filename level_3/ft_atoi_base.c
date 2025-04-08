/*
 * ft_atoi_base:
 * This function converts the string 'str', which represents a number in base 'str_base'
 * (where str_base is between 2 and 16), into an integer in base 10.
 *
 * The allowed characters in the string are:
 * - For digits: '0' to '9'
 * - For letters: 'a' to 'f' or 'A' to 'F' (only used when the base is greater than 10)
 *
 * The function also handles an optional leading minus sign ('-') to denote negative numbers.
 * A plus sign ('+') is allowed as the first character as well.
 *
 * If a character is encountered that is not valid for the given base, the conversion stops.
 *
 * Allowed functions: None.
 */

int ft_atoi_base(const char *str, int str_base)
{
	int i;		// Index to traverse the string
	int sign;	// To handle negative numbers
	int result; // The resulting converted number
	int digit;	// To store the value of the current digit

	// Check if the provided base is valid (base must be between 2 and 16).
	if (str_base < 2 || str_base > 16)
		return (0);

	i = 0;
	sign = 1;
	result = 0;

	// Handle the sign: if the first character is '-' then the number is negative.
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	// Optionally, if the first character is '+', just skip it.
	else if (str[i] == '+')
	{
		i++;
	}

	// Process each character of the string until the end.
	while (str[i])
	{
		// Check if the current character is a digit (0-9)
		if (str[i] >= '0' && str[i] <= '9')
			digit = str[i] - '0';
		// Check for lowercase letters (a-f) for bases above 10.
		else if (str[i] >= 'a' && str[i] <= 'f')
			digit = str[i] - 'a' + 10;
		// Check for uppercase letters (A-F) for bases above 10.
		else if (str[i] >= 'A' && str[i] <= 'F')
			digit = str[i] - 'A' + 10;
		else
			break; // If the character is not recognized, exit the loop.

		// If the digit is not valid for the given base, stop processing.
		if (digit >= str_base)
			break;

		// Multiply the current result by the base and add the current digit.
		result = result * str_base + digit;
		i++;
	}

	// Return the computed result multiplied by the sign.
	return (result * sign);
}

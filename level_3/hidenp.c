#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0; // index for s1
	int j = 0; // index for s2

	// if not exactly 2 arguments, just print newline and exit
	if (argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}

	// walk through s2 and try to match all characters of s1 in order
	while (argv[1][i] != '\0' && argv[2][j] != '\0')
	{
		if (argv[1][i] == argv[2][j])
			i++; // move to next char in s1 only if matched
		j++;	 // always move through s2
	}

	// if we reached the end of s1, all chars were found in order
	if (argv[1][i] == '\0')
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);

	return 0;
}

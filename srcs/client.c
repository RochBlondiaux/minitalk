#include "../includes/minitalk.h"

int main(int argc, char **argv)
{
	int ret;

	if (argc < 3)
		return (EXIT_FAILURE);
	ret = kill(ft_atoi(argv[1]), SIGTERM);
	if (ret == -1)
		return (EXIT_FAILURE);
}
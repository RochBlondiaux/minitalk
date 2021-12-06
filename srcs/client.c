/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:09:50 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/06 12:50:11 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	send_char(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(30);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(30);
	}
}

int	main(int argc, char **argv)
{
	int	srv_pid;

	if (argc < 3)
	{
		ft_putstr_fd(MISSING_ARG, 2);
		return (EXIT_FAILURE);
	}
	srv_pid = ft_atoi(argv[1]);
	if (srv_pid == 0 && argv[1][0] != '0')
	{
		ft_putstr_fd(INVALID_PID, 2);
		return (EXIT_FAILURE);
	}
	if (kill(srv_pid, 0) == -1)
	{
		ft_putstr_fd(UNKNOWN_PID, 2);
		return (EXIT_FAILURE);
	}
	send_char(srv_pid, argv[2]);
	return (0);
}

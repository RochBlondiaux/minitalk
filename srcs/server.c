/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:09:58 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/06 14:00:36 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static t_client	g_client;

static void	handle_action(int sig, siginfo_t *info, void *context)
{
	(void) context;
	if (!g_client.pid)
	{
		g_client.index = 0;
		g_client.pid = info->si_pid;
		ft_putstr_fd("Received (From #", 1);
		ft_putnbr_fd(g_client.pid, 1);
		ft_putstr_fd("): ", 1);
	}
	g_client.c |= (sig == SIGUSR2);
	if (++g_client.index == 8)
	{
		g_client.index = 0;
		if (!g_client.c)
		{
			g_client.pid = 0;
			ft_putchar_fd('\n', 1);
			return ;
		}
		ft_putchar_fd(g_client.c, 1);
		g_client.c = 0;
	}
	else
		g_client.c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_action;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

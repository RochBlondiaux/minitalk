/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:09:50 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/06 11:10:16 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	int	ret;

	if (argc < 3)
		return (EXIT_FAILURE);
	ret = kill(ft_atoi(argv[1]), SIGTERM);
	if (ret == -1)
		return (EXIT_FAILURE);
}

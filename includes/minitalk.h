/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:30:57 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/06 12:39:05 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

/**
 * Libraries
 */
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include "../libft/libft.h"

/**
 * Constants
 */
# define UNKNOWN_PID "Error: Unknown pid!\n"
# define INVALID_PID "Error: Invalid pid!\n"
# define MISSING_ARG "Error: Missing argument!\n"
# define MAX_CLIENTS 100

/**
 * Structures
 */
typedef struct s_client
{
	unsigned char	c;
	int				index;
	pid_t			pid;
}					t_client;

#endif

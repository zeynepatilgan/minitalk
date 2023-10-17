/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:01:24 by zeatilga          #+#    #+#             */
/*   Updated: 2023/10/17 16:36:11 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendbit(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(1, "Check the entered arguments.!", 35);
		write(1, "(client, pid, string)\n", 22);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
		ft_sendbit(pid, (argv[2][i++]));
	ft_sendbit(pid, '\n');
	return (0);
}

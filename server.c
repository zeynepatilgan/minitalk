/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:01:16 by zeatilga          #+#    #+#             */
/*   Updated: 2023/10/06 16:09:17 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handle(int sig)
{
	static int	bit = 128;
	static int	c = 0;

	if (sig == SIGUSR1)
		c = c + bit;
	bit = bit / 2;
	if (bit == 0)
	{
		write(1, &c, 1);
		bit = 128;
		c = 0;
	}
}

int	main(void)
{
	write(1, "PID:", 4);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, ft_handle);
	signal(SIGUSR2, ft_handle);
	while (1)
		pause();
}

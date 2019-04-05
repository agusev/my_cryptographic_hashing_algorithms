/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:05:19 by agusev            #+#    #+#             */
/*   Updated: 2019/04/04 22:25:00 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		ft_bonus_ssl(t_gen *g, int confirm, char *red)
{
	while (confirm == 0)
	{
		write(1, "ft_ssl> ", 8);
		fake_gnl(&red);
		if (ft_strcmp(red, "md5") == 0)
			confirm = 1;
		else if (ft_strcmp(red, "sha256") == 0)
			confirm = 2;
		else if (ft_strcmp(red, "sha256") == 0)
			confirm = 3;
		else if (ft_strcmp(red, "quit") == 0)
			return ;
		else
			error(red);
		free(red);
	}
	fake_gnl_all(&red, 0);
	if (confirm == 1)
		go_md5(red, g);
	else if (confirm == 2)
		go_sha256(red, g);
	else if (confirm == 3)
		go_sha256(red, g);
	return ;
}

void		file_no_rotat(t_gen *g, char **argv)
{
	if (!g->f_q)
	{
		if (ft_strcmp(argv[1], "sha256") == 0)
			ft_putstr("SHA256 (");
		else if (ft_strcmp(argv[1], "sha256") == 0)
			ft_putstr("SHA256 (");
		else
			ft_putstr("MD5 (");
		ft_printf("%s) = ", argv[g->pars]);
	}
	if (ft_strcmp(argv[1], "sha256") == 0)
		go_sha256(g->stdin, g);
	else if (ft_strcmp(argv[1], "sha256") == 0)
		go_sha256(g->stdin, g);
	else
		go_md5(g->stdin, g);
	ft_putchar('\n');
}

void		file_rotat(t_gen *g, char **argv)
{
	if (no_such_file(g, argv) == -1)
		return ;
	fake_gnl_all(&g->stdin, g->fd);
	if (!g->f_r)
		file_no_rotat(g, argv);
	else
		extra(g, argv);
	free(g->stdin);
	close(g->fd);
	g->pars++;
}

void		md5_sha(t_gen *g, char **argv, int argc)
{
	pars_entre(g, argc, argv);
	if (g->f_p || (!g->nb_file && !g->f_s))
	{
		fake_gnl_all(&g->stdin, 0);
		if (g->f_p)
			ft_putstr(g->stdin);
		if (ft_strcmp(argv[1], "sha256") == 0)
			go_sha256(g->stdin, g);
		else if (ft_strcmp(argv[1], "sha256") == 0)
			go_sha256(g->stdin, g);
		else
			go_md5(g->stdin, g);
		ft_putstr("\n");
		free(g->stdin);
	}
	g->pars = 2;
	while (g->pars < argc)
		if (print_s(g, argv, argc) == -1)
			break ;
	while (g->pars < argc)
		file_rotat(g, argv);
}

int			main(int argc, char **argv)
 {
	t_gen	g;
	if (argc == 1)
	{
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	}
 	if (argc == 1)
		ft_bonus_ssl(&g, 0, NULL);
	if (argc == 1)
		return (0);
	if (ft_strcmp(argv[1], "md5") == 0 || ft_strcmp(argv[1], "sha256") == 0
		|| ft_strcmp(argv[1], "sha256") == 0)
		md5_sha(&g, argv, argc);
	else
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\
		\n\nStandard commands:\
		\n\nMessage Digest commands:\nmd5\nsha256\n\nCipher\
		commands:\n", argv[1]);
	}
	return (0);
}

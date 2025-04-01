/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_rank_04.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:40:43 by lmonsat           #+#    #+#             */
/*   Updated: 2025/04/01 14:17:06 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------- MICROSHELL ------------- */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell_aai.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:30 by laichoun          #+#    #+#             */
/*   Updated: 2025/01/02 10:27:17 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void putstr_fd_2(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	cd(char **argv, int i)
{
	if (i != 2)
		return (putstr_fd_2("error: cd: bad arguments\n"), 1);
	if (chdir(argv[1]) < 0)
	{
		putstr_fd_2("error: cd: cannot change directory to ");
		putstr_fd_2(argv[1]);
		putstr_fd_2("\n");
		return (1);
	}
	return (0);
}

void	set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe && (dup2(fd[end], end) < 0 || close(fd[0]) < 0 || close(fd[1]) < 0))
	{
		putstr_fd_2("error: fatal\n");
		exit(1);
	}
}

int	exec(char **argv, int i, char **envp)
{
	int	has_pipe;
	int	pid;
	int	fd[2];
	int	status;

	has_pipe = argv[i] && !strcmp(argv[i], "|");
	if (!has_pipe && !strcmp(argv[0], "cd"))
		return (cd(argv, i));
	if (has_pipe && pipe(fd) < 0)
    {
        putstr_fd_2("error: fatal\n");
        exit(1);
    }
	if ((pid = fork()) < 0)
    {
        putstr_fd_2("error: fatal\n");
        exit(1);
    }
	if (pid == 0)
	{
		argv[i] = 0;
		set_pipe(has_pipe, fd, 1);
		
		if (!strcmp(*argv, "cd"))
			exit(cd(argv, i));
		
		execve(*argv, argv, envp);
		putstr_fd_2("error: cannot execute ");
		putstr_fd_2(*argv);
		putstr_fd_2("\n");
		exit(1);
	}
	waitpid(pid, &status, 0);
	set_pipe(has_pipe, fd, 0);
	return (WIFEXITED(status) && WEXITSTATUS(status));
}


int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	int	i = 0;
	int	status = 0;

	while (argv[i])
	{
		argv += i + 1; // permet de sauter | ou ; et d'aller a l'arg suivant
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (i)
			status = exec(argv, i, envp);
	}
	return (status);
}
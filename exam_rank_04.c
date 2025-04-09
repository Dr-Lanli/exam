
/* -------------- MICROSHELL ------------- */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#pragma region microshell_std

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

/*
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
}*/

#pragma endregion microshell_std


/* -------------------- */


#pragma region microshell_custom

// Affiche une chaîne sur la sortie d'erreur
void	print_error(const char *msg)
{
	while (*msg)
		write(2, msg++, 1);
}

// Implémentation de la commande 'cd'
int	builtin_cd(char **args)
{
	if (!args[1] || args[2])
	{
		print_error("error: cd: bad arguments\n");
		return (1);
	}
	if (chdir(args[1]) < 0)
	{
		print_error("error: cd: cannot change directory to ");
		print_error(args[1]);
		print_error("\n");
		return (1);
	}
	return (0);
}

// Redirige les entrées/sorties si un pipe est utilisé
void	setup_pipe(int is_pipe, int *pipe_fd, int end)
{
	if (is_pipe)
	{
		if (dup2(pipe_fd[end], end) < 0 || close(pipe_fd[0]) < 0 || close(pipe_fd[1]) < 0)
		{
			print_error("error: fatal\n");
			exit(1);
		}
	}
}

// Exécute une commande avec ou sans pipe
int	execute_command(char **args, int split_index, char **env)
{
	int	is_pipe = args[split_index] && !strcmp(args[split_index], "|");
	int	pipe_fd[2];
	int	pid;
	int	status;

	if (!is_pipe && !strcmp(args[0], "cd"))
		return (builtin_cd(args));

	if (is_pipe && pipe(pipe_fd) < 0)
	{
		print_error("error: fatal\n");
		exit(1);
	}

	if ((pid = fork()) < 0)
	{
		print_error("error: fatal\n");
		exit(1);
	}

	if (pid == 0) // processus enfant
	{
		args[split_index] = NULL;
		setup_pipe(is_pipe, pipe_fd, STDOUT_FILENO);
		
		if (!strcmp(args[0], "cd"))
			exit(builtin_cd(args));

		execve(args[0], args, env);
		print_error("error: cannot execute ");
		print_error(args[0]);
		print_error("\n");
		exit(1);
	}

	// processus parent
	waitpid(pid, &status, 0);
	setup_pipe(is_pipe, pipe_fd, STDIN_FILENO);
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

// Point d'entrée du programme
int	main(int argc, char *argv[], char *env[])
{
	(void)argc;
	int	status = 0;
	int	cmd_len;

	while (*argv)
	{
		argv++; // passe le binaire lui-même
		cmd_len = 0;

		// Trouve la fin de la commande actuelle (avant un '|' ou ';')
		while (argv[cmd_len] && strcmp(argv[cmd_len], "|") && strcmp(argv[cmd_len], ";"))
			cmd_len++;

		if (cmd_len > 0)
			status = execute_command(argv, cmd_len, env);

		argv += cmd_len;
		if (*argv && (!strcmp(*argv, "|") || !strcmp(*argv, ";")))
			argv++;
	}
	return (status);
}

#pragma endregion microshell_custom
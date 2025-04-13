#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int execute_commande(char *argv[], int cmd_split, char *envp[])
{
	int status;
	int pid;
	int pipe_fd[2];
	int is_pipe = argv[cmd_split] && !strcmp(argv[cmd_split], "|");

	if (!is_pipe && !strcmp(argv[0], "cd"))
	{
		return (exec_cd(argv));
	}
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
	if (pid == 0)
	{
		argv[cmd_split] = NULL;
		setup_pipe(is_pipe, pipe_fd, STDIN_FILENO);
		if (!strcmp(argv[0], "cd"))
		{
			exit(exec_cd(argv));
		}
		execve(argv[0], argv, envp);
		//error
	}

	waitpid(pid, &status, 0);
	setup_pipe(is_pipe, pipe_fd, STDIN_FILENO);
	return(WIFEXITED(status) && WEXISTATUS(status));
}

int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	int status;
	int cmd_len;

	while (*argv)
	{
		cmd_len = 0;
		argv++;
		while (argv[cmd_len] && strcmp(argv[cmd_len], "|") && strcmp(argv[cmd_len], ";"))
		{
			cmd_len++;
		}
		if (cmd_len > 0)
		{
			status = execute_command(argv, cmd_len, envp);
		}
		argv += cmd_len;
		if (argv[cmd_len] && (!strcmp(argv[cmd_len], "|") || !strcmp(argv[cmd_len], ";")))
		{
			argv++;
		}
	}
	return (status);
}
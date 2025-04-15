#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void print_error(const char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	exec_cd(char **argv)
{
	if (!argv[1] || argv[2])
	{
		print_error("error: cd: bad arguments\n");
		return (1);
	}
	if (chdir(argv[1]) < 0)
	{
		print_error("error: cd: cannot change directory to ");
		print_error(argv[1]);
		print_error("\n");
		return (1);
	}
	return (0);
}

void	setup_pipe(int is_pipe, int *pipe_fd, int end)
{
    if (is_pipe && (dup2(pipe_fd[end], end) < 0 || close(pipe_fd[0]) < 0 || close(pipe_fd[1]) < 0))
    {
        print_error("error: fatal\n");
        exit(1);
    }
}

int execute_command(char *argv[], int cmd_split, char *envp[])
{
    int	is_pipe = argv[cmd_split] && !strcmp(argv[cmd_split], "|");
	int	pipe_fd[2];
	int	pid;
	int	status;

	if (!is_pipe && !strcmp(argv[0], "cd"))
		return (exec_cd(argv));

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
		setup_pipe(is_pipe, pipe_fd, STDOUT_FILENO);
		
		if (!strcmp(argv[0], "cd"))
			exit(exec_cd(argv));

		execve(argv[0], argv, envp);
		print_error("error: cannot execute ");
		print_error(argv[0]);
		print_error("\n");
		exit(1);
	}
	waitpid(pid, &status, 0);
	setup_pipe(is_pipe, pipe_fd, STDIN_FILENO);
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	int status = 0;
	int cmd_len;

	while (*argv)
	{
		argv++;
		cmd_len = 0;
		while (argv[cmd_len] && strcmp(argv[cmd_len], "|") && strcmp(argv[cmd_len], ";"))
			cmd_len++;
		if (cmd_len > 0)
			status = execute_command(argv, cmd_len, envp);
		argv += cmd_len;
	}
	return (status);
}
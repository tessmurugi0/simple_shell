#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
	char *buffer;
	const char* prompt = "$";
	ssize_t buffer_size = 0;

	while (1)
	{
		write (STDOUT_FILENO, prompt, strlen(prompt);
	}

	if (buffer_size == -1)
	{
		perror("Error");
		free(buffer);
		exit EXIT;
		}
	pid_t pid = fork();

        if (pid < 0) {
            // Forking error
            perror("fork");
        } else if (pid == 0) {

#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <readline/history.h>

int main(void)
{
	char *line;

	line = readline("shell: ");
	printf("%s\n", line);
}

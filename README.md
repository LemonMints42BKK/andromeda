# andromeda
miniShell project

readline()

char *readline (char *prompt);
ex:
	char *line = readline ("Enter a line: ");

The function readline () prints a prompt and then reads and returns a single line of text from the user. The line readline returns is allocated with malloc (); you should free () the line when you are done with it. The declaration for readline in ANSI C is

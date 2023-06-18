#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EVN_VARLIST "TERM_PROGRAM TERM SHELL TMPDIR TERM_PROGRAM_VERSION \
TERM_SESSION_ID USER COMMAND_MODE SSH_AUTH_SOCK __CF_USER_TEXT_ENCODING PATH \
LaunchInstanceID PWD LANG ITERM_PROFILE XPC_FLAGS XPC_SERVICE_NAME SHLVL HOME \
COLORFGBG LC_TERMINAL_VERSION LOGNAME ITERM_SESSION_ID LOGNAME LC_TERMINAL \
SECURITYSESSIONID SQLITE_EXEMPT_PATH_FROM_VNODE_GUARDS COLORTERM"

static size_t	next_pos(char const *s, char c)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0' && s[index] != c)
		index++;
	return (index);
}

static size_t	size_sp(char const *s, char c)
{
	char	*ch;
	size_t	size;

	ch = (char *)s;
	size = 0;
	while (*ch != '\0')
	{
		while (*ch != '\0' && *ch != c)
			ch++;
		while (*ch != '\0' && *ch == c)
			ch++;
		size++;
	}
	return (size);
}

static void	ch_split(char **array, const char *s, char c)
{
	char	*ch;
	size_t	index;
	size_t	j;
	size_t	k;

	ch = (char *)s;
	index = next_pos(ch, c);
	k = 0;
	while (index)
	{
		array[k] = malloc(sizeof(char) * (index + 1));
		j = 0;
		while (j < index)
			array[k][j++] = *(ch++);
		array[k][j] = '\0';
		k++;
		while (*ch != '\0' && *ch == c)
			ch++;
		index = next_pos(ch, c);
	}
	array[k] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	while (*s != '\0' && *s == c)
		s++;
	array = malloc(sizeof(char *) * (size_sp(s, c) + 1));
	if (!array)
		return (NULL);
	ch_split(array, s, c);
	if (!array)
		free(array);
	return (array);
}

int	get_env(void)
{
	char	**env_name_list;
	char	*env_name;
	char	*env_value;

	env_name_list = ft_split(EVN_VARLIST, ' ');
	while (*env_name_list)
	{
		env_name = *env_name_list;
		env_value = getenv(env_name);
		printf("%s=%s\n", env_name, env_value);
        // printf("%s\n", *env_name_list);
		env_name_list++;
	}
	return (EXIT_SUCCESS);
}

int main(void)
{
	get_env();
	return (EXIT_SUCCESS);
}

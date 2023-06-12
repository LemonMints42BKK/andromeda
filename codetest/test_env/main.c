
#include "utiles.h"

size_t	ft_strlen(const char *s)
{
	size_t	ct;

	ct = 0;
	while (s[ct] != '\0')
	{
		ct++;
	}
	return (ct);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize)
	{
		while ((i < (dstsize - 1)) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

int main(int argc, char **argv)
{
    t_list *head;
    t_list *ptr;

    head = init_env(argc, argv);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%s=%s\n", ptr->name, ptr->var);
        ptr = ptr->next;
    }
}
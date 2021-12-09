#include "so_long.h"

int	ft_str_countc(char *str, char c)
{
	int count;

	count = 0;
	if (!str)
		return (-1);
	while (*str)
	{ 
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

t_bool	ft_strchr_set(char *str, char *set)
{
	char	*checklist;
	int	set_len;

	set_len = ft_strlen(set);
	checklist = (char *)malloc(set_len + 1);
	checklist[set_len] = '\0';
	ft_memset((void *)checklist, '0', set_len);
	while (*str && ft_strchr(checklist, '0'))
	{
		checklist[ft_strindex(set, *str)] = '1';
		str++;
	}
	free(checklist);
	if (!*str)
		return (0);
	return (1);
}

char	*ft_str_fusion(char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	if (!new)
		return (NULL);
	free(s1);
	return (new);
}

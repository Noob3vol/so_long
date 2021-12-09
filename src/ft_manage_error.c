#include "so_error.h"

void	ft_print_error(int error_nb)
{
	static char	*error_mess[] = {
		"Map is open",
		"Map is not rectangular",
		"Map is lacking some elements",
		"Map is containing same player twice"
	};

	ft_putendl(error_mess[error_nb]);
}

void	ft_manage_error(int error_mod)
{
	static int errnb = -1;

	if (errnb != -1)
		ft_print_error(errnb);
	else
	{
		ft_putendl_fd("Error", 2);
		if (error_mod == -1)
			ft_putendl(strerror(errno));
		else
			errnb = error_mod;
	}
}

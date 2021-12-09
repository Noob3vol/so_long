#ifndef SO_ERROR_H
# define SO_ERROR_H

# include <errno.h>
# include "libft.h"

enum	error_nb {
	MAP_OPEN,
	MAP_NOT_REC,
	MAP_CHARSET_NOT_FOUND,
	MAP_PLAYER_UBIQUITY
};


void	ft_print_error(int error_nb);
void	ft_manage_error(int error_mod);

#endif

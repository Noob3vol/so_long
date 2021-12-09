#include "so_long.h"
#include <stdio.h>

void	ft_print_map(t_map map)
{
	int i;

	i = 0;
	while (i < map.height)
	{
		write(1, &(map.layout[i * map.width]), map.width);
		ft_putchar('\n');
		i++;
	}
}

int	ft_get_tiles_color(int index)
{
	int	tiles_color[] = {
		~0,
		WHITE,
		BLUE,
		RED,
		GREEN
	};

	return (tiles_color[index]);
}

int	ft_assign_tiles(void *mlx_ptr, t_map *map, t_tiles *tiles)
{
	int	tiles_len;
	int	i;

	tiles_len = ft_strlen(tiles->charset);
	i = 0;
	while (i < tiles_len)
	{
		(tiles->img[i]).width = SCRN_WIDTH / map->width;
		(tiles->img[i]).height = SCRN_HEIGHT / map->height;
		tiles->img[i].id = mlx_new_image(mlx_ptr
				, (tiles->img[i]).width
				, (tiles->img[i]).height);
		ft_memset((void *)(tiles->img[i].layout), ft_get_tiles_color(i)
				, tiles->img[i].width * tiles->img[i].height);
		i++;
	}
	return (0);
}

int	ft_init_tiles(void *mlx_ptr, t_map *map, t_tiles *tiles)
{
	int	tiles_set_len;

	tiles->charset = ft_strdup(CHARSET);
	tiles_set_len = ft_strlen(tiles->charset);
	tiles->img = (t_img *)malloc(sizeof(t_img) * tiles_set_len);
	if (!tiles->img)
		return (0);
	ft_assign_tiles(mlx_ptr, map, tiles);
	return (1);
}

int	ft_load_item(t_env *env, int i)
{
	t_list		*new_node;
	t_sprite	*new_item;

	new_item = (t_sprite *)malloc(sizeof(t_sprite));
	if (!new_item)
		return (0);
	new_item->img.id = NULL;
	new_item->pos.width = (float)(i % env->map.width) + 0.5;
	new_item->pos.height = (float)(i  / env->map.width) + 0.5;
	new_node = ft_lstnew((void *)new_item);
	if (!new_node)
	{
		free(new_item);
		return (0);
	}
	ft_lstadd_front(&(env->item_ls), new_node);
	return (1);
}

int	ft_load_mob(t_env *env, t_map *map)
{
	int		i;

	i = 0;
	env->item_ls = NULL;
	while (map->layout[i])
	{
		if (map->layout[i] == 'P')
		{
			env->player.pos.width = (float)(i % map->width) + 0.5;
			env->player.pos.height = (float)(i  / map->width) + 0.5;
			map->layout[i] = '0';
		}
		else if (map->layout[i] == 'C')
		{
			if (!ft_load_item(env, i))
				return (0);
			map->layout[i] = '0';
		}
		i++;
	}
	return (1);
}

//	int	ft_init_sprite(t_img *item, t_img *player)
//	{
//		item->pix.len.width = 
//		((t_sprite *)env->item_ls->content)->img.id = ft
//		env
//	}

void	ft_print_item_ls(void *item)
{
	printf("width = %.1f, height = %.1f\n", ((t_sprite *)item)->pos.width, ((t_sprite *)item)->pos.height);
}

int	ft_free_game(t_env *env)
{
	int	i;

	if (env->map.layout)
		free(env->map.layout);
	if (env->mlx.scrn.img.id)
		mlx_destroy_image(env->mlx.id, env->mlx.scrn.img.id);
	if (env->player.img.id)
		mlx_destroy_image(env->mlx.id
				, ((t_sprite *)env->player.img.id));
	if (env->item_ls)
	{
		if (((t_sprite *)env->item_ls->content)->img.id)
		{
		ft_putendl("HELLO");
			mlx_destroy_image(env->mlx.id
					, ((t_sprite *)env->item_ls->content)->img.id);
		}
		ft_lstclear(&(env->item_ls), free);
	}
	if (env->tiles.charset)
	{
		free(env->tiles.charset);
		i = 0;
		while (i < (int)ft_strlen(env->tiles.charset))
		{
			mlx_destroy_image(env->mlx.id, env->tiles.img[i].id);
			i++;
		}
	}
	if (env->mlx.scrn.id)
		mlx_destroy_window(env->mlx.id, env->mlx.scrn.id);
	if (env->mlx.id)
		mlx_destroy_display(env->mlx.id);
	free(env->mlx.id);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	game_data;

	if (ac == 1 || ft_strcmp_end(av[1], ".ber"))
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	ft_memset(&game_data, 0, sizeof(t_env));
	ft_print_memory(&(game_data.item_ls), sizeof(void *));
	if (!ft_load_map(&(game_data.map), av[1]))
	{
		ft_manage_error(42);
		return (-1);
	}
	ft_print_memory(&(game_data.item_ls), sizeof(t_list *));
	if (!ft_load_mob(&game_data, &(game_data.map)))
		return (-1);
	ft_print_memory(&(game_data.item_ls), sizeof(t_list *));
	ft_lstiter(game_data.item_ls, ft_print_item_ls);
	//	ft_putendl("hello");
	//	game_data.mlx.id = mlx_init();
	//	game_data.mlx.scrn.id = mlx_new_window(game_data.mlx.id, SCRN_WIDTH
	//			, SCRN_HEIGHT, "so_long");
	//	game_data.mlx.scrn.img.id = mlx_new_image(game_data.mlx.id, SCRN_WIDTH
	//			, SCRN_HEIGHT);
	//	//game_data.mlx_ptr = mlx_init();
	//	game_data.map.layout = ft_load_map(*(av + 1));
		ft_free_game(&game_data);
	return (0);
}

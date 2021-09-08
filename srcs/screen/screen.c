/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:39:46 by dnicki            #+#    #+#             */
/*   Updated: 2021/09/08 20:49:52 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

void	draw_screen(t_scene *scene, t_data *img, int fd)
{
	int	h;
	int	w;
	int	i;

	h = scene->height;
	w = scene->width;
	i = h;
	while (i > 0)
	{
		i--;
		write(fd, img->addr + i * img->line_length, img->line_length);
	}
}

void	filler(t_bitmap_fileheader *bmfh, t_bitmap_infoheader *bmih,
			int w, int h)
{
	t_bitmap_fileheader	fh;
	t_bitmap_infoheader	ih;

	fh.bf_filesize = sizeof(fh) + sizeof(ih) + 4 * w * h + 2;
	fh.bf_reserved1 = 0;
	fh.bf_reserved2 = 0;
	fh.bf_offs_bits = 0x36;
	ih.bi_size = sizeof(ih);
	ih.bi_width = w;
	ih.bi_height = h;
	ih.bi_planes = 1;
	ih.bi_bps = 32;
	ih.bi_compression = 0;
	ih.bi_image_size = 0;
	ih.bi_x_pxs_per_meter = 5000;
	ih.bi_y_pxs_per_meter = 5000;
	ih.bi_colors_used = 0;
	ih.bi_colors_important = 0;
	*bmfh = fh;
	*bmih = ih;
}

char	*get_file_name(char **argv)
{
	char	*ans;
	int		len;
	char	*tmp;

	ans = ft_strdup(argv[1]);
	len = ft_strlen(ans);
	--len;
	while (ans[len] != '/' && len >= 0)
	{
		if (ans[len] == '.')
			ans[len] = 0;
		len--;
	}
	ans = ft_strjoin_all_clear(ans, ft_strdup(".bmp"));
	tmp = ft_strdup(ans + len);
	free(ans);
	ans = ft_strjoin_all_clear(ft_strdup("screenshots"), tmp);
	return (ans);
}

void	screenshot(t_scene *scene, t_data *img, t_for_hook *for_close, char *argv[])
{
	int					fd;
	t_bitmap_fileheader	fh;
	t_bitmap_infoheader	ih;
	unsigned short		bfType;
	char				*name;

	printf("in screen\n");
	name = get_file_name(argv);
	fd = open(name, O_WRONLY | O_CREAT, 0666);
	free(name);
	filler(&fh, &ih, scene->width, scene->height);
	bfType = 0x4d42;
	write(fd, &bfType, 2);
	write(fd, &fh, sizeof(fh));
	write(fd, &ih, sizeof(ih));
	draw_screen(scene, img, fd);
	close(fd);
	printf("screen is done\n");
	_close(for_close);
}

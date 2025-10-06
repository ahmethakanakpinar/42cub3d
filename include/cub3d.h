/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 02:40:49 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/07 02:11:46 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H


# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
	int	shift;	
}		t_keys;

typedef struct s_vector
{
	double						x;
	double						y;
}								t_vector;

typedef struct s_player
{
	t_vector	pos;
    //Dünya koordinatlarındaki konum.
	t_vector	dir;
    // Bakış yönü vektörü (raycasting için).
	t_vector	plane;
    // Kamera düzlemi vektörü (FOV projeksiyonu).
	double		move_speed;
    // Yürüme/hareket hızı.
	double		rot_speed;
    // Dönüş hızı.
	t_keys		keys;
    // Basılı tuşlar durumu (girdi takibi).
}				t_player;



typedef struct s_map
{
	char		**grid;
    //grid: Harita karakter matrisi (duvar, boşluk, kapı, vs.).
	int			width;
    //width / height: Harita boyutları.
	int			height;
    //floor_color / ceiling_color: Zemin ve tavan renkleri (RGB packed int).
	int			floor_color;
	int			ceiling_color;
	char		player_start;
    //player_start: Başlangıç yönü karakteri (N, S, E, W).
	t_vector	player_pos;
    //player_pos: Başlangıç konumu (float vektör olarak).
    char		*north;
	char		*south;
	char		*east;
	char		*west;
    //north/south/east/west: Duvar yönü dokuları.
}				t_map;
//t_map: Harita ızgarası ve görsel/başlangıç yapılandırmaları.


// typedef struct s_texture
// {
// 	void						*img;
//     //MLX tarafında oluşturulmuş görüntü nesnesinin işaretçisi (mlx_new_image ile).
// 	char						*addr;
//     //addr: Bu görüntünün piksel verisinin başlangıç adresi (framebuffer’a doğrudan yazmak için).
// 	int							width;
// 	int							height;
//     //width / height: Dokunun piksel cinsinden boyutları.
// 	int							bpp;
//     //bpp: Bits per pixel; bir pikselin kaç bit tuttuğu (örn. 32).
// 	int							line_len;
//     //line_len: Bir satırın bellek uzunluğu (byte cinsinden); bir satırdan diğerine geçerken addr + y * line_len + x * (bpp/8) hesaplanır.
// 	int							endian;
//     //endian: Byte sıralaması; MLX’in geri döndürdüğü endianness bilgisi (renk bileşenlerinin okunma sırası için).
// 	char						*path;
//     //path: Bu dokunun yüklendiği dosya yolu (debug/temizleme işlemlerinde faydalı).
// }								t_texture;

typedef struct s_game
{
	void			*mlx;
	void			*win;
    //mlx / win: MLX context ve pencere işaretçileri.
	void			*img[2];
	char			*addr[2];
	int				current_buffer;
    //img[2] / addr[2] / current_buffer: Çift buffer görüntüler ve bellek adresleri; hangi buffer’ın aktif olduğu.
	int				bits_per_pixel;
	int				line_length;
	int				endian;
    //bits_per_pixel / line_length / endian: Görüntü tamponu format bilgileri.
	int				fd_map;
	char			*map_path;
    //fd_map / map_path: Harita dosyası tanıtıcısı ve yolu.
	t_map			map;
    //map: Yüklü harita verileri.
	t_player		p1;
    //p1: Oyuncu durumu.
	
}				t_game;
//t_game: Oyun genel durum konteyneri; tüm alt sistemleri bir araya toplar.

bool	validate_map_arguments(int argc, char **argv);
void	read_error(t_game *game);
void	cleanup_game(t_game *game);	
bool 	check_map_validation(t_game *game, char *path);

int		ft_isspace(int c);
bool	print_color_error(int f_count, int c_count);
bool	print_texture_error(int no, int so, int we, int ea);
bool	check_element_counts(t_game *game);


#endif

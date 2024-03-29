/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 23:55:46 by agusev            #+#    #+#             */
/*   Updated: 2019/04/20 23:57:21 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# include "ft_printf.h"
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

# define SWP(X, Y, S) {char *_a=(char *)(X),*_b=(char *)(Y),_t; int _s=(S);SWPW}
# define SWPW while(_s-- > 0){_t=*_a;*_a=*_b;*_b=_t;_a++;_b++;}
# define SWPINT(X, Y)	SWP(X, Y, sizeof(int))
# define SWPLNG(X, Y)	SWP(X, Y, sizeof(long))
# define SWPLLNG(X, Y)	SWP(X, Y, sizeof(long long))
# define SWPDBL(X, Y)	SWP(X, Y, sizeof(double))
# define SWPLDBL(X, Y)	SWP(X, Y, sizeof(long double))
# define SWPCHR(X, Y)	SWP(X, Y, sizeof(char))
# define SWPSTR(X, Y)	SWP(X, Y, sizeof(char *))

# define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
# define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list *alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_word_count(char const *s, char d);
char				*ft_extract_word(char const *s, char d, unsigned int n);
char				*ft_strshrink(char **s);
char				*ft_flatten_charr(char **a);
char				*ft_flatten_intarr(int *a, size_t n);
char				*ft_flatten_tlist(t_list const *list);
int					ft_strchri(const char *s, int c);
void				ft_strsetdel(char **dst, char *src);
int					ft_freeret(void **p, int ret);
void				ft_free_intarr(int **a, int count);
void				ft_free_charr(char **a, int count);
int					ft_strstri(const char *haystack, const char *needle);

void				ft_qsort(void *a, size_t cnt, size_t sz,
						int f(const void *, const void *));
int					fn_cmp_int(const void *a, const void *b);
int					fn_cmp_long(const void *a, const void *b);
int					fn_cmp_double(const void *a, const void *b);
int					fn_cmp_char(const void *a, const void *b);

#endif

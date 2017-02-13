/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:40:04 by jdesmare          #+#    #+#             */
/*   Updated: 2017/02/11 15:05:14 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <wchar.h>
# include <locale.h>
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
int					ft_char_size(int c);
void				ft_putwchar(wchar_t c);
void				ft_putnchar(char c, int nb);
size_t				ft_strlen(const char *s);
size_t				ft_strwlen(const wchar_t *s);
size_t				ft_strnwlen(const wchar_t *s, int n);
void				ft_putstr(const char *s);
void				ft_putwstr(const wchar_t *s);
void				ft_putnstr(char *s, int n);
void				ft_putnwstr(wchar_t *s, int n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strstr(const char *haystack, const char *needle);
void				ft_putnbr(long long int n);
void				ft_putoct(unsigned long long int n);
void				ft_putunbr(long long int n);
void				ft_putlunbr(unsigned long long int n);
int					ft_atoi(const char *nptr);
long int			ft_atol(const char *nptr);
char				*ft_strncat(char *dest, const char *src, size_t n);
void				ft_bzero(void *s, int n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack,
											const char *needle, size_t len);
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
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_countwords(const char *s, char c);
int					ft_power(int nb, int power);
char				*ft_strupcase(char *str);
int					ft_wordlen(const char *str, char c);
void				ft_swap(int *a, int *b);
char				*ft_strrev(char *str);
int					ft_sqrt(int nb);
void				ft_putnbr_base(long long int nb, int base);
void				ft_putnbr_base_min(long long int nb, int base);
char				*ft_strcdup(const char *s, char c);
int					ft_count_nb(long long int nb);
int					ft_count_lunb(unsigned long long int nb);
void				ft_print_hex(unsigned long long int nb);
void				ft_print_nhex(unsigned long long int nb, int i);
void				ft_print_uhex(unsigned long long int nb);
void				ft_print_uhex_maj(unsigned long long int nb);
int					ft_longer_size(int n1, int n2);
int					ft_smaller_size(int n1, int n2);
int					ft_puthex_size(unsigned long long int nb);
int					ft_putoct_size(unsigned long long int nb);
int					ft_ismin(int *tab, int size);
int					ft_ismax(int *tab, int size);
int					ft_is_sorted(int *tab, int size);
void				*ft_realloc(void *ptr, size_t size);

#endif

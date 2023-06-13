/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:23:47 by gsaiago           #+#    #+#             */
/*   Updated: 2023/06/13 19:49:24 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

enum e_read
{
	FT_LST = 1,
	FT_STR = 2,
	FT_MAT = 4,
	FT_N = 8,
	FT_NON = 16
};

/* read_file enum */
union u_read
{
	char			*str;
	void			*err;
	struct s_list	*lst;
};

/* smartptr_struct */
typedef struct s_meta
{
	void	(*dtor)(void *pointer);
	void	*ptr;
}	t_meta;

/* libft bonus struct */
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

int				ft_atoi(const char *str);
void			ft_bzero(void *b, size_t len);
void			*ft_calloc(size_t count, size_t size);
void			*ft_realloc(void *oldptr, size_t new_size);
int				ft_isalnum(int c);
int				ft_isspace(char c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t len);
void			*ft_memmove(void *dst,	const void *src, size_t len);
void			*ft_memset(void *dest, int c, size_t len);
char			*ft_strchr(const char *s, int c);
int				ft_strchrn(const char *line, char c);
char			*ft_strdup(char *s1, int flag);
char			*ft_strndup(char *s1, int n, int flag);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_putendl_fd(char *s, int fd);
char			*ft_strjoin(char *s1, char *s2, int flag);
char			*ft_itoa(int n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char *str, char c);
// libft bonus functions //
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
char			**ft_lst_to_mat(t_list *node);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
/* Ft_printf Functions */
int				ft_printf(const char *s, ...);
int				ft_putstr(char *s);
int				ft_printhex(const char *base, unsigned int b, unsigned int n);
unsigned int	ft_printptr(const char *base, void *n);
int				ft_putnbr(int nbr);
int				ft_putchar(int c);
/* GNL Functions */
char			*ft_strjoin_gnl(char *s1, char *s2);
char			*ft_staticptr(char *buffer);
char			*ft_returnptr(char *buffer);
char			*ft_gnl(int valid, int fd, char *sptr);
char			*get_next_line(int fd);
/* expanded libft */
void			ft_free_mat(char **mat);
char			**ft_lsttochrmat(t_list *node);
int				ft_mat_size(char **mat);
char			*ft_revstring(char *str);
void			*ft_read_file(int fd, int flags);
int				ft_isnumstr(char *str);
/* SMART POINTERS */
/* Ussage: <variable_name>__attribute__((cleanup(free_call))); */
void			sfree(void *ptr);
void			*smalloc(size_t size, void (*dtor)(void *));
void			free_call(void *ptr);
/* Dtr smart pointer functions */
void			destroy_matrix(void	*mat);

#endif

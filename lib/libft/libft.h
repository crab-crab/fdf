/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:17:35 by crabin            #+#    #+#             */
/*   Updated: 2025/07/15 12:10:19 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
// constants
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

// user defined data types
typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

// using <ctype.h>
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

// using <stdlib.h>
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *nptr);
char	*ft_sitoa(int n, char *result);
char	*ft_uitoa(unsigned int n, char *result);

// using <strings.h>
void	ft_bzero(void *s, size_t n);

// using <string.h>
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack,	const char *needle, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t dsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
char	*ft_strdup(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);

// Additional
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Doubly Linked List
t_list	*ft_lst_fill(int *arr, size_t size);
void	ft_lst_print(t_list *lst);
void	ft_lst_lenprint(t_list *lst, int size);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstinnit(int content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstcreate(t_list	*new);
void	lst_remove(t_list **lst_member);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del)(int));

// Stack Operations
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	rerotate(t_list **stack);
void	push(t_list **stack_a, t_list **stack_b);

// ft_printf
int		ft_printf(const char *format, ...);
int		pt_char(va_list *args);
int		pt_string(va_list *args);
int		pt_pointer(va_list *args);
int		pt_decimal(va_list *args);
int		pt_udecimal(va_list *args);
int		pt_hexi(va_list *args, const char *base_str);
int		pt_percent(void);
int		to_hex(const char *base_str, unsigned long input, char *result);
int		ft_printf(const char *format, ...);

#endif
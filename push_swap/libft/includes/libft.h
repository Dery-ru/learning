/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:59:49 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/09 14:08:55 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list1
{
	void			*content;
	struct s_list1	*next;
}					t_list1;

int		ft_atoi(const char *str);
void	ft_bzero(void *src, size_t len);
void	*ft_calloc(size_t num, size_t size);
int		ft_isalnum(int character);
int		ft_isalpha(int character);
int		ft_isascii(int character);
int		ft_isdigit(int character);
int		ft_isprint(int character);
void	*ft_memcpy(void *dst, const void *src, size_t size);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr(const void *src, int c, size_t n);
int		ft_memcmp(const void *src1, const void *src2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *src, int c, size_t len);
char	*ft_strchr(const char *str, int ch);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *str, int ch);
int		ft_tolower(int character);
int		ft_toupper(int character);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list1	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list1 **lst, t_list1 *new);
int		ft_lstsize(t_list1 *lst);
t_list1	*ft_lstlast(t_list1 *lst);
void	ft_lstadd_back(t_list1 **lst, t_list1 *new);
void	ft_lstdelone(t_list1 *lst, void (*del)(void*));
void	ft_lstclear(t_list1 **lst, void (*del)(void*));
void	ft_lstiter(t_list1 *lst, void (*f)(void *));
t_list1	*ft_lstmap(t_list1 *lst, void *(*f)(void *), void (*del)(void *));

int		get_next_line(int fd, char **line);

#endif
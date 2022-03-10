/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipelaez <diego.pelaez@hotmail.com.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:30:25 by dipelaez          #+#    #+#             */
/*   Updated: 2022/03/10 13:41:55 by dipelaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147783647

/**
 * @brief Checks if the passed character is alphabetic.
 * 
 * @param c This is the param to be checked.
 * @return This function returns non-zero value if c is an alphabetic, else it 
 * returns 0.
*/
int		ft_isalpha(int c);

/**
 * @brief Checks for an alphanumeric character; 
 * it is equivalent to (isalpha(c) || isdigit(c)).
 * 
 * @param c This is the param to be checked.
 * @return This function returns non-zero value if c is an alphanumeric, else it 
 * returns 0.
*/
int		ft_isalnum(int c);

/**
 * @brief Checks if the character is ASCII.
 * 
 * @param c This is the param to be checked.
 * @return This function returns non-zero value if c is an ASCII, else it 
 * returns 0.
*/
int		ft_isascii(int c);

/**
 * @brief Checks for a digit (0 through 9).
 * 
 * @param c This is the param to be checked.
 * @return This function returns non-zero value if c is a digit, else it 
 * returns 0.
*/
int		ft_isdigit(int c);

/**
 * @brief Checks for any printable character including space.
 * 
 * @param c This is the param to be checked.
 * @return This function returns non-zero value if c is printable, else it 
 * returns 0.
*/
int		ft_isprint(int c);

/**
 * @brief Calculates the length of the string pointed to by s,
 *  excluding the terminating null byte.
 * 
 * @param s This is the string whose lenght is to be found.
 * @return Returns the number of characters in the string pointed to by s.
*/
size_t	ft_strlen(const char *s);

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void	*dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t	n);
size_t	ft_strlcpy(char	*dst, char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const	char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char	*s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Returns a new string, which is the result 
 * of the concatenation of 's1' and 's2'.
 * 
 * @param s1 String 1 
 * @param s2 String 2.
 * @return The new String. NULL if the allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Returns a copy of 's1' with the characters specified in 'set'
 *  removed from the begining and the end of the string.
 * 
 * @param s1 String 
 * @param set Characters to be trimmed.
 * @return The trimmed string. NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates and returns an array of strings obtained by splitting 's' 
 * using the character 'c' as a delimiter. Array must be ended by a 
 * NULL pointer. 
 * 
 * @param s The string to be split. 
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split.
 * NULL if the allocation fails.
*/
char	**ft_split(char const *s, char c);

/**
 * @brief Allocates and returns a string representing the integer 
 * received as an argument.
 * Negative numbers must be handled. 
 * 
 * @param n The integer to convert. 
 * @return The string representing the integer.
 * NULL if the allocation fails.
*/
char	*ft_itoa(int n);

/**
 * @brief Applies the function 'f' to each character of the string 's' to create
 * a new string resulting from successive applications of 'f'. 
 * 
 * @param s The string on which iterate.
 * @param f The function to apply to each character. 
 * @return The string created from the successive applications of 'f'.
 * NULL if the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function 'f' to each character of the string passed as 
 * argument, and passing its index as first argument. Each character is 
 * passed by address to f to be modified if necessary. 
 * 
 * @param s The string on which to iterate.
 * @param f The function to apply to each character. 
 * @return None.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Outputs the character 'c' to the given file
 * descriptor. 
 * 
 * @param c The character to output.
 * @param fd The file descriptor on which to write. 
 * @return None.
*/
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string 's' to the given file
 * descriptor. 
 * 
 * @param s The string to output.
 * @param fd The file descriptor on which to write. 
 * @return None.
*/
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string 's' to the given file
 * descriptor, followed by a newline. 
 * 
 * @param s The string to output.
 * @param fd The file descriptor on which to write. 
 * @return None.
*/
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer 'n' to the given file
 * descriptor. 
 * 
 * @param n The integer to output.
 * @param fd The file descriptor on which to write. 
 * @return None.
*/
void	ft_putnbr_fd(int n, int fd);

#endif

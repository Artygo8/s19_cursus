#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

size_t		ft_putstr(char *s);
size_t		ft_strlen(char *s);
char		*ft_strcpy(char *s1, char *s2);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
char		*ft_strdup(const char *s1);
int			ft_atoi_base_c(char *str, char *base);

int			test_write(void);
int			test_read(void);

int			test_strlen(void);
int			test_strcpy(void);
int			test_strcmp(void);
int			test_strdup(void);

#endif

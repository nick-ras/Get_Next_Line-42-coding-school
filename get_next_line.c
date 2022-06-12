#include "get_next_line.h"

 char *put_s_str_leftover_in_buf(char *s_str)
{
	char * buf;
	int	i;

	i = 0;
	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	while(s_str[i] != '\0')
	{
		buf[i] = s_str[i];
		s_str[i] = '\0';
	}
	buf[i] = '\0';
	return(buf);
}

char *edit_buf_and_s_str(char *s_str, char *buf_t)
{
	char	*buf;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!ft_strchr(buf_t, '\n') && !ft_strchr(buf_t, '\n'))
		i++;
	buf = malloc((i + 1) * sizeof(char)); // could be double '\0'
	i = 0;
	while (!ft_strchr(buf_t, '\n') && !ft_strchr(buf_t, '\n'))
		buf[i] = buf_t[i];
	buf[i] = '\0';
	i++;
	while(buf_t[i] != '\0')
	{
		s_str[j] = buf_t[i];
		buf_t = '\0';
		j++;
		i++;
	}
	while (j < BUFFER_SIZE)
		s_str[j] = '\0';
	free(buf_t);
	return(buf);
}

char *read_lines(int fd, char *s_str, char *buf)
{
	int	read_count;
	char *temp;
	char *temp_total;

	temp = malloc(BUFFER_SIZE + 1 * sizeof(char));
	read_count = 0;
	while(!ft_strchr(buf, '\n') && !ft_strchr(buf, '\0'))
	{
		read_count = read(fd, temp, BUFFER_SIZE);
		if(read_count == -1) //doesnt check for read_count = 0
			return (NULL);
		buf = ft_strjoin(buf, temp); //Frees temp
	}
	buf = edit_buf_and_s_str(s_str, buf);
	return(buf);
}


char	*get_next_line(int fd)
{
	static char	s_str[BUFFER_SIZE];
	char    *buf;
	char    *buf_new;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= __INT_MAX__)
		return (NULL);

	if(ft_strchr(s_str, '\n'))
	{
		buf = put_s_str_leftover_in_buf(s_str);
		buf_new = edit_buf_and_s_str(s_str, buf);
		free(buf);
		return(buf_new);
	}
	else
	{
		buf = put_s_str_leftover_in_buf(s_str);
		buf_new = read_lines(fd, s_str, buf);
		free(buf);
		return(buf_new);
	}
}

#include "get_next_line.h"

char	*put_s_str_leftover_in_buf(char *s_str)
{
	char	*buf;
	int		i;

	i = 0;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	/* while (i < BUFFER_SIZE + 1)
	{
		//write(1, "5\n", 2);
		buf[i++] = '\0';
	} */
	while (s_str[i] != '\0')
	{
		//write(1, &s_str[i], 1);
		buf[i] = s_str[i];
		s_str[i] = '\0';
	}
	buf[i] = '\0';
	return (buf);
}

char	*edit_buf_and_s_str(char *s_str, char *buf)
{
	int		i;
	int		j;

	while (buf[i] != '\n' && buf[i] != '\0')
	{
		write(1, buf + i, 1);
		printf("%i", i);
		i++;
	}
	j = 0;
	while (buf[i] != '\0')
	{
		s_str[j++] = buf[i++];
		buf[i++] = '\0';
	}
	s_str[j] = '\0';
	//write(1, "hio\n", 4);
	return (buf);
}

char	*read_lines(int fd, char *s_str, char *buf)
{
	int	read_count;
	char	*temp;
	char	*char_ptr;
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	/* while (i < BUFFER_SIZE + 1)
		temp[i++] = '\0'; */
	while (!ft_strchr(buf, '\n'))
	{
		printf("start loop\n");
		read_count = read(fd, temp, BUFFER_SIZE);
		if (read_count == -1)
			return (NULL);
		else if (read_count == 0)
		{
			write(1, "count is 0\n", 4);
			printf("%s\n", buf);
			free(temp);
			return (buf);//return buf?
		}
		temp[read_count] = '\0';
		char_ptr = buf;
		buf = ft_strjoin(buf, temp);
		printf("buffer each loop: %s\n", buf);
		free(char_ptr);
		s_str[0] = '\0'; //DELETE
	}
	//write(1, "huy\n", 4);
	free(temp);
	//edit_buf_and_s_str(s_str, buf);  //if read count is lower than buf size
	return (buf); 
}

/* char *join_strings(char *buf, char *temp)
{
	if (!*)
} */

char	*get_next_line(int fd)
{
	static char	s_str[BUFFER_SIZE];
	char		*buf;

	if (!*s_str)
		s_str[0] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= __INT_MAX__)
		return (NULL);
	if (ft_strchr(s_str, '\n'))
	{
		buf = put_s_str_leftover_in_buf(s_str);
		printf("leftover values %s\n", buf);
		//buf_new = buf;
		//buf = edit_buf_and_s_str(s_str, buf);
		//free(buf_new);
		return (buf);
	}
	else
	{
		printf("else statement\n");
		buf = put_s_str_leftover_in_buf(s_str);
		printf("-%c-\n", buf[0]); //tests of string is '\0'
		printf("leftover values %s <-\n", buf);
		buf = read_lines(fd, s_str, buf);
		printf("return string %s <-\n", buf);
		write(1, "end\n", 4);
		printf("end GNL\n");
		//if buf = NULL then zero out s_str
		return (buf);
	}
	//write(1, "o\n", 2);
}

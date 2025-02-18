#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main()
{
    int fd;
    char *line;

    // Open the file for reading
    fd = open("input.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    // Call get_next_line and print each line
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Print the line (it includes the newline)
        free(line); // Don't forget to free the memory after using it
    }

    // Close the file descriptor
    close(fd);

    return 0;
}
# get_next_line
GNL is a utility function.
It is also a project of the 42school curriculum.

## Description
```C
int get_next_line(int file_descriptor, char **line_to_fill)
```
Each time get next time is called on a file descriptor, it allocates memory for the line it just read in the 'line_to_fill'.

For each line read ending with an endl ('\n'), the function returns 1.

When the EOF is reached, the function returns 0.

In case of invalid file_descriptor or memory allocation failure, the function returns -1.

## Example Usage
```C
int main()
{
    int     fd;
    char    *line;

    fd = 0;
    line = NULL;

    while (get_next_line(fd, line))
    {
        puts(line);
        free(line);
    }
    puts(line);
    free(line);

    return 0;
}

get_next_line(int file_descriptor, char **line_to_fill)
```

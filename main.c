#include "get_next_line.h"

int main()
{
    int fd;
    int fd2;
    fd = open("text", O_RDONLY);
    fd2 = open("text2", O_RDONLY);
    char *str;
    char *str2;

    while(str != NULL)
    {
        str = get_next_line(fd);
        str2 = get_next_line(fd2);
        printf("%s",str);
        printf("%s",str2);
        free(str);
    }
    return (0);
}

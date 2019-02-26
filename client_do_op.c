#include "client.h"

void     do_put(int sock, char *filename)
{
    int         fd;
    int         size;
    struct stat info;
    char        buf[100];

    ft_bzero(buf, 100);
    if ((fd = open(filename, O_RDONLY)) == -1)
    {
        perror("open");
        return ;
    }
    fstat(fd, &info);
    ft_strcpy(buf, "put ");
    ft_strcat(buf, filename);
    size = info.st_size;
    send(sock, buf, 100, 0);
    send(sock, &size, sizeof(int), 0);
    if (send_file(sock, size, fd))
        printf("File successfully sent.\n");
    else
        printf("File failed to send.\n");
    recv(sock, &size, sizeof(int), 0);
    if (size)
        printf("Server received the file.\n");
    else
        printf("Server failed to receive the file.\n");
}

void     do_get(int sock, char *filename)
{
    char   buf[100];
    int    size;
    char    *file;
    int     fd;

    ft_bzero(buf, 100);
    ft_strcpy(buf, "get ");
    ft_strcat(buf, filename);
    send(sock, buf, 100, 0);
    recv(sock, &size, sizeof(int), 0);
    file = malloc(size);
    recv(sock, file, size, 0);
    if ((fd = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0666)) == -1)
    {
        perror("open");
        return ;
    }
    write(fd, file, size);
    printf("File received.\n");
    close(fd);
    free(file);
}

void     do_cd(int sock, char *str)
{
    char   buf[100];
    int     status;

    ft_bzero(buf, 100);
    if (ft_strcmp(str, "cd") == 0)
        ft_strcpy(buf, "cd ");
    else if (ft_strncmp(str, "cd ", 3) == 0)
        ft_strcpy(buf, str);
    else
    {
        printf("No such file or directory\n");
        return ;
    }
    send(sock, buf, 100, 0);
    recv(sock, &status, sizeof(int), 0);
    if (status == 0)
        printf("No such file or directory\n");
}

void     do_ls(int sock)
{
    char    buf[100];
    int    size;
    char        *file;

    size = 0;
    ft_bzero(buf, 100);
    ft_strcpy(buf, "ls");
    send(sock, buf, 100, 0);
    read(sock, &size, sizeof(int));
    file = malloc(size);
    read(sock, file, size);
    write(1, file, size);
    free(file);
}

void    do_pwd(int sock)
{
    char   buf[100];
    int    size;

    ft_bzero(buf, 100);
    ft_strcpy(buf, "pwd");
    send(sock, buf, 100, 0);
    recv(sock, &size, sizeof(int), 0);
    recv(sock, buf, size, 0);
    write(1, buf, size);
    write(1, "\n", 1);
}

void    do_quit(int sock)
{
    close(sock);
}
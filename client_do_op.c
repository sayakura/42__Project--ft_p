#include "client.h"
#include "common.h"

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
    if (!S_ISREG(info.st_mode))
    {
        printf("%sThis is not a file.%s\n", RED, RESET);
        return ;
    }
    ft_strcpy(buf, "put ");
    ft_strcat(buf, filename);
    size = info.st_size;
    send(sock, buf, 100, 0);
    send(sock, &size, sizeof(int), 0);
    if (send_file(sock, size, fd))
        printf("%sFile successfully sent.%s\n", GREEN, RESET);
    else
        printf("%sFile failed to send.%s\n", RED, RESET);
    recv(sock, &size, sizeof(int), 0);
    if (size)
        printf("%sServer received the file.%s\n", GREEN, RESET);
    else
        printf("%sServer failed to receive the file%s\n", RED, RESET);
    close(fd);
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

    if (size < 0)
    {
        printf("%s[ERROR] get failed%s\n", RED, RESET);
        return ;
    }

    if ((fd = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0666)) == -1)
    {
        perror("open");
        close(fd);
        return ;
    }
    if (receive_file(sock, size, fd))
        printf("%sFile received.%s\n", GREEN, RESET);
    else
        printf("%s[ERROR] Failed to receive file.%s\n", RED, RESET);
    close(fd);
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
        printf("%sNo such file or directory%s\n", RED, RESET);
        return ;
    }
    send(sock, buf, 100, 0);
    recv(sock, &status, sizeof(int), 0);
    if (status == 0)
        printf("%sNo such file or directory%s\n", RED, RESET);
}

void     do_ls(int sock, char *arg)
{
    char    buf[100];
    int    size;
    char        *file;

    size = 0;
    ft_bzero(buf, 100);
    ft_strcpy(buf, "ls ");
    ft_strcat(buf, arg);
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
    ft_putstr(MAGENTA);
    write(1, buf, size);
    ft_putstr(RESET);
    write(1, "\n", 1);
}

void    do_quit(int sock)
{
    close(sock);
}
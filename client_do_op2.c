#include "client.h"

void     do_lls()
{
    if (fork() == 0)
    {
        execl("/bin/ls", "ls", NULL);
        exit(0);
    }
    wait(NULL);
}

void     do_lcd(char *str)
{
    if (chdir(str) == -1)
        perror("lcd");
}

void     do_lpwd()
{
    char   *path;
    int     len; 

    path = getcwd(NULL, 200);
    printf("%s\n", path);
    free(path);
}

void     do_mkdir(int sock, char *dirname)
{
    int         size;
    char        buf[100];

    ft_bzero(buf, 100);
    ft_strcpy(buf, "mkdir ");
    ft_strcat(buf, dirname);
    send(sock, buf, 100, 0);
    recv(sock, &size, sizeof(int), 0);
    if (!size)
        printf("mkdir: %s: File exists or invalid argument", dirname);
}

void     do_rmdir(int sock, char *dirname)
{
    int         size;
    char        buf[100];

    ft_bzero(buf, 100);
    ft_strcpy(buf, "rmdir ");
    ft_strcat(buf, dirname);
    send(sock, buf, 100, 0);
    recv(sock, &size, sizeof(int), 0);
    if (!size)
        printf("mkdir: %s: File exists or invalid argument", dirname);
}

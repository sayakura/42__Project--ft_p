#include "client.h"
#include "common.h"

extern char    *g_home_dir;

void     s_do_put(int sock, char *filename)
{
    int         fd;
    int         size;
    int         status;

    printf("PUT request received.\n");
    if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0666)) == -1)
    {
        perror("open");
        return ;
    }
    recv(sock, &size, sizeof(int), 0);
    status = receive_file(sock, size, fd);
    if (status)
        printf("Recived file: %s\n", filename);
    else
        printf("Failed to receive the file: %s\n", filename);
    send(sock, &status, sizeof(int), 0);
}

void     s_do_get(int sock, char *filename)
{
    char   *file;
    struct stat sb;
    int     fd;

    if ((fd = open(filename, O_RDONLY)) == -1)
    {
        perror("open");
        close(fd);
        sb.st_size = -1;
        send(sock, &(sb.st_size), sizeof(int), 0);
        return ;
    }
    fstat(fd, &sb);
    file = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    send(sock, &(sb.st_size), sizeof(int), 0);
    if (send_file(sock, sb.st_size, fd))
        printf("File sent successfully.\n");
    else
        printf("File sending failed..\n");
    munmap(file, sb.st_size);
    close(fd);
    printf("done get\n");
}

int     chdir_carefully(char *path)
{
    char    old_path[200];
    char    new_path[200];
    char    *modified_path;
    char    *temp;

    if (path[0] == '\0')
    {
        chdir(g_home_dir);
        return (1);
    }
    ft_bzero(old_path, 200);
    getcwd(old_path, 200);
    if ((chdir(path)) == -1)
        return (0);
    getcwd(new_path, 200);
    if (ft_strstr(new_path, g_home_dir) == NULL)
    {
        chdir(old_path);
        return (0);
    }
    else
        return (1);
}

void     s_do_cd(int sock, char *path)
{
    int status;

    status = chdir_carefully(path);
    send(sock, &status, sizeof(int), 0);
}

void     s_do_ls(int sock, char *arg)
{
    int         fd;
    char        *data;
    struct      stat sb;

    if ((fd = open(".tmp",  O_RDWR|O_CREAT|O_TRUNC, 0666)) == -1)
        ft_errorexit("open gg");
    if (fork() == 0)
    {
        dup2(1, 7777);
        dup2(fd, 1);
        dup2(1, 7778);
        dup2(fd, 2);
        execl("/bin/ls", "ls", ft_strlen(arg) ? arg : NULL,  NULL);
    }
    else
    {
        wait(NULL);
        dup2(7777, 1);
        dup2(7778, 2);
        close(fd);
        fd = open(".tmp", O_RDWR, 0666);
        if (fstat(fd, &sb) == -1)
            ft_errorexit("fstat gg");
        send(sock, &(sb.st_size), sizeof(int), 0);
        data = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
        send(sock, data, sb.st_size, 0);
        munmap(data, sb.st_size);
        close(fd);
        unlink("tmp");
    }
}

void    s_do_pwd(int sock)
{
    char   *path;
    int     len; 

    path = getcwd(NULL, 200);
    len = ft_strlen(path + ft_strlen(g_home_dir));
    if (len == 0)
    {
        len = 2;
        send(sock, &len, sizeof(int), 0);
        send(sock, "/\0", len, 0);
    }
    else
    {
        send(sock, &len, sizeof(int), 0);
        send(sock,  path +  ft_strlen(g_home_dir), len, 0);
    }
    free(path);
}

// void    s_do_quit(int sock)
// {
//     int status;

//     status = 1;
//     send(sock, &status, sizeof(int), 0);
//     close(sock);
// }

void    s_do_mkdir(int sock, char *dirname)
{
    int status;

    status = (mkdir(dirname, 0766) == -1) ? 0 : 1;
    send(sock, &status, sizeof(int), 0);
}
void    s_do_rmdir(int sock, char *dirname)
{
    int status;

    status = (rmdir(dirname) == -1) ? 0 : 1;
    send(sock, &status, sizeof(int), 0);
}

void    s_do_unlink(int sock, char *filename)
{
    int status;

    status = (unlink(filename) == -1) ? 0 : 1;
    send(sock, &status, sizeof(int), 0);
}
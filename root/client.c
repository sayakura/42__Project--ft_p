
#include "client.h"
#include "common.h"

char    get_char()
{
    char buff[1];

    read(0, buff, 1);
    return buff[0];
}

int     send_file(int server_sock, int file_size, int fd)
{
    char    *data;
    int     b_sent;
    char    buffer[BUFSIZ];

    b_sent = 0;
    data = mmap(NULL, file_size , PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    while ((b_sent != file_size) &&\
        (b_sent += send(server_sock, data, file_size, 0)) && (b_sent > 0))
        printf("Sending file....%d / %d\n", b_sent, file_size);
    close(fd);
    munmap(data, file_size);
    if (b_sent == file_size)
        printf("%sSuccessfully sent %d bytes.%s\n", GREEN, file_size, RESET);
    return (b_sent == file_size ? 1 : 0);
}

int     prompt(int sock)
{
    char    buf[1024];
    int     i;

    i = 0;
    ft_bzero(buf, sizeof(buf));
    write(1, "> ", 2);
    while ((buf[i++] = get_char()) != '\n')
        ;
    buf[i - 1] = '\0';
    if ((ft_strncmp(buf, "ls", 2)) == 0 &&
        (buf[2] == '\0' ||  buf[2] == ' '))
        do_ls(sock, buf + 3);
    else if ((ft_strncmp(buf, "cd", 2)) == 0) 
        do_cd(sock, buf);
    else if ((ft_strncmp(buf, "get ", 4)) == 0)
        do_get(sock, buf + 4);
    else if ((ft_strncmp(buf, "put ", 4)) == 0)
        do_put(sock, buf + 4);
    else if ((ft_strncmp(buf, "pwd", 3)) == 0)
        do_pwd(sock);
    else if ((ft_strncmp(buf, "mkdir ", 6)) == 0)
        do_mkdir(sock, buf + 6);
    else if ((ft_strncmp(buf, "rmdir ", 6)) == 0)
        do_rmdir(sock, buf + 6);
    else if ((ft_strncmp(buf, "unlink ", 7)) == 0)
        do_unlink(sock, buf + 7);
    else if ((ft_strncmp(buf, "lls", 3)) == 0)
        do_lls();
    else if ((ft_strncmp(buf, "lcd ", 4)) == 0)
        do_lcd(buf + 4);
    else if ((ft_strncmp(buf, "lpwd", 3)) == 0)
        do_lpwd();
    else if ((ft_strncmp(buf, "lmkdir ", 7)) == 0)
        mkdir(buf + 7, 0766);
    else if ((ft_strncmp(buf, "quit", 4)) == 0)
    {
        close(sock);
        return (0);
    }
    else
        printf("command not found: %s\n", buf);
    return (1);
}

void    socket_setup(char *host, int port)
{

    int                 sock;
    struct sockaddr_in  servaddr;

    if (ft_strcmp(host, "localhost") == 0)
        host = "127.0.0.1";
    printf("\x1b[33mConnecting...\x1b[0m %s %d\n", host, port);
    sock = socket(AF_INET, SOCK_STREAM, 0); 
    ft_bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr(host); 
    servaddr.sin_port = htons(port); 
    if (connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) 
        ft_errorexit("\x1b[31mConnection Failed. \n\x1b[0m");
    else
        while (1)
            if (!prompt(sock))
                break ;
    close(sock);
}

int main(int ac, char **av)
{
    if (ac != 3)
        ft_errorexit("Need to specify the ip and the port.");
    printf("================================================\n");
    printf("|                                              |\n");
    printf("|                  FTP 1.0.0                   |\n");
    printf("|                Author: \x1b[35mQpeng\x1b[0m                 |\n");
    printf("|                                              |\n");
    printf("|               Client Version                 |\n");
    printf("|                                              |\n");
    printf("================================================\n");
    socket_setup(av[1], ft_atoi(av[2]));
    return (0);
}
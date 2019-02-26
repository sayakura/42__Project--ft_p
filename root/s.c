#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/*for getting file size using stat()*/
#include<sys/stat.h>

/*for O_RDONLY*/
#include<fcntl.h>
#include "s.h"
#define PORT 7777
#define max_clients 20

char    *g_home_dir;

int     socket_setup()
{
    int                 main_sock;
    struct sockaddr_in  address;
    int                 opt;

    opt = 1;
    if((main_sock = socket(AF_INET , SOCK_STREAM , 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if( setsockopt(main_sock, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,\
    sizeof(opt)) < 0 )
    {   
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(main_sock, (struct sockaddr *)&address, sizeof(address))<0)
    {   
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    return (main_sock);
}


void     socket_listen(int sock)
{
    if (listen(sock, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("waiting for connection...\n");
}

int     handle_op(int sock)
{
    char buf[100];

    if (recv(sock, buf, 100, 0) == 0)
        return (0);
    if ((ft_strncmp(buf, "ls", 2)) == 0)
        s_do_ls(sock);
    else if ((ft_strncmp(buf, "cd ", 3)) == 0) 
        s_do_cd(sock, buf + 3);
    else if ((ft_strncmp(buf, "get ", 4)) == 0)
        s_do_get(sock, buf + 4);
    else if ((ft_strncmp(buf, "put ", 4)) == 0)
        s_do_put(sock, buf + 4);
    else if ((ft_strncmp(buf, "pwd", 3)) == 0)
        s_do_pwd(sock);
    else if ((ft_strncmp(buf, "quit ", 5)) == 0)
        s_do_quit(sock);
    else
        return (0);
    return (1);
}

void    handle_request(int sock, int *client_socks, fd_set *fd_list)
{
    int     i;
    int     b_read;
    char    buf[100];

    i = -1;
    while (++i < max_clients)
        if (FD_ISSET(client_socks[i], fd_list))
            if (!handle_op(client_socks[i]))
            {
                printf("Client disconnected.");
                close(sock);
                client_socks[i] = 0;
            }

}

void    connection_handler(int sock, fd_set *fd_list, int *client_socks)
{
    int     new_sock;
    struct sockaddr_in address;   
    int     addrlen;
    int     i;

    if (FD_ISSET(sock, fd_list))
    {
        if ((new_sock = accept(sock,  
            (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
        {   
                perror("accept");   
                exit(EXIT_FAILURE);   
        }   
        printf("New connection , socket fd is %d , ip is : %s , port : %d\n" , new_sock ,\
            inet_ntoa(address.sin_addr) , ntohs(address.sin_port));   
        while (++i < max_clients)
            if (client_socks[i] == 0)
            {
                client_socks[i] = new_sock;
                printf("Adding to list of sockets as %d\n" , i);   
                break ;
            }
    }
}

void    socket_select_setup(int sock)
{
    fd_set fd_list;
    int     max;
    int     i;
    int     client_socks[max_clients];
    int     actived;

    ft_bzero(client_socks, sizeof(client_socks));
    while (1)
    {
        i = -1;
        FD_ZERO(&fd_list);
        FD_SET(sock, &fd_list);
        max = sock;
        while (++i < max_clients)
        {
            if (client_socks[i] > 0)
                FD_SET(client_socks[i], &fd_list);
            if (client_socks[i] > max)
                max = client_socks[i];
        }
        actived = select(max + 1, &fd_list, NULL, NULL, NULL);
        if ((actived < 0))   
            printf("select error\n");
        connection_handler(sock, &fd_list, client_socks);
        handle_request(actived, client_socks, &fd_list);
    }
}

void    ftp_setup()
{
    mkdir("root", 0777);
    chdir("root");
}
int     main(void)
{
    int sock;

    ftp_setup();
    g_home_dir = getcwd(NULL, 200);
    sock = socket_setup();
    socket_listen(sock);
    printf("Listening on port %d \n", PORT);
    socket_select_setup(sock);
    return (0);
}
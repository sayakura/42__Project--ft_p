#include <stdio.h> 
#include <sys/socket.h> 
#include <sys/ioctl.h>
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include "libft/libft.h"
#include <arpa/inet.h>
#include <fcntl.h>
#include<sys/stat.h>
#include <sys/mman.h>
#include <net/if.h>



void     s_do_put(int sock, char *filename);
void     s_do_get(int sock, char *filename);
void     s_do_cd(int sock, char *path);
void     s_do_ls(int sock);
void    s_do_pwd(int sock);
void    s_do_mkdir(int sock, char *dirname);
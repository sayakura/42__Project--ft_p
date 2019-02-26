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

void        do_put(int sock, char *str);
void        do_get(int sock, char *str);
void        do_cd(int sock, char *str);
void        do_ls(int sock, char *arg);
void        do_lls();
void        do_lcd(char *str);
void        do_lpwd();
void        do_pwd(int sock);
void        do_quit(int sock);
void        do_mkdir(int sock, char *dirname);
void        do_rmdir(int sock, char *dirname);
void        do_unlink(int sock, char *dirname);
int         send_file(int sock, int size, int fd);

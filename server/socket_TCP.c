#include "socket_TCP.h"

#include <stdio.h>
#include <sys/socket.h>

int create_socket_TCP(int *fd){
    // номер файлового дескриптора связанного с созданным сокетом
    *fd = socket(AF_INET, SOCK_STREAM, 0);
    if ( *fd == -1 ){
        fprintf(stderr, "Socket not create");
        return 1;
    }

    printf("socket fd :  %d \n", *fd);
    return 0;
}
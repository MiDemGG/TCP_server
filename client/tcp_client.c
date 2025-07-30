#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#include "socket_TCP.h"

int main(){
    int fd;

    create_socket_TCP(&fd);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(10101);
    addr.sin_addr.s_addr = inet_addr("192.168.2.151");

    // Устанавливается соединение
    if ( connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1 ) {
        printf("Не сработал запрос на соединение");
        exit(0);
    }
    
    return 0;
}
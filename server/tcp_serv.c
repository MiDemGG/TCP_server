#include <stdio.h>
#include <netinet/in.h>

int main(){
    int fd, res, opt;
    struct sockaddr_in add_port;

    // номер файлового дескриптора связанного с созданным сокетом
    // -1 при ошибке
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if ( fd == -1 ){
        printf("Не создался сокет");
        return 0;
    }
    printf("%d \n", fd);
/*
    // addressing family
    add_port.sin_family = AF_INET;
    // sets the port number in the "network byte order"
    add_port.sin_port = 10101;
    // ip address
    add_port.sin_addr = INADDR_ANY;
    res = bind(fd, (struct sockaddr*)&add_port, sizeof(add_port));

    return 0;
*/
}
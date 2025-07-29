#include <stdio.h>
#include <netinet/in.h>

int main(){
    int fd, res, opt;
    struct sockaddr_in addr;

    // номер файлового дескриптора связанного с созданным сокетом
    // -1 при ошибке
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if ( fd == -1 ){
        printf("Не создался сокет");
        return 0;
    }
    printf("%d \n", fd);

    // addressing family
    addr.sin_family = AF_INET;
    // sets the port number in the "network byte order"
    addr.sin_port = htons(10101);
    // ip address
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    //Снабдит сокет адресом ( идентификатор сокет )
    bind(fd, (struct sockaddr*)&addr, sizeof(addr));

    printf("%i %i %i \n", addr.sin_family, addr.sin_port, addr.sin_addr.s_addr);
    return 0;
}
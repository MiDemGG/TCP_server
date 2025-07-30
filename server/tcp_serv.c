#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(){
    // файловый дескриптор сокета, 
    int fd, err_bind;
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
    //                           принимает соединения на этот порт на любом из
    // ip address                имеющихся в системе ip-адресов
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    //Снабдит сокет адресом ( идентификатор сокет )
    err_bind = bind(fd, (struct sockaddr*)&addr, sizeof(addr));
    if ( err_bind == -1) {
        printf("Не сработал bind \n");
        return 0;
    }
    printf("%i %i %i \n", addr.sin_family, addr.sin_port, addr.sin_addr.s_addr);

    // размер очереди непринятых запросов на соединение
    int qlen = 10;
    // перевод сокета в слушающий режим
    listen(fd, qlen);


    int fd_socket_accept;
    struct sockaddr new_addr;
    socklen_t addrlen = sizeof(new_addr);
    printf("Ждем соединения с клиентом... \n");
    // возвращает файловый дескриптор нового сокета, созданного для обслуживания
    // вновь установленного соединения
    fd_socket_accept = accept(fd, &new_addr, &addrlen);
    if ( fd_socket_accept == -1){
        printf("Ошибка в accept \n");
        return 0;
    }
    
    return 0;
}
#include "tcp_serv.h"

static void bind_socket_TCP(int *fd){
    int err_bind;

    struct sockaddr_in addr;
    // addressing family
    addr.sin_family = AF_INET;
    // sets the port number in the "network byte order"
    addr.sin_port = htons(10101);
    //                           принимает соединения на этот порт на любом из
    // ip address                имеющихся в системе ip-адресов
    addr.sin_addr.s_addr = INADDR_ANY;

    //Снабдит сокет адресом ( идентификатор сокет )
    err_bind = bind(*fd, (struct sockaddr*)&addr, sizeof(addr));
    if ( err_bind == -1) {
        printf("Не сработал bind \n");
        exit(0);
    }

    // printf("%i %i %i \n", addr.sin_family, addr.sin_port, addr.sin_addr.s_addr);
}

int main(){
    // файловый дескриптор сокета
    int fd;

    // создаем сокет
    create_socket_TCP(&fd);
    // снабжаем адресом
    bind_socket_TCP(&fd);

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
    printf("Файловый дескриптор потока ввода-вывода с клиентом %i \n", fd_socket_accept);

    char text[79];
    if ( read(fd_socket_accept, text, 79) == -1 ) {
        printf("Ошибка read \n");
    }
    printf("%s \n", text);
    return 0;
}
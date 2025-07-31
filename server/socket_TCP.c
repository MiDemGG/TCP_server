#include "socket_TCP.h"

void create_socket_TCP(int *fd){
    // номер файлового дескриптора связанного с созданным сокетом
    *fd = socket(AF_INET, SOCK_STREAM, 0);
    if ( *fd == -1 ){
        printf("Не создался сокет");
        exit(0);
    }

    printf("Файловый дескриптор сокета имеет номер %d \n", *fd);
}
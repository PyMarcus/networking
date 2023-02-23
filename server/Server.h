//
// Created by Marcus on 23/02/2023.
//

#ifndef NETWORKING_SERVER_H
#define NETWORKING_SERVER_H


#include <iostream>
#include <winsock.h>


const short int p = 9696;


/*
 * Create a socket, file descriptor,
 * TCP, that server the single connections
 * */
class Server {
private:
    int _socket;
    u_long ip_address = INADDR_ANY;
    short int port;

public:
    Server(u_long ip_address = inet_addr("127.0.0.1"), short int port = p){
        this->ip_address = ip_address;
        this->port = port;
    }


    void create_socket();
    void set_socket_information();
    inline int bind_socket_to_local_port(int _sockett);
    void listen_connections(int sockett, short int size);
};


#endif //NETWORKING_SERVER_H

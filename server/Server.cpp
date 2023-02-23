//
// Created by Marcus on 23/02/2023.
//

#include "Server.h"
#include <iostream>
#include <winsock.h>


struct sockaddr_in srv;


void Server::create_socket()
{
    // windows specific [WSA variable]
    WSADATA ws;

    if(WSAStartup(MAKEWORD(2, 2), &ws) < 0)
    {
        std::cerr << "[FAILED] WSA failed to initialize!" << std::endl;
    }
    else
    {
        std::cout << "WSA was initialized" << std::endl;
    }

    //create a new socket
    int _socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(_socket < 0)
    {
        std::cerr << "[FAILED] The socket is not opened!" << std::endl;
    }
    else
    {
        std::cout << "Successfully to open socket!" << std::endl;
    }

    // set socket
    set_socket_information();

    // bind
    int ret = bind_socket_to_local_port(_socket);
    if(ret < 0)
    {
        std::cout << "[FAILED] to bind into local port!" << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        std::cout << "Successfully bind local port" << std::endl;
    }

    // listen
    listen_connections(_socket, 5);
}


void Server::set_socket_information()
{
    srv.sin_family = AF_INET;
    srv.sin_addr.s_addr = this->ip_address;
    srv.sin_port = htons(this->port);

    // set first num of bytes
    memset(&(srv.sin_zero), 0, 8);
}


inline int Server::bind_socket_to_local_port(int _sockett) {
    return bind(_sockett, (sockaddr*)&srv, sizeof(sockaddr));
}


/*
 * @param: size (MAX connections at pool of queue - backlog)
 * */
void Server::listen_connections(int sockett, short size)
{
    int listening = listen(sockett, size);
    if(listening < 0)
    {
        std::cout << "[FAILED] to listen at local port!" << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        std::cout << "Successfully listening at local port..." << std::endl;
    }
}



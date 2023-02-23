#include "server/Server.h"


int main()
{
    std::ios_base::sync_with_stdio(false);

    Server server;
    server.create_socket();

    return EXIT_SUCCESS;
}
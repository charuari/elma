#ifndef _TCPSERVER_H
#define _TCPSERVER_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string>
#include <json/json.h>

using nlohmann::json;

class TcpServer {

public:
   TcpServer(int _port_number);
   //virtual int listen();
   //virtual int send(std::string message);
   int listen();
   //int send(std::string message);
   int send(json message);
   //virtual std::string receive(int size);
   //std::string receive(int size);
   json receive(int size);
   virtual ~TcpServer();

private:
   int     _port_number;
   int     _socketfd, _client_socketfd;
   struct  sockaddr_in   _server_address;
   struct  sockaddr_in   _client_address;
   bool	   _client_connected;
};

#endif /* TCPSERVER_H */

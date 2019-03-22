#ifndef _TCPSERVER_H
#define _TCPSERVER_H
#include "elma.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string>
#include <json/json.h>

using nlohmann::json;
using namespace elma;

//! The TCP/IP Server class.

//! Instance of this class will help to connect to a client to receive and send json messages.

class TcpServer {

public:

   //! Constructor
   //! \param port number The port number of the server
   TcpServer(int _port_number);
   
   //! Method to create socket, bind, listen and accept connection from incoming client.
   int listen();
   
   //! Send usually an acknowledgement back to client.
   //! \param Json message to be sent
   //! return 0 on successful send.
   int send(json message);
   
   //! Receive message from client.
   //! \param Size of the buffer set to read the incoming message
   //! \return Received json message.
   json receive(int size);

   //! Destructor
   //! Close the server socket and accepted client socket.
   virtual ~TcpServer();

private:
   int     _port_number;
   int     _socketfd, _client_socketfd;
   struct  sockaddr_in   _server_address;
   struct  sockaddr_in   _client_address;
   bool	   _client_connected;
};

#endif 

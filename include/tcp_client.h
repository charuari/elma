#ifndef _TCPCLIENT_H
#define _TCPCLIENT_H
#include "elma.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string>
#include <json/json.h>

using nlohmann::json;
using namespace elma;

//! The TCP/IP Client class.

//! Instance of this class will help to connect to server to send and receive json messages.
class TcpClient {

public:

	//! Constructor
    //! \param name The IP address (localhost in our case) and port number of the server to which client wants to connect to.
	TcpClient(std::string _server_name, int _port_number);
	
	//! Method to create socket, get the hostname and connect to server.
	int connect_to_server();

	//! Method to close socket when done with communication.
	int disconnect_from_server();
	
	//! Send message to server.
    //! \param name json message
    //! return 0 on successful send.
	int send(json message);

	//! Receive message from server usually an acknwledgement or processed data.
    //! \param name size of the buffer set to read the incoming message.
    //! \return received json message.
	json receive(int size);

	//! Check if client is connected.
	bool is_client_connected() { return this->_is_connected; }

	//! Destructor
	//! Calls disconnect_from_server.
	virtual ~TcpClient();


private:
    int 	    _socketfd;
    struct 	    sockaddr_in   _server_address;
    struct 	    hostent       *server;
    std::string _server_name;
    int         _port_number;
    bool        _is_connected;
};

#endif 

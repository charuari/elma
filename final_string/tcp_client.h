#ifndef _TCPCLIENT_H
#define _TCPCLIENT_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string>
//#include <json/json.h>

//using nlohmann::json;


class TcpClient {

public:
	TcpClient(std::string _server_name, int _port_number);
	//virtual int connect_to_server();
	//virtual int disconnect_from_server();
	//virtual int send(std::string message);
	//virtual std::string receive(int size);
	int connect_to_server();
	int disconnect_from_server();
	int send(std::string message);
	//int send(json message);
	std::string receive(int size);
	//json receive(int size);
	bool is_client_connected() { return this->_is_connected; }
	virtual ~TcpClient();


private:
    int 	    _socketfd;
    struct 	    sockaddr_in   _server_address;
    struct 	    hostent       *server;
    std::string _server_name;
    int         _port_number;
    bool        _is_connected;
};

#endif /* TCPCLIENT_H*/

#include "tcp_client.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;
using namespace elma;

//! Initializes client socket and connection status.
//! \param //! \param name The IP address (localhost in our case) and port number of the server to which client wants to connect to.
TcpClient::TcpClient(std::string _server_name, int _port_number) {
	this->_socketfd = -1;
	this->server = NULL;
	this->_server_name = _server_name;
	this->_port_number = _port_number;
	this->_is_connected = false;
}

//! Create socket, get the hostname and connect to server.
//! Return 0 on success or else throw error describing in which stage of connection establishment.
int TcpClient::connect_to_server(){
    _socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (_socketfd < 0){
    	perror("Socket Client: error opening socket.\n");
    	return 1;
    }
    server = gethostbyname(_server_name.data());
    if (server == NULL) {
        perror("Socket Client: error - no such host.\n");
        return 1;
    }
    bzero((char *) &_server_address, sizeof(_server_address));
    _server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr,(char *)&_server_address.sin_addr.s_addr, server->h_length);
    _server_address.sin_port = htons(_port_number);
    
    if (connect(_socketfd, (struct sockaddr *) &_server_address, sizeof(_server_address)) < 0){
    	perror("Socket Client: error connecting to the server.\n");
    	return 1;
    }
    this->_is_connected = true;
    return 0;
}

//! Send message to server. Json messages are converted into bytes to write into buffer.
//! \param name json message
//! return 0 on successful send or error throw.
int TcpClient::send(json message){
    string output = message.dump();
	const char *write_buffer = output.data();
	int length =output.length();
    int n = write(this->_socketfd, write_buffer, length);
    if (n < 0){
       perror("Socket Client: error writing to socket");
       return 1;
    }
    return 0;
}

//! Receive message from server usually an acknwledgement or processed data.
//! Byte messages are converted to strings and then to json.
//! \param name size of the buffer set to read the incoming message.
//! \return received json message.
json TcpClient::receive(int size=1024){
    char read_buffer[size];
    int n = read(this->_socketfd, read_buffer, size);//sizeof(read_buffer));
    if (n < 0){
       perror("Socket Client: error reading from socket");
    }
    std::string input(read_buffer);
    json j = input;
    return j;
}

//! Close socket when done with communication.
int TcpClient::disconnect_from_server(){
	this->_is_connected = false;
	close(this->_socketfd);
	return 0;
}

//! Calls disconnect_from_server.
TcpClient::~TcpClient() {
	if (this->_is_connected == true){
		disconnect_from_server();
	}
}


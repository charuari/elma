#include "tcp_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <sys/ioctl.h>
#include <json/json.h>

using namespace std;
using namespace elma;

//! Initializes server socket and client connection status.
//! \param The port number of the server where it keeps listening.
TcpServer::TcpServer(int portNumber) {
	this->_socketfd = -1;
	this->_client_socketfd = -1;
	this->_port_number = portNumber;
	this->_client_connected = false;
}

//! Create socket, bind, listen and accept connection from incoming client.
//! \return 0 on success, else throws error describing in which part of connection establishment.
int TcpServer::listen(){
    this->_socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->_socketfd < 0){
    	perror("Socket Server: error opening socket.\n");
    	return 1;
    }
    bzero((char *) &_server_address, sizeof(_server_address));
    _server_address.sin_family = AF_INET;
    _server_address.sin_addr.s_addr = INADDR_ANY;
    _server_address.sin_port = htons(this->_port_number);
    if (bind(_socketfd, (struct sockaddr *) &_server_address, sizeof(_server_address)) < 0){
    	perror("Socket Server: error on binding the socket.\n");
    	return 1;
    }
    ::listen(this->_socketfd, 5);
    socklen_t client_length = sizeof(this->_client_address);
    this->_client_socketfd = accept(this->_socketfd,
    		(struct sockaddr *) &this->_client_address,
    		&client_length);
    if (this->_client_socketfd < 0){
    	perror("Socket Server: Failed to bind the client socket properly.\n");
    	return 1;
    }
    return 0;
}

//! Send usually an acknowledgement back to client. Json messages are converted into bytes to write into buffer.
//! \param name json message
//! return 0 on successful send or error throw.
int TcpServer::send(json message){
    string output = message.dump();
	const char *write_buffer = output.data();
	int length = output.length();
    int n = write(this->_client_socketfd, write_buffer, length+1);
    if (n < 0){
       perror("Socket Server: error writing to server socket.");
       return 1;
    }
    return 0;
}

//! Receive message from client. Byte messages are converted to strings and then to json.
//! \param name Size of the buffer set to read the incoming message.
//! \return received json message.
json TcpServer::receive(int size=1024){
    char read_buffer[size];
    int n = read(this->_client_socketfd, read_buffer,size);
    if (n < 0){
       perror("Socket Server: error reading from server socket.");
    }
    std::string input(read_buffer);
    json j = input;
    return j;
}

//! Destructor
//! Close the server socket and accepted client socket.
TcpServer::~TcpServer() {
	close(this->_socketfd);
	close(this->_client_socketfd);
}

#include <iostream>
#include "tcp_server.h"
using namespace std;


int main(int argc, char *argv[]){
   cout << "Starting Server Example" << endl;
   TcpServer server(54321);
   cout << "Listening for a connection..." << endl;
   server.listen();
   string rec = server.receive(1024);
   //json rec = server.receive(1024);
   //cout << "Received from the client [" << rec<< "]" << endl;
   string message("The Server says thanks!");
   //cout << "Sending back [" << message << "]" << endl;
   //auto j = json::parse(message);
   server.send(message);
   //cout << "End of Server Example" << endl;
   return 0;
}

#include <iostream>
#include "tcp_server.h"
using namespace std;


int main(int argc, char *argv[]){
   cout << "Starting Server Example" << endl;
   TcpServer server(54321);
   cout << "Listening for a connection..." << endl;
   server.listen();
   json rec = server.receive(1024);
   //cout << "Received from the client [" << rec.dump()<< "]" << endl;
   //auto message= R"({"Server":"Thanks!"})"_json;
   auto message = R"(
  {
    "happy": true,
    "pi": 3.141
  }
)"_json;
   //cout << "Sending back [" << message.dump() << "]" << endl;
   server.send(message);
   cout << "End of Server Example" << endl;
   return 0;
}

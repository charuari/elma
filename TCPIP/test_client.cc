#include <iostream>
//#include "gtest/gtest.h"
#include "tcp_client.h"
//#include "tcp_server.h"
using namespace std;

/*TcpServer server(54321);
server.listen();
string rec = server.receive(1024);

TEST(Client,Basic){
   TcpClient client("localhost", 54321);
   client.connect_to_server();
   string message("Hello from the Client");
   cout << "Sending [" << message << "]" << endl;
   client.send(message);
   ASSERT_STREQ(message,rec);

}*/


int main(int argc, char *argv[]){
   if(argc!=2){
      cout << "Incorrect usage: " << endl;
      cout << "   client server_name" << endl;
      return 2;
   }
   cout << "Starting Client Example" << endl;
   TcpClient client(argv[1], 54321);
   client.connect_to_server();
   string message("Hello from the Client");
   cout << "Sending [" << message << "]" << endl;
   //auto j = json::parse(message);
   client.send(message);
   //string rec = client.receive(1024);
   string rec = client.receive(1024);
   cout << "Received [" << rec << "]" << endl;
   cout << "End of Client Example" << endl;
   return 0;
}

/*GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/

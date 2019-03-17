#include <iostream>
#include <string.h>
#include "gtest/gtest.h"
#include "tcp_client.h"



namespace{
using namespace std;
TEST(Client,Basic){
   TcpClient client("localhost", 54321);
   client.connect_to_server();
   string message("Hello from the Client");
   //cout << "Sending [" << message << "]" << endl;
   client.send(message);
   string rec = client.receive(1024);
   string out = "The server says thanks!";
   //string rec = "The server says thanks!";
   EXPECT_EQ(out.length(),rec.length());
}
}



/*int main(int argc, char *argv[]){
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
}*/

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
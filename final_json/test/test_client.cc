#include <iostream>
#include <string.h>
#include "gtest/gtest.h"
#include "tcp_client.h"

using namespace std;

TEST(Client,Basic){
   TcpClient client("localhost", 54321);
   client.connect_to_server();
   auto message = R"({"Client":"Hello"})"_json;
   //cout << "Sending [" << message.dump() << "]" << endl;
   client.send(message);
   json rec = client.receive(1024);
   auto out = R"(
  {
    "happy": true,
    "pi": 3.141
  }
)"_json;
   //string rec = "The server says thanks!";
   EXPECT_EQ(out.size(),rec.size());
   //ASSERT_STREQ(out.dump(),rec.dump());
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
   auto message = R"({"Client":"Hello"})"_json;
   cout << "Sending [" << message.dump() << "]" << endl;
   client.send(message);
   json rec = client.receive(1024);
   cout << "Received [" << rec.dump() << "]" << endl;
   cout << "End of Client Example" << endl;
   return 0;
}*/

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <iostream>
#include "elma.h"
#include "tcp_server.h"
#include "server_process.h"
#include <json/json.h>
#include <chrono>
#include "gtest/gtest.h"

using nlohmann::json;

using namespace std;
using namespace elma;
#define MS(__ms__) high_resolution_clock::duration(milliseconds(__ms__))

//! The size of data sent form client and the size of data received by server is expected equal;
//! Also the number of acknowledgements to client is tested.
json temp = "{\"temperature\":77.27870658285856,\"x\":-4,\"y\":3})";

TEST(SERVER, BASIC){
        Manager m;
        ProServer s ("server");
        m.schedule(s, MS(10))
        .init()
        .start();
        m.emit(Event("start_server"));
        m.run(MS(100)).stop();
        EXPECT_EQ(s.value().size(),temp.size());
        EXPECT_EQ(s.ack(),9);
        
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
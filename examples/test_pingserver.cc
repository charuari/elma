#include <iostream>
#include <time.h>
#include "elma.h"
#include "tcp_server.h"
#include "server_ping.h"
#include <json/json.h>
#include <chrono>


using nlohmann::json;

using namespace std;
using namespace elma;
#define MS(__ms__) high_resolution_clock::duration(milliseconds(__ms__))

int main(){
        Manager m;
        PingServer s ("server");
        m.schedule(s, MS(1000))
        .init()
        .start();
        m.emit(Event("start_server"));
        m.run(MS(4000)).stop();
              
}


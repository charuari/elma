#include <iostream>
#include <chrono>
#include "elma.h"
#include "client_ping.h"
#include "tcp_client.h"

using namespace std;
using namespace elma;

#define MS(__ms__) high_resolution_clock::duration(milliseconds(__ms__))

int main(){
    Manager m;
    PingClient c ("client");
    m.schedule(c, MS(1000))
     .init()
     .start();
    m.emit(Event("start_client"));
    m.run(MS(4000)).stop();
            
}



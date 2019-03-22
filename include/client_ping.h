#ifndef _CLIENT_PING_H
#define _CLIENT_PING_H
#include "elma.h"
#include "tcp_client.h"
#include <json/json.h>

using nlohmann::json;
using namespace elma;
using namespace std;

//! Creating an instance of TCP/IP client with IP and port number of server.
TcpClient ping_cli("localhost", 54330);

//! An inherited elma process class which serves as a TCP/IP client.

//! Pings server and receive current time for confirming the connection.
class PingClient : public elma::Process {
    
    public: 
    
    //! The constructor wraps the base constructor.
    //! \param name The name of the process
    PingClient(string name) : Process(name) {}
    
    //! Virtual method of abstract elma process class.
    //! Watch for events and  corresponding handlers are described.
    //! Manager emits events to start and stop client.
    void init() {
        watch("start_client",[this](Event& e ) {
            ping_cli.connect_to_server();
        });
        watch("stop_client",[this](Event& e ) {
            ping_cli.~TcpClient();
        });
        watch("client_send",[this](Event& e ) {
            ping_cli.send(data);
        });
    }

    //! Nothing to do to start. 
    void start() {}

    //! TCP/IP messages are send and received in update method.
    //! Data is send to server in the emit event.
    //! Mind the print statement included to check current time received from server on the client terminal.
    void update() {
        data["Client ping Server"] = "hello";
        emit(Event("client_send",data));
        json rec = ping_cli.receive(1024);
        cout<<"Client received"<<rec.get<std::string>()<<endl;
    }

    //! Nothing to do to stop
    void stop() {}
                  
    private:
        std::string hello;
        json data;
               
    };
#endif
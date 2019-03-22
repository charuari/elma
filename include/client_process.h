#ifndef _CLIENT_PROCESS_H
#define _CLIENT_PROCESS_H
#include "elma.h"
#include "tcp_client.h"
#include "data_generator.h"
#include <json/json.h>

using nlohmann::json;
using namespace elma;
using namespace std;

//! Creating an instance of TCP/IP client with IP and port number of server.
TcpClient cli("localhost", 54321);

//! An inherited elma process class which serves as a TCP/IP client.

//! Send data to server and receive acknowledgement back.
class ProClient : public elma::Process {
    
    public: 
    
    //! The constructor wraps the base constructor.
    //! \param name The name of the process
    ProClient(string name) : Process(name) {}

    //! Virtual method of abstract elma process class.
    //! Watch for events and corresponding handlers are described.
    //! Manager emits events to start and stop client.
    void init() {
        watch("start_client",[this](Event& e ) {
            cli.connect_to_server();
        });
        watch("stop_client",[this](Event& e ) {
            cli.~TcpClient();
        });
        watch("client_send",[this](Event& e ) {
            cli.send(data);
        });
    }

    //! Nothing to do to start. 
    void start() {}

    //! TCP/IP messages are send and received in update method.
    //! Data is send to server in the emit event.
    //! Mind the print statement included to check acknowldegement received from server on the client terminal.
    void update() {
        data = ds.gen();
        emit(Event("client_send",data));
        json rec = cli.receive(1024);
            cout<<"Client received"<<rec.get<std::string>()<<endl;
    }

    //! Nothing to do to stop 
    void stop() {
    }

    private:
        //! Creating instance of random temperature and location co-ordinates generator.
        DataGenerator ds;
        json data;
            
    };

#endif
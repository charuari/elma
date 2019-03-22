#ifndef _SERVER_PING_H
#define _SERVER_PING_H
#include "elma.h"
#include "tcp_server.h"
#include <sys/ioctl.h>
#include <time.h>
#include <json/json.h>
#include <string>
#include <iostream>

using nlohmann::json;
using namespace elma;
using namespace std;

//! Creating an instance of TCP/IP server with port number.
TcpServer ping_svr(54330);
//! An inherited elma process class which serves as a TCP/IP server.

//! Receives data from client and sends current time to client confirming the established connection.

class PingServer : public elma::Process {
   public: 

   //! The constructor wraps the base constructor.
   //! \param name The name of the process
   PingServer(string name) : Process(name) {}
   
   //! Virtual method of abstract elma process class.
   //! Watch for events and corresponding handlers are described.
   //! Manager emits events to start and stop server.
   void init() {
      watch("start_server",[this](Event& e ) {
         ping_svr.listen();
      });
      watch("stop_server",[this](Event& e ) {
         ping_svr.~TcpServer();
      });
      watch("server_send",[this](Event& e ) {
         ping_svr.send(message);
      });
              
   }     

   //! Nothing to do to start.  
   void start() {}

   //! TCP/IP messages are send and received in update method.
   //! Mind the print statement included to check ping from client on the server terminal.
   //! Current time is sent back to client in the emit event.
   void update() {
      data = ping_svr.receive(1024);
      cout<<"Server Received "<<data.get<std::string>()<<endl;
      time(&clock);
      message["Acknowledgement to Client"] = ctime(&clock);
      emit(Event("server_send",message));
   }   

   //! Nothing to do to stop      
   void stop() {}
           
   private:
      time_t clock;
      json data;
      json message;
   };
   #endif
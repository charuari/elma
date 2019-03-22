#ifndef _SERVER_PROCESS_H
#define _SERVER_PROCESS_H
#include "elma.h"
#include "tcp_server.h"
#include <sys/ioctl.h>
#include <json/json.h>
#include <iostream>

using nlohmann::json;
using namespace elma;
using namespace std;

//! Creating an instance of TCP/IP server with port number.
TcpServer svr(54321);

//! An inherited elma process class which serves as a TCP/IP server.

//! Receives data from client and send acknowledgement back.
class ProServer : public elma::Process {
   public: 
        
   //! The constructor wraps the base constructor.
   //! \param name The name of the process
   ProServer(string name) : Process(name) {}
   
   //! Virtual method of abstract elma process class.
   //! Watch for events and corresponding handlers are described.
   //! Manager emits events to start and stop server.
   void init() {
      watch("start_server",[this](Event& e ) {
         svr.listen();
      });
      watch("stop_server",[this](Event& e ) {
         svr.~TcpServer();
      });
      watch("server_send",[this](Event& e ) {
         svr.send(message);
      });
              
   }     

   //! Nothing to do to start.  
   void start() {}

   //! TCP/IP messages are send and received in update method.
   //! Mind the print statement included to check data received from client on the server terminal.
   //! An acknowledgement is sent back in the emit event and count of it is registered to test in gtest.
   void update() {
      data = svr.receive(1024);
      cout<<"Server Received "<<data.get<std::string>()<<endl;
      message["Acknowledgement to Client:"] = msgcnt++;
      emit(Event("server_send",message));
   }   

   //! Useful method to check received data in gtest.
   //! \return received json message from client.
   json value(){
      return data;
   } 

   //! Method to check number of messages received. Useful for gtest.
   //! \return number of messages received
   int ack(){
      return msgcnt;
   }

   //! Nothing to do to stop 
   void stop() {}
           
   private:
      int msgcnt = 0;
      json data;
      json message;
                       
   };
   #endif
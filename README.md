Elma_TCP
===

Elma is an event loop and process manager for embedded and reactive systems. It keeps track of processes, finite state machines, events, and communication channels, executing them at specified frequencies. Currently, processes talk to each other via events, this repository contains methods which describes how Json messages will be send back and forth between processes using TCP/IP protocol.

The source code for Elma_TCP [is on Github](https://github.com/charuari/elma_TCP).

Installation
===

To get started, you will need a C++ build environment to compile.
- git clone https://github.com/charuari/elma_TCP.git
- cd elma_TCP
- docker run -v $PWD:/source -it klavins/elma:latest bash
- make

Execution
===
Example 1
---
- examples/bin/test_pingserver &
- examples/bin/test_pingclient
- ps waux

Example 2
---
- example/bin/test_server &
- example/bin/test_client
- ps waux

Design Process
===
To make Elma processes communication via TCP/IP, the first step I decided to do is to write a C++ library for TCP/IP server and client, so that instances of them can be used inside elma process derived class. The library I used is C socket library and many resources had things written in C. Hence, writing one in C++ felt mandatory in my case. The send and receive features of server and client involves byte packets and initially, I had designed them  for only strings and tested it with basic server client chat . Upon success, I had to tweek a little to make it suitable for json messages. Now, TCP/IP server client could send back and forth json messages.


The goal of this project is to use this in Elma and I had decided to build two examples for it.
    1. Simple client server ping
    2. Temperature server

Description
===
Simple client server ping
---
This was experimented to see how to integrate the so far stand-a-lone TCP/IP into Elma.

Server and client were derived from abstract base class of Elma process and the update of client process will emit the json message(here, it's just an hello) which is to be send to server. This event will be watched in the init method with appropriate handler.

Similarly, the update of server process will receive the message from client and send back the current time and date as an acknowldegement of the established communication.

Just printing the messages from server and client terminal help us to confirm the communication.

Temperature server
---
Server and client are derived from Elma process base class. A helper class is used to generate random temperature and geographic co-ordinates which serves as data to be sent by client to server. This data will be sent from client process update method to server and it is received in the server process update method and the server sends back the count of the data received so far.

The random data generator is set with srand(0), for the values to be determinant so that it can be tested in the server side if same data is received. Also, the number of updates of server process is tested for the number of acknowledgements sent back to client.

Print statements from server and client terminals are used to confirm communication.

Files
===
C++ library for TCP/IP:
---
- tcp_server.h
- tcp_client.h
- tcp_server.cc
- tcp_client.cc

Simple Client Server ping
---
- server_ping.h
- client_ping.h
- test_pingserver.cc
- test_pingclient.cc

Temperature Server
---
- data_generator.h
- server_process.h
- client_process.h
- test_server.cc
- test_client.cc

File structure:
===
- src
    - channel.cc
    - client.cc
    - manager.cc
    - process.cc
    - state_machine.cc
    - state.cc
    - tcp_client.cc
    - tcp_server.cc

- include
    - channel.h
    - client.h
    - client_ping.h
    - client_process.h
    - data_generator.h
    - elma.h
    - event.h
    - exceptions.h
    - literals.h
    - manager.h
    - process.h
    - server_ping.h
    - server_process.h
    - state.h
    - state_machine.h
    - tcp_client.h
    - tcp_server.h
    - transition.h

- examples
    - Makefile
    - test_client.cc
    - test_pingclient.cc
    - test_pingserver.cc
    - test_server.cc    

Results
===
- Simple Client Server ping
    - Please find the print statements of messages from client and server side.
    - Client pings server with "Hello"
    - Server responds with current date and time.

![Prints from server & client](https://github.com/charuari/elma_TCP/blob/master/images/pingimage.PNG)

- Temperature Server
    - Please find the print statements of messages from client and server side.
    - The length of the data sent from client is tested against the message received by server.
    - Also, the number of updates of server process is tested against the number of acknowledgements sent by server to client.

![Prints from server & client](https://github.com/charuari/elma_TCP/blob/master/images/temperatureimage.PNGg)

Acknowledgements
===

A great thanks to the following people!

- Prof.Klavins - He was of a great help for giving me ideas about how to integrate TCP/IP into Elma. He also advised me how to write a gtest for this case.

- Justin Vrana - Gave me the idea about showing print statements from server and client side to confirm the established connection, in case test case couldn't be written.

- Kung-Hung(Henry)Lu - Helped me with the file structure and makefile for server client applications.

References
===
Libraries
---
- Elma
- C socket libraries 
    - sys/types.h
    - sys/socket.h
    - netdb.h
    - netinet/in.h
Links
---
- https://www.geeksforgeeks.org/socket-programming-cc/
Books
---
- Exploring Raspberry PI by Derek Molly







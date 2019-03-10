Elma_UDP
===

Elma is an event loop and process manager for embedded and reactive systems. It keeps track of processes, finite state machines, events, and communication channels, executing them at specified frequencies. Currently, processes talk to each other via events.

Goal
----

The ultimate goal of this project Elma_UDP, is to facilitate processes communication using UDP/IP. UDP is a lightweight, no congestion control, higher speed communication protocol for devices over an ethernet and /or internet. It provides sending and receiving of data between two hosts in a connectionless manner.

My contributions
------

In this project, I will create separate C++ classes for server and client and object of these classes will be used by the processes to reach out each other depending upon the application. I will also make the server and client use Json messages for their communication because it is ubiquitously used in networked systems. 

Upon completion...
------

I will be able to understand how UDP/IP works and become proficient in using C++. As a first time programmer in C++, this project will help me enhance my understanding of various C++ concepts like classes, polymorphihsm, inheritance etc. Also, because of wide variety of applications of UDP/IP in the field of IoT, this project will broaden my knowledge about IoT features, the area which I am really interested to venture.

Resources
====

- Elma
- C socket libraries 
    - sys/types.h
    - sys/socket.h
    - netdb.h
    - netinet/in.h

Milestones
====
Below is the table of milestones I have set to complete this project.

|Milestone                                          | Date   |
|:---                                               | :---:  |
|1. Understand steps involved in UDP/IP             |03.10.19|
|2. Write basic class for sever and client          |03.12.19|
|3. Incorporate json as content of communication    |03.14.19|
|4. Implement in elma                               |03.20.19|
|5. API documentation                               |03.22.19|


Installation
===

The source code for Elma_UDP [is on Github](https://github.com/charuari/elma_UDP).

From Dockerhub
---

To get started, you will need a C++ build environment to compile.
    git clone https://github.com/charuari/elma_UDP.git
    docker run -v $PWD:/source -it klavins/ecep520:cppenv-json bash
    make 
    examples/bin/basic
    

Manual Installation
---

To install Elma without using Docker, you will need to install the following tools:
- [gcc](https://gcc.gnu.org/) 4.9 or an equivalent C/C++ compiler that supports at least C++14
- Make (if you want to use the makefile. Alternatively, you can use some other build manager)
- [Doxygen](http://www.doxygen.nl/)
- [Google Test](https://github.com/google/googletest)
- Neils Lohmann's JSON library: https://github.com/nlohmann/json

Usage
===

Coming soon



Elma_TCP
===

Elma is an event loop and process manager for embedded and reactive systems. It keeps track of processes, finite state machines, events, and communication channels, executing them at specified frequencies. Currently, processes talk to each other via events.

Goal
----

The ultimate goal of this project Elma_TCP, is to facilitate processes communication using TCP/IP. 

My contributions
------

In this project, I will create separate library for server and client and object of these classes will be used by the processes to reach out each other depending upon the application. I will also make the server and client use Json messages for their communication because it is ubiquitously used in networked systems. 

Upon completion...
------

I will be able to understand how TCP/IP works and become proficient in using C++. As a first time programmer in C++, this project will help me enhance my understanding of various C++ concepts like classes, polymorphihsm, inheritance etc. Also, because of wide variety of applications of TCP/IP in the field of IoT, this project will broaden my knowledge about IoT features, the area which I am really interested to venture.

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

|Milestone                                          | Date   |  Adjusted dates|
|:---                                               | :---:  |   :---:        |
|1. Understand steps involved in TCP/IP             |03.10.19|03.11.19        |
|2. Write basic class for sever and client          |03.12.19|03.13.19        |
|3. Incorporate json as content of communication    |03.14.19|03.15.19        |
|4. Implement in elma                               |03.20.19|03.21.19        |
|5. API documentation                               |03.22.19|03.22.19        |

Accomplishments until 03.17.19
===
- Wrote C++ library for TCP server and client 
- Passed test cases for server client communication using string messages
    - Please find inside final_string directory.
- Passed test cases for server client communication using json messages
    - Please find under final_json directory.

Installation
===

The source code for Elma_TCP [is on Github](https://github.com/charuari/elma_TCP).

From Dockerhub
---

To get started, you will need a C++ build environment to compile.
- git clone https://github.com/charuari/elma_TCP.git
- docker run -v $PWD:/source -it klavins/elma:latest bash
- cd elma_TCP
    - cd final_string
        - make 
        - test/bin/test_server &
        - test/bin/test_client
    - cd final_json
        - make 
        - test/bin/test_server &
        - test/bin/test_client 

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



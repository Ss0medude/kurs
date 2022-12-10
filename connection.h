#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;
class connection {
private:
    int s;
    int rc;
    struct sockaddr_in selfAddr;
    //sockaddr_in * selfAddr = new (sockaddr_in);
    //selfAddr->sin_family = AF_INET; 
    //selfAddr->sin_port = htons(44214); 
    //selfAddr->sin_addr.s_addr =inet_addr("127.0.0.1"); 
    //sockaddr_in * client_addr = new sockaddr_in;
    //socklen_t len = sizeof (sockaddr_in);
public:
connection()=delete;
int Socket(){return s;}
int Bind(){return rc;}
int Listen(){return rc;}
int Accept(){return work_sock;}
int RECV(){return rc;}

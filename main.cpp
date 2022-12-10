#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <sys/types.h>
using namespace std;

void error_processing(const char * why, const int exitcode = 1)
{
    cerr<< why << endl;
    exit(exitcode);
}
void Print(const char * line)
{
    cerr<< line << endl;
}
int main (int argc, char **argv)
{
    //1 пункт подготовить структуру с адресом нашей программы(сервера)
    sockaddr_in * selfaddr = new (sockaddr_in);
    selfaddr->sin_family = af_inet; // интернет протокол ipv4
    selfaddr->sin_port = htons(44214); // любой порт на усмотрение ос
    selfaddr->sin_addr.s_addr =inet_addr("127.0.0.1"); // все адреса нашего пк

    // 2 пункт создать сокет
    int s = socket(af_inet, sock_stream, 0); 
    if (s == -1) {
        error_processing("error open socket",11);
    }
    //3 пункт связать сокет с адресом
    int rc = bind(s, (const sockaddr *) selfaddr, sizeof ( sockaddr_in));
    if (rc == -1) {
        close(s);
        error_processing("error bind socket with local address",12);
    }
    //4 пункт поставить сокет в режим ожидания соединения
    rc = listen(s, 1);
    if ( rc == -1) {
        close(s);
        errhandler("error calling listen",13);
    }
    // 5 пункт подготовить пустую адресную структуру (для клиента),принять клиентское соединение из очереди соединений
    sockaddr_in * client_addr = new sockaddr_in;
    socklen_t len = sizeof (sockaddr_in);
    
    int work_sock = accept(s, (sockaddr*)(client_addr), &len);
    if (work_sock == -1) {
    error_processing("error accept connection",14);
 }
       // подготовить буфер для передачи и приема данных
    char *id = new char[256];
    // HASH
    int msglen = strlen(id); // вычисляем длину строки
    uint32_t kolvo;
    uint32_t size;
    vector <uint16_t> Value[kolvo*size];
    //ауентификация успешная или нет
            if 
            {}
            else {
            close(s);
            id[rc]='\0';
            
            Print("ERR");
            }
    // принять вектора
    Print("id");
    rc = recv(s, id, 256,0);
    if ( rc == -1) {
        close(s);
        error_processing("error receive answer",15);
    }             
      Print("kolvo");
    rc = recv(s, kolvo, 32,0);
    if ( rc == -1) {
        close(s);
        error_processing("error receive answer",17);
    }   
     print("size");
    rc = recv(s, size, 32,0);
    if ( rc == -1) {
        close(s);
        error_processing("error receive answer",18);
    }  
      print("value");
    rc = recv(s, value, 256,0);
    if ( rc == -1) {
        close(s);
        error_processing("error receive answer",19);
    }        
     //произведение векторов       
    //передать данные
    // закрыть сокет
    close(s);

    delete selfaddr;
    delete client_addr;
    delete[] id;
    return 0;
}

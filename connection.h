#pragma once
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include "read_base.h"
using namespace std;
/**
@brief Класс соединения с клиентом
@details Для соединения использованы сокеты
*/
class connection
{
private:
    int s;///< Основной сокет
    struct sockaddr_in selfaddr;///<Структура sockaddr_in
    int port;///< Порт, на котором работает сервер 33333
    const char * adress="127.0.0.1";///<Сетевой адрес сервера
public:
    /**
     @brief Конструктор
     @details Устанавливает порт, инициализирует основной сокет и структуру sockaddr_in
     @param [in] port, порт, на котором работает сервер, int.
     */
    connection(int port);
    /**
     @brief Привязка сокета к адресу
    */
    int Bind();
    /**
    @brief Установка сокета в пассивный режим ожидания
    */
    void Listen();
    /**
    @brief Приём соединения
    */
    int Accept();
    /**
    @brief Приём данных от клиента
    @param [in] sock, сокет, int
    @param [in] buf, буфер для данных, void*
    @param [in] size, размер буфера, int
    */
    int Recv(int s, void*buf, int size);
    /**
    @brief Отправка данных клиенту
    @param [in] sock, сокет, int
    @param [in] buf, буфер с данными, void*
    @param [in] sizeb, количество отправляемых байт, int
    */
    void Send(int s, void*buf, int sizeb);
    /**
        @brief Закрытие сокета
        */
    void Close();
    
    void server_client(int port, string log_name, base db, int sock);
};

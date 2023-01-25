#pragma once
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <map>
#include <fstream>
using namespace std;
/**
@brief Класс для получения параметров коммандной строки
*/
class server
{
private:
    int port=33333;///< Порт, на котором работает сервер
    string base_name="/home/stud/kurs/vcalc.conf";///< Путь к файлу с базой данных
    string log_name = "/var/log/vcalc.log";///< Путь к журналу ошибок
    void help();///<вывод подсказки
public:
    /**
     @brief Конструктор, внутри которого считываются параметры командной строки
     @details Параметры  командной строки:
    	1)-b Путь к файлу с базой данных, необязательный
    	2)-l Путь к файлу для записи логов, необязательный
    	3)-p Порт, на котором работает сервер, необязательный
    	4)-h вызов подсказки
        5) ? вызов подсказки
    	При ошибках в параметрах или запуске без них вызывается справка и программа завершает работу
     @param [in] int argc
     @param [in] char **argv
    */
    server(int argc, char **argv);
    string get_base()///<Возвращает путь к файлу с базой данных
    {
        return base_name;
    };
    string get_log()///<Возвращает путь к журналу ошибок
    {
        return log_name;
    };
    int get_port()///<Порт, на котором работает сервер
    {
        return port;
    };
};

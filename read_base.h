#pragma once
#include <map>
#include <string>
#include <fstream>
#include <exception>
#include <typeinfo>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "error_processing.h"
using namespace std;
/**
@brief Класс для работы с базой данных 
*/

class base
{
private:
    char sep = ':';///<Разделитель идентификатора и пароля в базе данных
public:
    map <string,string> DataBase;///<Словарь с парами идентификатор:пароль
    /** 
 @brief Конструктор, считывающий базу данных и сохраняющий её в словарь
 @param [in] base_name, путь к файлу с базой данных, string.
*/
    base(string base_name);
    /** 
 @brief Проверка наличия идентификатора клиента в базе данных
 @param [in] user, идентификатора клиента, string
*/
    bool check_user(string user);
};

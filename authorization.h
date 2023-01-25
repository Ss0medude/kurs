#pragma once
#include <map>
#include <string>
#include <iostream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>
#include <fstream>
#include <random>
#include <sstream>
#include <exception>
#include <typeinfo>
#include <string>
#include <chrono>
#include "error_processing.h"
using namespace std;
/**
@brief Класс для аутентификации клиента на сервере
@details Функция вычисления хэша MD5
*/
class authorization
{
private:
    string salt;///< Соль для вычисления хэша
    string id;///< Идентификатор клиента
    string password;///< Пароль клиента
    string Hash;///< Хэш в виде шестнадцатиричных цифр
public:
    /**
     @brief Конструктор для установки идентификатора и пароля клиента
     @param [in] Id, идентификатор клиента, string.
     @param [in] Password, пароль клиента, string.
    */
    authorization(string Id, string Password);
    /**
    @brief Генерация случайной соли для вычисления хэша
    @param [in] salt, соль, string.
    @param [in] size, размер соли, size_t.
    */
    void generate_salt();
    char err[3] = {'E','R','R'};///< Сообщение, отсылаемое клиенту при ошибке его обрабоки
    char ok[2] = {'O','K'};///< Сообщение, отсылаемое клиенту при успешной авторизации
    /**
    @brief Сравнение хэша, присылаемого клиентом и хэша, вычисляемого внутри метода
    @param [in] client_hash, хэш клиента, tring
    */
    bool compare_hash(string client_hash);
    string get_salt() ///< Возвращает соль
    {
        return salt;
    }
};

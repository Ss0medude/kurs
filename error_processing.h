#pragma once
#include <exception>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;
/**
@brief Класс для обработки ошибок и записи в журнал
*/
class error_processing
{
private:
    string log_path="/home/stud/kurs/vcalc.log"; ///< Путь к файлу с журналом ошибок
public:
    error_processing() {}; ///< Конструктор без параметров
    string get_log_path(string log_path)
    {
        return log_path;
    };///<Функция, выдающая путь к файлу с журналом ошибок
    /**
    @brief Функция записи ошибки в журнал
    @details Функция записывает время, суть и критичность ошибки
    @param [in] why, суть ошибки, string
    @param [in] exit, критичность ошибки (Критическая - true, Некритическая - false), string
    */
    void write_log(string why, bool exit);
    ~error_processing() {}; ///< Деструктор
};
/**
@brief Класс для обработки ошибок
@details Наследует от класса invalid_argument
*/
class name_error: public invalid_argument
{
private:
    bool status = false;///<Статус критичности ошибки
public:
    /**
     @brief Конструктор ошибок с строкой в качестве параметра
     @param [in] whyy, тип ошибки, const string.
     @param [in] exitt, критическа ошибка - true, некритическая ошибка - false, bool
    */
    explicit name_error (const string& whyy, bool exitt = false):
        invalid_argument(whyy)
    {
        status = exitt;
    }
    /**
     @brief Конструктор ошибок с си-строкой в качестве параметра
     @param [in] whyy, тип ошибки, const char*.
     @param [in] exitt, критическа ошибка - true, штатная - false, bool
    */
    explicit name_error (const char* whyy,  bool exitt=false):
        invalid_argument(whyy)
    {
        status=exitt;
    }
    bool get_status() const
    {
        return status;   ///<Возвращает статус критичности ошибки
    }
};

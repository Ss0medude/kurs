#pragma once
#include <vector>
#include <iostream>
#include <exception>
#include "error_processing.h"
using namespace std;
/**
@brief Класс для вычислений по вектору
@details Операция - произведение
*/
class calc
{
private:
    int16_t result[1];///< Результат вычислений
public:
    calc() {}; ///<Конструктор без параметров
    /**
    @brief Вычисляет произведение вектоов
    @param [in] vector, вектор, vector<int16_t>
    */
    int16_t * calculation(vector<int16_t> vecto)
    {
        try {
            if (vecto.empty()) {
                throw name_error(string("error empty vector"));
            }
            for (std::vector<int16_t>::iterator it = vecto.begin() ; it != vecto.end(); ++it) {
                cout << ' ' << *it;
            }
            cout << '\n';
            int16_t avg = 1;
            for (uint32_t i = 0; i < vecto.size(); i++) {
                avg *= vecto[i];
            }
            result[0] = avg;
        } catch(std::exception &e) {
            throw name_error(string("error calculation"));
        }
        return result;
    }
};

#include "error_processing.h"
using namespace std;

void error_processing::write_log(string why, bool exit)
{
    auto end = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(end);
    ofstream log;
    log.open (log_path,fstream::out | fstream::app);
    if (exit) {
        log << "Время ошибки: " << ctime(&end_time)
            << "\t Ошибка: " << why
            << " Критическая ошибка" << ";\n";
    } else  {
        log << "Время ошибки: " << ctime(&end_time)
            << "\t Ошибка: " << why
            << " Некритическая ошибка" << ";\n";
    }
    log.close();
}

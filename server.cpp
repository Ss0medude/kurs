#include "server.h"

void server::help()
{
    cout << "Параметры:\n'-b' База данных\n'-l' Журнал работы\n'-p' Порт \n'-h' Вызов инструкции\n";
    exit(1);
}
server::server(int argc, char **argv)
{
    int opt;
    while ((opt = getopt(argc, argv, "b:l:p:h:")) != -1) {
        switch (opt) {
        case 'b':
            base_name = string(optarg);
            break;
        case 'l':
            log_name = string(optarg);
            break;
        case 'p':
            port = strtol(optarg,nullptr,10);
            break;
        case 'h':
        case '?':
            help();
        }
    }
}

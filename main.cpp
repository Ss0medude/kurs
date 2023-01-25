#include "connection.h"
#include "error_processing.h"
#include "authorization.h"
#include "server.h"
#include "calculation.h"
#include "read_base.h"
/**
*@file server
* @author Сергеева С.В.
* @version 1.0.0
*@brief Функция main
* @date 23.01.2022
* @copyright ИБСТ ПГУ
*/
int main (int argc, char **argv)
{
    error_processing er_pr;
    try {
        server ser(argc, argv);
        er_pr.get_log_path(ser.get_log());
        base db(ser.get_base());
        connection client(ser.get_port());
        client.Bind();
        client.Listen();
        int sock;
        while(true) {
            sock = client.Accept();
            cout<<"подключено"<<endl;
            client.server_client(ser.get_port(), ser.get_log(), db, sock);
        }
    } catch (const name_error & e) {
        er_pr.write_log(e.what(), e.get_status());
        if (e.get_status()) {
            exit(1);
        }
    }
    return 0;
}

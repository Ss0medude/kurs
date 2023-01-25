#include "connection.h"
#include "error_processing.h"
#include "authorization.h"
#include "server.h"
#include "calculation.h"
#include "read_base.h"
void connection::Close()
{
    close(s);
}
connection::connection(int port)
{
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == -1) {
        throw name_error(string("error open socket"),true);
    }
    selfaddr.sin_family = AF_INET;
    selfaddr.sin_port = htons(port);
    selfaddr.sin_addr.s_addr = inet_addr(adress);
}
int connection::Bind()
{
    int rc = bind(s, (struct sockaddr *)&selfaddr, sizeof ( sockaddr_in));
    if (rc == -1) {
        throw name_error(string("error bind socket with local address"),true);
        return rc;
    }
    }
    void connection::Listen() {
        int rc = listen(s, 1);
        if ( rc == -1) {
            throw name_error(string("error calling listen"),true);
        }
    }
    int connection::Accept() {
        sockaddr_in * client_addr = new sockaddr_in;
        socklen_t len = sizeof (sockaddr_in);
        int rc = accept(s, (sockaddr*)(client_addr), &len);
        if (rc == -1) {
            throw name_error(string("error accept connection"),false);
            return rc;
        }
    }
    int connection::Recv(int s,void*buf, int size) {
        int rc = recv(s, buf, size, 0);
        if ( rc == -1) {
            Close();
            throw name_error(string("error receive answer"),false);
            return rc;
        }
    }
    void connection::Send(int s, void*buf, int sizeb) {
        int rc = send(s, buf, 256, 0);
        if ( rc == -1) {
            Close();
            throw name_error(string("error send answer"));
        }

    }
    void connection::server_client(int port, string log_name, base db, int sock) {
    try {
                connection client(port);
                char buf[2048];
                int user;
                user = client.Recv(sock, &buf, 2048);
                string user_id = string(buf, user);
                for (uint i = 0; i < user_id.size(); i++) {
                    if (user_id[i] == '\n') {
                        user_id.pop_back();
                    }
                }
                cout<< "Подключенный клиент:"<< user_id << "№" <<user_id.size()<<endl;
                db.check_user(user_id);
                authorization autho(user_id, db.DataBase[user_id]);
                autho.generate_salt();
                string salt = autho.get_salt();
                char salt_buf[16];
                strcpy(salt_buf, salt.c_str());
                client.Send(sock, salt_buf, sizeof(salt_buf));
                user = client.Recv(sock, &buf, 2048);
                string Password = string(buf, user);
                for (uint i = 0; i < Password.size(); i++) {
                    if (Password[i] == '\n') {
                        Password.pop_back();
                    }
                }
                autho.compare_hash(Password);
                client.Send(sock, autho.ok, sizeof(autho.ok));
                uint32_t num_vectors;
                uint32_t vector_len;
                user = client.Recv(sock, &num_vectors, sizeof num_vectors);
                for(unsigned int i =0; i< num_vectors; i++) {
                    user = client.Recv(sock, &vector_len, sizeof vector_len);
                    int16_t int_buf[vector_len];
                    user = client.Recv(sock, &int_buf, vector_len*sizeof(int16_t));
                    vector<int16_t> vecto;
                    for(unsigned int i =0; i< vector_len; i++) {
                        vecto.push_back(int_buf[i]);
                    }
                    client.Send(sock, calc().calculation(vecto), sizeof(int16_t));
                }
                client.Close();
                cout<<"завершено" << endl;
                return ;
            } catch (const name_error & e) {
            error_processing er_pr;
                er_pr.write_log(e.what(), e.get_status());
                if (e.get_status()) {
                    exit(1);
                }
            }
            connection err_send(port);
            err_send.Send(sock, authorization("ERR","ERR").err, sizeof(authorization("ERR","ERR").err));
            close(sock);
            return ;
        }
   
    

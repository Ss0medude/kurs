#include "authorization.h"

authorization::authorization(string Id, string Password)
{
    id = Id;
    password = Password;
}

void authorization::generate_salt()
{
    unsigned long salti[16];

        for(int i = 0; i < 16; i++)
        {
        	salti[i] = (unsigned long)std::rand();
        }
    stringstream stream;  
    stream<<hex<<salti;  
    string str = stream.str(); 
     for (long unsigned int i =0; i<=str.size(); i++) {
        str[i] = toupper(str[i]);
        }
        if (str.size() < 16) {
        string strstr =str;
        for (unsigned i = str.size(); i <16; i++) {
            strstr.insert (strstr.begin(), '0');
            }
            str=strstr;
            }
        salt=str;
}

bool authorization::compare_hash(string client_hash)
{
    try {
        using namespace CryptoPP;
        Weak::MD5 hash;
        string msg = salt+password;
        cout<<"Солёный пароль:"<<msg<<endl;
        StringSource ss(msg, true /*pumpAll*/, new HashFilter(hash, new HexEncoder(new StringSink (Hash))));
    } catch(const CryptoPP::Exception& e ) {
        throw name_error(string("error hash calsulation"),false);
        return false;
    }
    cout<<"Хэш клиента: "<<client_hash<<" "<<"Хэш сервера: "<<Hash<<" "<<client_hash.compare(Hash)<<endl;
    if (client_hash.compare(Hash) != 0) {
        throw name_error(string("error hash not same"),false);
    }
    return (client_hash.compare(Hash) == 0);
}

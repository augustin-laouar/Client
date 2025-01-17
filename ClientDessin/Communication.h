#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <string>
#include "Erreur.h"
#ifndef CLIENTDESSIN_COMMUNICATION_H
#define CLIENTDESSIN_COMMUNICATION_H
using namespace std;

class Communication {
private:
    SOCKET sock;
    SOCKADDR_IN sockaddr;
    int connexion;
    static  Communication *comm  ;
    
    Communication(const char*, short);
    
public:
    virtual ~Communication(){}
    /** @brief methode permettant d'avoir une seule instance de communication pour pouvoir ouvrir une seule communication
    */
    static Communication* getInstance(const char* c = "127.0.0.1", short i=9111) {
      
            if (comm == nullptr) {
               comm = new Communication(c,i);
            }
        return comm;
    } 
    /**
    * e@brief methode pour envoyer un message 
    */
    
    void Envoyer(const char* message) {
        connexion = send(sock, message, strlen(message), 0);
    }
    /**
    * @brief se preparer a la reception d'une chaine de caractere 
    */
    void Recevoir(char* buff, int len) {
        connexion = recv(sock, buff, len, 0);
    }
    /** @brief fermeture d'une connexion 
    */
    void FermerConnexion() {
        connexion = shutdown(sock, SD_BOTH);                            // on coupe la connexion pour l'envoi et la r�ception
        // renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

        if (connexion == SOCKET_ERROR)
            throw Erreur("la coupure de connexion a �chou�");


        connexion = closesocket(sock);                          // renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
        if (connexion) throw Erreur("La fermeture du socket a �chou�");

        WSACleanup();
    }
};


#endif //CLIENTDESSIN_COMMUNICATION_H

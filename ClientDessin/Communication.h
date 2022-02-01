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
public:
    Communication(const char*, short);
    void Envoyer(const char* message) {
        connexion = send(sock, message, strlen(message), 0);
    }
    void Recevoir(char* buff, int len) {
        connexion = recv(sock, buff, len, 0);
    }
    void FermerConnexion() {
        connexion = shutdown(sock, SD_BOTH);                            // on coupe la connexion pour l'envoi et la réception
        // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

        if (connexion == SOCKET_ERROR)
            throw Erreur("la coupure de connexion a échoué");


        connexion = closesocket(sock);                          // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
        if (connexion) throw Erreur("La fermeture du socket a échoué");

        WSACleanup();
    }
};


#endif //CLIENTDESSIN_COMMUNICATION_H

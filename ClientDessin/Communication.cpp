#pragma warning(disable:4996) 
#pragma comment(lib, "ws2_32.lib") // spécifique à VISUAL C++
#include "Communication.h"
Communication::Communication(const char* adresse, short port) {
	WSADATA wsaData;        // structure contenant les données de la librairie winsock à initialiser

	connexion = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2

	/* en cas de succès, wsaData a été initialisée et l'appel a renvoyé la valeur 0 */

	if (connexion) throw Erreur("L'initialisation a échoué");

	cout << "client vers le serveur de majuscule" << endl;
	cout << "initialisation effectuée" << endl;

	//---------------------- création socket -------------------------------------------------


	int familleAdresses = AF_INET;         // IPv4
	int typeSocket = SOCK_STREAM;           // mode connecté TCP
	int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
	// pour les valeurs des paramètres : cf. fct socket dans la doc sur winsock

	this->sock = socket(familleAdresses, typeSocket, protocole);

	if (sock == INVALID_SOCKET)
	{
		ostringstream oss;
		oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;    // pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
		throw Erreur(oss.str().c_str());
	}
	//------------------------------ création du représentant du serveur ----------------------------------------

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = inet_addr(adresse);   // inet_addr() convertit de l'ASCII en entier
	//InetPton(adresseServeur, sockaddr.sin_addr.s_addr);
	sockaddr.sin_port = htons(port);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

	//-------------- connexion du client au serveur ---------------------------------------

	this->connexion = connect(sock, (SOCKADDR*)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.
	// Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

	if (connexion == SOCKET_ERROR)
		throw Erreur("La connexion a échoué");

}
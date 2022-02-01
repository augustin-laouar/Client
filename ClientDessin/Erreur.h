#pragma once
#include <exception>
using namespace std;
class Erreur : public exception
{
private:
    const char* msg;
public:
    Erreur(const char* m) { msg = m; }
    const char* what() {
        return msg;
    }
};


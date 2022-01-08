#ifndef ALGOPRINCIPAL_H_INCLUDED
#define ALGOPRINCIPAL_H_INCLUDED

#include "decryFunc.h"

class BruteCrack
{
public:
    BruteCrack();
    void Run();
private:
    void accueil();
    void askPassword();
    void registering();
    void redirect();
    void crack();
    std::string setAddresse();
    bool verifyUsed();
    std::string takePass(int number);
    std::string recupPass();
    std::string setBase();
    std::string regPass;
    std::string passWay;
    std::ifstream getPass;
    std::ofstream putPass;
    std::ifstream tempo;
    std::ifstream lector;
    bool used;
    const int PassSize = 8;
    std::vector<std::string> potentiels;
    std::vector<std::string> admis;
    std::vector<std::string> repeche;
};

#endif // ALGOPRINCIPAL_H_INCLUDED

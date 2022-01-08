#ifndef DECRYFUNC_H_INCLUDED
#define DECRYFUNC_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <map>
#include <vector>

enum lisibilite{bon,moyen,faible};
std::string AllRunner(int decalage,char sacrifice);
char decrypt(int clover,char threat);
std::string revertit(int cible);//fonction qui convertit les nombre en char
lisibilite verifie(std::string addresse);//Verifie si le contenu du fichier est lisible

#endif // DECRYFUNC_H_INCLUDED

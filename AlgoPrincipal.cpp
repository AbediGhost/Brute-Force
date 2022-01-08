#include "AlgoPrincipal.h"

using namespace std;

BruteCrack::BruteCrack()
{
    cout << "Creation du cracker\n\n";
    passWay = "data/SR92i.abt";
    used = verifyUsed();
}

void BruteCrack::Run()
{
    accueil();
    redirect();
    crack();
}

void BruteCrack::accueil()
{
    system("color f");
    cout << "Bienvenue dans le programme de Brute_Cracking de Abedi-Technology !!!" <<endl;
    cout << "Copyright 2016 ©Abedi_Technology" <<endl;
    cout << "Produit numero : 005-122-016" <<endl;
    cout << "Version : 1.0.0.0"<<endl;
}

void BruteCrack::askPassword()
{
    cout << "----------Quel est votre mot de passe-------------"<<endl;
    int cx,ax = 0;
    do
    {
        cx = 0;
        cin >> regPass;
        if(regPass != recupPass())
        {
            cout << "___________Mot de Passe INCORRECT!!!!____________"<<endl;
            cx = 1;
            ax++;
        }
        if(ax >= 5)
        {
            exit(0);
        }
    }while(cx == 1);
}

void BruteCrack::registering()
{
    cout << "_____________________Inscription________________________"<<endl;;
    cout << "-------------Veuillez entrer un mot de passe------------"<<endl;;
    regPass = takePass(PassSize);
    putPass.open(passWay.c_str());
    putPass << regPass;
    putPass.close();
    system("del data\\ver\\chico.abt");
}

void BruteCrack::redirect()
{
    if(used == true)
    {
        askPassword();
    }
    else if(used == false)
    {
        registering();
    }
}

bool BruteCrack::verifyUsed()
{
    tempo.open("data/ver/chico.abt");
    if(!tempo)
        return true;
    else
        tempo.close();
        return false;
}

string BruteCrack::takePass(int number)
{
    string PassWord;
    system("color A");
    for(int i=0;i<number;i++)
    {
        PassWord += getch();
        cout<<"*";
    }
    cout <<endl;
    system("color F");
    return PassWord;
}

string BruteCrack::recupPass()
{
    string MotDePasse;
    getPass.open(passWay.c_str());
    getPass >> MotDePasse;
    getPass.close();
    return MotDePasse;
}

string BruteCrack::setBase()
{
    string addresse;
    bool exist = false;
    cout << "Veuillez entrer l'addresse du fichier a cracker"<<endl;
    do
    {
        cin >> addresse;
        ifstream test(addresse.c_str());
        if(test)
        {
            exist= true;
            test.close();
        }

    }while(exist == false);
    return addresse;
}

void BruteCrack::crack()
{
    string victime;
    string nomFichier;
    lisibilite esAdmis;
    char stockage;//variable pour stocker le caractere  dechiffrer
    victime = setBase();
    for(int i=0;i<26;i++)
    {
        lector.open(victime.c_str());
        while(lector.get(stockage))
        {
            nomFichier = "";
            nomFichier = AllRunner(i,stockage);
        }
        potentiels.push_back(nomFichier);
        lector.close();
    }
    cout <<potentiels.size() << " fichiers potentiels"<<endl;
    for(int i=0;i<potentiels.size();i++)
    {
        cout << "fichier "<<potentiels[i] <<endl;
        esAdmis = verifie(potentiels[i]);
        if(esAdmis == bon)
        {
            admis.push_back(potentiels[i]);
            cout <<potentiels[i] << " ajoute aux fichiers potentiels"<<endl;
        }
        else if(esAdmis == moyen)
        {
            repeche.push_back(potentiels[i]);
            cout <<potentiels[i] << " ajoute aux fichier moyens"<<endl;
        }
    }
    system("MD bon");
    system("MD moyen");
    for(int i=0;i<admis.size();i++)
    {
        cout << "Deplacement"<<endl;
        string totaux = "move /Y "+admis[i]+" admis";
        system(totaux.c_str());
    }
    for(int i=0;i<repeche.size();i++)
    {
        cout << "Deplacement"<<endl;
        string totaux = "move /Y "+repeche[i]+" moyen";
        system(totaux.c_str());
    }
    system("color F");
    cout << "_______________Cracking termine______________"<<endl;
    cout << "_________Veuillez consulter les differentes propositions_________"<<endl;
    cout << "________________________________________Copyright 2016 ©Abedi_Technology" <<endl;
    cout << "________________________________________Produit numero : 005-122-016" <<endl;
    cout << "________________________________________Version : 1.0.0.0"<<endl;
    getch();
}

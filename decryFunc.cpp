#include "decryFunc.h"

using namespace std;

string AllRunner(int decalage,char sacrifice)
{
    char resultat;
    string prenom;
    string nom;
    ofstream writer;
    resultat = decrypt(decalage,sacrifice);
    cout << "Cracking avec la cle "<<decalage << " du caractere "<<sacrifice <<endl;
    prenom = revertit(decalage);
    nom = "cle"+prenom+".abt";
    writer.open(nom.c_str(),ios::app);
    writer.put(resultat);
    writer.close();
    return nom;
}

char decrypt(int clover,char threat)
{
    string delta = "abcdefghijklmnopqrstuvwxyz";
    char toReturn;
    int special = 0;
    int poste=0;
    for(int k=0;k<26;k++)
    {
        if(threat == delta[k])//on cherche le char dans la liste
        {
            poste = k;//On donne la position d char
            break;
        }
        if(threat == '*')//On verifie si c'est un caractere inconnu
        {
            break;
        }
        if(threat == '\n')
        {
            special = 1;
        }
        if(threat == ' ')
        {
            special = 2;
        }
    }
    poste = poste - clover;
    if(poste < 0)
    {
        poste = 26 + poste;
    }
    toReturn = delta[poste];
    if(threat == '*')
        toReturn = '*';
    if(special == 1)
        toReturn = '\n';
    if(special == 2)
        toReturn = 2;
    return toReturn;
}

string revertit(int cible)
{
    string prefixe;//La cible a retourner
    int nombres[10] = {0,1,2,3,4,5,6,7,8,9};
    string number[10] = {"0","1","2","3","4","5","6","7","8","9"};
    for(int i=0;i<10;i++)
    {
        if(nombres[i] == cible)
        {
            prefixe = number[i];
            break;
        }
    }
    return prefixe;
}

lisibilite verifie(string addresse)
{
    map<char,int> liste;
    int compteur = 0;
    int kit = 0;
    int valeur[26];
    char conteneur = NULL;
    string Alpha = "abcdefghijklmnopqrstuvwxyz";
    string Alpha2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ifstream lecteur(addresse.c_str());
    if(!lecteur)
    {
        cout<<addresse<<endl;
        cout << "Erreur d'ouverture d'un fichier"<<endl;
        getch();
        exit(0);
    }
    while(lecteur.get(conteneur))
    {
        kit = 0;
        for(int i=0;i<26;i++)
        {
            conteneur = tolower(conteneur);
            if(conteneur == Alpha[i])
            {
                cout <<conteneur <<endl;
                liste[conteneur]++;
                compteur++;
                kit = 1;
            }
            if(kit == 1)
                break;
        }
    }
    for(int i=0;i<26;i++)
    {
        valeur[i] = liste[Alpha[i]];
    }
    for(int i=0;i<26;i++)
    {
        valeur[i] = (valeur[i]*100)/compteur;
    }
    if(valeur[liste['e']] >= 12 && valeur[liste['a']] >= 7 && valeur[liste['a']] < 15 && valeur[liste['n']] >= 5)
        return bon;
    else if (valeur[liste['e']] >= 12 || valeur[liste['a']] >= 7 && valeur[liste['a']] < 15 || valeur[liste['n']] >= 5)
        return moyen;
    else
        return faible;
}

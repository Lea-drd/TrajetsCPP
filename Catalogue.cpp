/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

#include <string.h>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

    void Catalogue::Ajouter(Trajet * trajet){
        trajets->AddToQueue(trajet);
    }

    void Catalogue::Afficher(){
        trajets->Afficher();
    }

    void Catalogue::RechercheSimple(const char * villeA, const char * villeB){
        Maillon * curseur = trajets->getPremier();
        int nbT = 0;

        while(curseur != nullptr){
            char * vd = curseur->getElem()->GetVilleD();
            char * va = curseur->getElem()->GetVilleA();
            if(strcmp(vd, villeA)==0 && strcmp(va, villeB)==0){
                nbT++;
                cout << "["<< nbT << "] ";
                if(curseur->getElem()->GetType()==0){
                    cout << "Trajet simple : " << endl;
                }else{
                    cout << "Trajet composé : " << endl;
                }
                curseur->getElem()->Afficher();
            }
            curseur = curseur->getNext();
        }
        if(nbT==0){
            cout << "Pas de trajet trouvé. " << endl;
        }
    }

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

trajets = new Liste();

} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

    delete(trajets);


} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


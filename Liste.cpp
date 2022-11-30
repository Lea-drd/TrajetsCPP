/*************************************************************************
                           Liste  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Liste> (fichier Liste.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Liste.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Liste::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Liste::Afficher() const{
    Maillon * cursMaillon = premierMaillon;
    if(cursMaillon!=nullptr){
        cursMaillon->getElem()->Afficher();
    }
    while(cursMaillon->getNext()!=nullptr){
        cursMaillon=cursMaillon->getNext();
        cursMaillon->getElem()->Afficher();
    } 
}

void Liste::Ajouter(Trajet * trajet){
    Maillon * leMaillon = new Maillon(trajet);
    ++nbMaillon;
    if(premierMaillon == nullptr)
    {
        cout <<"Bienvenue au 1er maillon" << endl;
        premierMaillon = leMaillon;
    }
    else
    {
        cout <<"Je set le dernier maillon\n" << endl;
        dernierMaillon->setNext(leMaillon);
    }
    dernierMaillon = leMaillon;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
/*
Liste::Liste ( const Liste & unListe )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Liste>" << endl;
#endif
} //----- Fin de Liste (constructeur de copie)
*/

Liste::Liste ( Maillon * premierM, int nbM, Maillon * dernierM )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Liste>" << endl;
#endif
    premierMaillon = premierM;
    nbMaillon = nbM;
    dernierMaillon = dernierM;
} //----- Fin de Liste

Liste::~Liste ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Liste>" << endl;
#endif
} //----- Fin de ~Liste


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


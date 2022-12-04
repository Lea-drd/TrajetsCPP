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

void Liste::AddToQueue(Trajet * trajet){
    Maillon * leMaillon = new Maillon(trajet);
    ++nbMaillon;
    if(premierMaillon == nullptr)
    {
        premierMaillon = leMaillon;
    }
    else
    {
        dernierMaillon->setNext(leMaillon);
    }
    dernierMaillon = leMaillon;
}

Maillon * Liste::getPremier(){
    return premierMaillon;
}

Maillon * Liste::getDernier(){
    return dernierMaillon;
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

    Maillon * cursMaillon = premierMaillon;
    Maillon * nextMaillon = cursMaillon->getNext();
    if(nextMaillon==nullptr){
        delete cursMaillon;
    }
    else
    {
        while(nextMaillon->getNext()!=nullptr){
            delete cursMaillon;
            cursMaillon=nextMaillon;
            nextMaillon=nextMaillon->getNext();
        } 
   
    delete cursMaillon;
    delete nextMaillon;
    }
} //----- Fin de ~Liste


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


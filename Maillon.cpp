/*************************************************************************
                           Maillon  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Maillon> (fichier Maillon.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Maillon.h"

//------------------------------------------------------------- Constantes
#define nullptr NULL
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Maillon * Maillon::GetNext()
{
    return next;
}

void Maillon::SetElem(Trajet * t){
    elem = t;
}

void Maillon::SetNext(Maillon * m){
    next = m;
}

const Trajet * Maillon::GetElem(){
    return elem;
}
//-------------------------------------------- Constructeurs - destructeur

Maillon::Maillon ( const Trajet * e)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Maillon>" << endl;
#endif
   elem = e;
   next = nullptr;
} //----- Fin de Maillon


Maillon::~Maillon ( )
// Algorithme :
//  On détruit le Trajet lié et par recursivité les maillons vont se détruire jusqu'au dernier qui est null
{
#ifdef MAP
    cout << "Appel au destructeur de <Maillon>" << endl;
#endif
    if(next != nullptr){
        delete next;
    }
    delete elem;
} //----- Fin de ~Maillon


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

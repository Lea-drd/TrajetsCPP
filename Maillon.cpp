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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Maillon::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
Maillon * Maillon::getNext()
{
   return next;
}

void Maillon::setNext(Maillon * m){
    next = m->getNext();
}
//-------------------------------------------- Constructeurs - destructeur
/*
Maillon::Maillon ( const Maillon & unMaillon )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Maillon>" << endl;
#endif
} //----- Fin de Maillon (constructeur de copie)
*/

Maillon::Maillon ( Trajet * e)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Maillon>" << endl;
#endif
   elem = e;
} //----- Fin de Maillon


Maillon::~Maillon ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Maillon>" << endl;
#endif
} //----- Fin de ~Maillon


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


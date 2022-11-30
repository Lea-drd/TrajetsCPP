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

Liste::Liste ( Maillon * premierE, int nbE, Maillon * dernierE )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Liste>" << endl;
#endif
    premierElem = premierE;
    nbElem = nbE;
    dernierElem = dernierE;
} //----- Fin de Liste

void Liste::Ajouter(Maillon * trajet){
    ++nbElem;
    dernierElem->setNext(trajet);
    trajet->setNext(nullptr);
}

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


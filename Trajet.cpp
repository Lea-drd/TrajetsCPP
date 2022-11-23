/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $23/11/2022$
    copyright            : (C) $2022$ par $Lina BORG et Léa DURAND$
    e-mail               : $lina.borg@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode




//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/*Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
} //----- Fin de Trajet (constructeur de copie)*/


Trajet::Trajet ( const char *vd, const char *va )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
    villeDepart = new char[strlen(vd)+1];
    strcpy(villeDepart, vd);
    villeArrivee = new char[strlen(va)+1];
    strcpy(villeArrivee, va);
} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// void TrajetSimple::Afficher ( )
// Algorithme :
//{
//} //----- Fin de Afficher
void TrajetSimple::Afficher() const
{
    cout << " - De " << villeDepart << " à " << villeArrivee << " en " << moyenTransport; 
}

char * TrajetSimple::GetVilleD() const{
    return villeDepart;
}

char * TrajetSimple::GetVilleA() const{
    return villeArrivee;
}

char * TrajetSimple::GetTransport() const{
    return moyenTransport;
}

bool TrajetSimple::GetType() const{
    return 0;
}


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple (const char* vd, const char* va, const char* mt)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    moyenTransport = new char[strlen(mt)+1];
    strcpy(moyenTransport, mt);
    villeDepart = new char[strlen(vd)+1];
    strcpy(villeDepart, vd);
    villeArrivee = new char[strlen(va)+1];
    strcpy(villeArrivee, va);
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete [] moyenTransport;
    delete [] villeArrivee;
    delete [] villeDepart;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


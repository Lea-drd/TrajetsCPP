/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

    void TrajetCompose::Afficher() const
    {
        trajets->Afficher();
    }

    char * TrajetCompose::GetVilleD() const{
    return trajets->getPremier()->getElem()->GetVilleD();
}

    char * TrajetCompose::GetVilleA() const{
        return trajets->getDernier()->getElem()->GetVilleA();
    }

    void TrajetCompose::AddStep(const TrajetSimple * ts){
        if(strcmp(trajets->getDernier()->getElem()->GetVilleA(), ts->GetVilleD())==0){
            trajets->AddToQueue(ts);
        }
        else{
            cout << "[ERROR] La nouvelle étape débute à " << ts->GetVilleD() << " alors que la dernière étape termine à " << trajets->getDernier()->getElem()->GetVilleA() << endl;
        }
    }

    bool TrajetCompose::GetType(){
        return 1;
    }


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
/*
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose (constructeur de copie)
*/

TrajetCompose::TrajetCompose (const Trajet * tj)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    trajets = new Liste();
    trajets->AddToQueue(tj);
    nbTrajets = 1;
    derniereVilleTrajet = trajets->getDernier()->getElem()->GetVilleA();
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    delete(trajets);
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


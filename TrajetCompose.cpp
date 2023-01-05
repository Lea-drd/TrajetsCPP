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
#include <cstring>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes
#define nullptr NULL
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// void TrajetCompose::Afficher ( )
// Algorithme :
//  Appel l'affichage de la liste contenant des trajets simples
//{
//} //----- Fin de Afficher
    void TrajetCompose::Afficher() const
    {    
        trajets->Afficher();
    }

    void TrajetCompose::SauvegarderTrajet(const char * ficN) const
    {
        trajets->SauvegarderEtape(ficN);
    }

    char * TrajetCompose::GetVilleD() const{
    return trajets->GetPremier()->GetElem()->GetVilleD();
    }

    char * TrajetCompose::GetVilleA() const{
        return trajets->GetDernier()->GetElem()->GetVilleA();
    }

    char * TrajetCompose::GetTransport() const
    {
        return '\0';
    }

// void AddStep::Afficher ( const TrajetSimple * ts )
// Algorithme :
//  Ajoute l'étape si la ville de départ correspond à la ville d'arrivée précédente
//  Sinon renvoie un message d'erreur
//{
//} //----- Fin de AddStep
    void TrajetCompose::AddStep(const TrajetSimple * ts){
        if (trajets->GetPremier() == nullptr)
        {
            trajets->AddToQueue(ts);
            derniereVilleTrajet = trajets->GetDernier()->GetElem()->GetVilleA();
        }
        else if (!strcmp(trajets->GetDernier()->GetElem()->GetVilleA(), ts->GetVilleD()))
        { // La ville de départ et la précédente ville d'arrivée sont les mêmes
            trajets->AddToQueue(ts);
        }
        else
        {
            cout << "[ERROR] La nouvelle étape débute à " << ts->GetVilleD() << " alors que la dernière étape termine à " << trajets->GetDernier()->GetElem()->GetVilleA() << endl;
        }
    }

    bool TrajetCompose::GetType()const{
        return 1;
    }


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    trajets = new Liste();
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    delete trajets;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Liste.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//  Permet de définir un trajet composé
//  Peut être constitué de plusieurs étapes qui sont des trajets simples
//  On peut obtenir et définir ses attributs
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

// void Afficher ( );
// Mode d'emploi :
//  Permet d'afficher les étapes du trajet complexe
// Contrat :
//
    void Afficher() const;

    void SauvegarderTrajet(const char * ficN) const;

// void AddStep ( const TrajetSimple * ts );
// Mode d'emploi :
//  ts est le Trajet simple que l'on veut ajouter
//  Permet d'ajouter une étape au trajet 
// Contrat :
//
    void AddStep(const TrajetSimple * ts);
    char * GetVilleD() const;
    char * GetVilleA() const;
    char * GetTransport() const;
    bool GetType() const;

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    TrajetCompose ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Liste * trajets;
char * derniereVilleTrajet;
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose


/*************************************************************************
                           Liste  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Liste> (fichier Liste.h) ----------------
#if ! defined ( LISTE_H )
#define LISTE_H

//--------------------------------------------------- Interfaces utilisées
#include "Maillon.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Liste>
//  Elle permet de gerer une collection de Trajets simples et complexes. 
//  La Liste permet l'ajout, le tri et l'affichage
//------------------------------------------------------------------------

class Liste
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

// void Afficher ( );
// Mode d'emploi :
//  Permet l'affichage de chaque élément la constituant
// Contrat :
//
    void Afficher() const;

    void SauvegarderEtape(const char * ficN) const;

// void AddToQueue ( const Trajet * trajet );
// Mode d'emploi :
//  trajet est le trajet à ajouter
//  Permet d'ajouter à la fin de la liste
// Contrat :
//
    void AddToQueue(const Trajet * trajet);

// void AddSorted ( const Trajet * trajet );
// Mode d'emploi :
//  trajet est le trajet à ajouter
//  Permet d'ajouter de façon triée dans la liste
// Contrat :
//
    void AddSorted(const Trajet * trajet);
    Maillon * GetPremier();
    Maillon * GetDernier();

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    Liste ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Liste ();
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Att&ributs protégés
Maillon * premierMaillon;
Maillon * dernierMaillon;
int nbMaillon;
};

//-------------------------------- Autres définitions dépendantes de <Liste>

#endif // Liste_H


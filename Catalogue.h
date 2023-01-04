/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Liste.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//  Permet d'ajouter, afficher et rechercher un trajet simple ou complexe
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
// void Ajouter ( Trajet * trajet );
// Mode d'emploi :
//  trajet est le Trajet à ajouter dans le catalogue
//  Permet l'ajout dans la liste.
// Contrat : aucun
//
    void Ajouter(Trajet * trajet);

// void Afficher ( );
// Mode d'emploi :
//  Permet d'afficher chaque Maillon du Catalogue
// Contrat : aucun
//
    void Afficher();

    void Sauvegarde() const;

// void RechercheSimple ( const char * villeD, const char * villeA );
// Mode d'emploi :
//  villeD : ville de depart cherchée
//  villeA : ville d'arrivée cherchée
//  Permet de réaliser une recherche simple dans le catalague.
//  Seul les trajets ne mélangeant pas plusieurs trajets sont retournés.
// Contrat : aucun
//
    void RechercheSimple(const char * villeA, const char * villeB);
   
// void RechercheComplexe ( const char * villeA, const char * villeB, char * txt, const char * villesParcourues [], int nbVilles );
// Mode d'emploi :
//  villeD : ville de depart cherchée
//  villeA : ville d'arrivée cherchée
//  txt : texte qui sera affiché si une solution est trouvée
//  villesParcourues : tableau de chaine de caractères avec le nom des villes parcourues
//  nbVilles : nombre de villes parcourues
//  Permet de réaliser une recherche complexe dans le catalague.
//  Tout les trajets, même ceux regroupant plusieurs trajets, sont retournés.
// Contrat : aucun
//   
    void RechercheComplexe(const char * villeD, const char * villeA, Maillon * trajetsRecursif [], int nbTrajetsRecursifs);
    //void RechercheComplexe(const char * villeD, const char * villeA, char * villesparcourues [], int nbVilles);
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    Catalogue ( );
    // Mode d'emploi :
    //  
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Liste * trajets;

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H


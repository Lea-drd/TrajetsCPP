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

#include "Maillon.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Liste>
//
//
//------------------------------------------------------------------------

class Liste
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Afficher() const;
    void AddToQueue(const Trajet * trajet);
    Maillon * getPremier();
    Maillon * getDernier();


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
   /*
    Liste ( const Liste & unListe );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    */

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

//----------------------------------------------------- Attributs protégés
Maillon * premierMaillon;
int nbMaillon;
Maillon * dernierMaillon;

};

//-------------------------------- Autres définitions dépendantes de <Liste>

#endif // Liste_H


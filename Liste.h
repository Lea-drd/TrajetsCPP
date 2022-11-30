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


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
   /*
    Liste ( const Liste & unListe );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    */

    Liste (Maillon * premierE, int nbE, Maillon * dernierE);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Liste ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Ajouter(Maillon * trajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Maillon * premierElem;
int nbElem;
Maillon * dernierElem;

};

//-------------------------------- Autres définitions dépendantes de <Liste>

#endif // Liste_H


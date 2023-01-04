/*************************************************************************
                           Maillon  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/


//---------- Interface de la classe <Maillon> (fichier Maillon.h) ----------------
#if ! defined ( MAILLON_H )
#define MAILLON_H

#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Maillon>
//  Définie comment sont liés les trajets entre eux.
//  Chaque trajet est relié à un autre par un pointeur de façon ordonnée
//------------------------------------------------------------------------

class Maillon
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    Maillon * GetNext();
    const Trajet * GetElem();
    void SetElem(Trajet * t);
    void SetNext(Maillon *);
    //void Afficher() const;

//-------------------------------------------- Constructeurs - destructeur

    Maillon ( const Trajet * e);
    // Mode d'emploi :
    //
    // Contrat : aucun
    //

    virtual ~Maillon ( );
    // Mode d'emploi :
    //
    // Contrat : aucun
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
   const Trajet * elem;
   Maillon * next;

};

//-------------------------------- Autres définitions dépendantes de <Maillon>

#endif // XXX_H


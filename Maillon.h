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
//
//
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
    Maillon * getNext();
    const Trajet * getElem();
    void setElem(Trajet * t);
    void setNext(Maillon *);
    void Afficher() const;

//-------------------------------------------- Constructeurs - destructeur
 /*
    Maillon ( const Maillon & unMaillon );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
*/
    Maillon ( const Trajet * e);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Maillon ( );
    // Mode d'emploi :
    //
    // Contrat :
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


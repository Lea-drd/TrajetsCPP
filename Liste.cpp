/*************************************************************************
                           Liste  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Liste> (fichier Liste.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#define nullptr NULL

//------------------------------------------------------ Include personnel
#include "Liste.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// type Liste::Afficher ( )
// Algorithme :
//  Tant qu'il y a un maillon suivant on l'affiche
//{
//} //----- Fin de Afficher
void Liste::Afficher() const{
    Maillon * cursMaillon = premierMaillon;
    if(cursMaillon!=nullptr){
        cursMaillon->GetElem()->Afficher();
    }
    while(cursMaillon->GetNext()!=nullptr){
        cursMaillon=cursMaillon->GetNext();
        cursMaillon->GetElem()->Afficher();
    } 
}

void Liste::SauvegarderEtape(const char * ficN) const
{
    ofstream fic;
    fic.open(ficN, std::ios_base::app);

    Maillon * cursMaillon = premierMaillon;
    if(cursMaillon!=nullptr){
        fic << cursMaillon->GetElem()->GetVilleD() << "#" << cursMaillon->GetElem()->GetVilleA() << "#" << cursMaillon->GetElem()->GetTransport() << endl;
        
    }
    while(cursMaillon->GetNext()!=nullptr){
        cursMaillon=cursMaillon->GetNext();
        fic << cursMaillon->GetElem()->GetVilleD() << "#" << cursMaillon->GetElem()->GetVilleA() << "#" << cursMaillon->GetElem()->GetTransport() << endl;
    } 
}

// type Liste::AddToQueue ( const Trajet * trajet )
// Algorithme :
//{
//} //----- Fin de AddToQueue
void Liste::AddToQueue(const Trajet * trajet){
    Maillon * leMaillon = new Maillon(trajet);
    if(premierMaillon == nullptr)
    {
        premierMaillon = leMaillon;
    }
    else
    {
        dernierMaillon->SetNext(leMaillon);
    }
    dernierMaillon = leMaillon;
    ++nbMaillon;
}

// type Liste::AddSorted ( const Trajet * trajet )
// Algorithme :
//{
//  On ajoute soit en début de liste, soit au milieu selon l'ordre alphabetique départ puis arrivée, soit à la fin
//  On s'arrête dès que le bon emplacement est trouvé.
//} //----- Fin de AddSorted
void Liste::AddSorted(const Trajet * trajet){
    Maillon * leMaillon = new Maillon(trajet);

    //La liste est initialement vide
    if(premierMaillon==nullptr){
        premierMaillon= leMaillon;
        dernierMaillon = leMaillon;
        ++nbMaillon;
        return;
    }

    //Le premier maillon doit être échangé
    //Alphabétique départ et arrivée
    if(strcmp(premierMaillon->GetElem()->GetVilleD(), trajet->GetVilleD())>0 || (strcmp(premierMaillon->GetElem()->GetVilleD(), trajet->GetVilleD())==0 && strcmp(premierMaillon->GetElem()->GetVilleA(), trajet->GetVilleA())>0)){
        leMaillon->SetNext(premierMaillon);
        ++nbMaillon;
        premierMaillon=leMaillon;
        return;
    }

    Maillon * curseur = premierMaillon;
    Maillon * curseurPrec = premierMaillon;

    while(curseur != dernierMaillon){

        //Les villes de départ sont identiques
        //--> Tri par ville d'arrivée
        if(strcmp(curseur->GetElem()->GetVilleD(), trajet->GetVilleD())==0){

            //La première ville est à échanger
            while(curseur != dernierMaillon && strcmp(curseur->GetElem()->GetVilleD(), trajet->GetVilleD())==0){
                if(strcmp(curseur->GetElem()->GetVilleA(), trajet->GetVilleA())>0){
                    curseurPrec->SetNext(leMaillon);
                    leMaillon->SetNext(curseur);
                   
                    return;
                }
                curseurPrec=curseur;
                curseur=curseur->GetNext();
            }
            curseurPrec->SetNext(leMaillon);
            leMaillon->SetNext(curseur);
            ++nbMaillon;
            return;
        }
        else if(strcmp(curseur->GetElem()->GetVilleD(), trajet->GetVilleD())>0){
            curseurPrec->SetNext(leMaillon);
            leMaillon->SetNext(curseur);
            ++nbMaillon;
            return;
        }
        curseurPrec=curseur;
        curseur=curseur->GetNext();
    }
    //Ajout en fin de liste sinon
    dernierMaillon->SetNext(leMaillon);
    dernierMaillon=leMaillon;
    ++nbMaillon;
}

Maillon * Liste::GetPremier(){
    return premierMaillon;
}

Maillon * Liste::GetDernier(){
    return dernierMaillon;
}



//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


Liste::Liste ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Liste>" << endl;
#endif
    premierMaillon = nullptr;
    dernierMaillon = nullptr;
    nbMaillon = 0;
} //----- Fin de Liste

Liste::~Liste ( )
// Algorithme :
//  On détruit le premier maillon et par recursivité les maillons vont se détruire jusqu'au dernier qui est null
{
#ifdef MAP
    cout << "Appel au destructeur de <Liste>" << endl;
#endif

    Maillon * cursMaillon = premierMaillon;
    if(cursMaillon != nullptr){
        delete cursMaillon;
    }



} //----- Fin de ~Liste


//------------------------------------------------------------------ PRIVE


//----------------------------------------------------- Méthodes protégées


/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#define nullptr NULL
#include <string.h>
#include <cstdlib>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// void Catalogue::Ajouter ( Trajet * trajet )
// Algorithme :
//{
//} //----- Fin de Ajouter
    void Catalogue::Ajouter(Trajet * trajet){
        trajets->AddSorted(trajet);
    }

// void Catalogue::Afficher ( )
// Algorithme :
//{
//} //----- Fin de Afficher
    void Catalogue::Afficher(){
        int n=1;
        //cout << "Affichage de Catalogue" << endl;
        Maillon * cursMaillon = trajets->GetPremier();
        if(cursMaillon!=nullptr){
            cout << "[" << n << "]";
            cursMaillon->GetElem()->Afficher();
            cout << endl;
            while(cursMaillon->GetNext()!=nullptr){
                ++n;
                cout << "[" << n << "]";
                cursMaillon=cursMaillon->GetNext();
                cursMaillon->GetElem()->Afficher();
                cout << endl;
            }
            Sauvegarde(); 
        }
        else
            cout << " -- Le catalogue est vide -- " << endl << endl;
        
    }

    void Catalogue::Sauvegarde() const{
        //penser à demander le nom du fichier après !!!!
        ofstream fic;
        int n=1;
        //cout << "Affichage de Catalogue" << endl;
        Maillon * cursMaillon = trajets->GetPremier();
        if(cursMaillon!=nullptr){
            const char * ficN = "sauvegarde.txt";
            fic.open (ficN);
            fic << cursMaillon->GetElem()->GetType() << endl;
            fic << cursMaillon->GetElem()->GetVilleD() << "//" << cursMaillon->GetElem()->GetVilleA();
            fic.close();
            cursMaillon->GetElem()->SauvegarderTrajet(ficN);
            while(cursMaillon->GetNext()!=nullptr){
                ++n;
                cursMaillon=cursMaillon->GetNext();
                fic.open (ficN, std::ios_base::app);
                fic << cursMaillon->GetElem()->GetType() << endl;
                fic << cursMaillon->GetElem()->GetVilleD() << "//" << cursMaillon->GetElem()->GetVilleA() << endl;
                fic.close();
                cursMaillon->GetElem()->SauvegarderTrajet(ficN);
            } 
        }
    }

// void Catalogue::RechercheSimple ( const char * villeD, const char * villeA )
// Algorithme :
//  Parcours toute la liste de trajets
//  On affiche toutes les solutions, la ville de départ et d'arrivée demandées correspondent au trajet
//{
//} //----- Fin de RechercheSimple
    void Catalogue::RechercheSimple(const char * villeD, const char * villeA){
        Maillon * curseur = trajets->GetPremier();
        int nbT = 0;

        while(curseur != nullptr){
            char * vd = curseur->GetElem()->GetVilleD();
            char * va = curseur->GetElem()->GetVilleA();
            if(strcmp(vd, villeD)==0 && strcmp(va, villeA)==0){
                ++nbT;
                cout << "["<< nbT << "] ";
                // A voir si c'est necessaire de laisser .GetType 
                if(curseur->GetElem()->GetType()==0){
                    cout << "Trajet simple  : ";
                }else{
                    cout << "Trajet composé : ";
                }
                curseur->GetElem()->Afficher();
                cout << endl;
            }
            curseur = curseur->GetNext();
        }
        if(nbT==0){
            cout << "Pas de trajet trouvé. " << endl << endl;
        }
    }

// void Catalogue::RechercheComplexe ( const char * villeD, const char * villeA )
// Algorithme :
//{
//  Parcours toute la liste de trajets
//  Si le trajet n'a pas déjà été utilisé on recherche sur celui ci
//  Si la ville de départ et d'arrivée correspond on a une solution
//  Sinon on prend la ville d'arrivée comme ville de départ et on fait une recursivité
//  L'affichage est supposé se faire en appelant un tableau de Maillon qui contient le chemin passé !Ne fonctionne pas
//} //----- Fin de RechercheComplexe
    void Catalogue::RechercheComplexe(const char * villeD, const char * villeA, Maillon * trajetsRecursif [], int nbTrajetsRecursifs)
    {
        int i;
        bool solution = true;
        bool utilisable;
        
        Maillon * curseur = trajets->GetPremier();
        while(curseur != nullptr)
        {
            utilisable = true;
            char * vd = curseur->GetElem()->GetVilleD();
            char * va = curseur->GetElem()->GetVilleA();
            for(i = 0; i<nbTrajetsRecursifs; i++){
                if(curseur == trajetsRecursif[i] )
                {
                    utilisable = false;
                }
            }
            if(utilisable)
            {
                if( strcmp(vd, villeD) == 0 && strcmp(va, villeA) != 0 )
                {
                    trajetsRecursif[nbTrajetsRecursifs] = curseur;
                    solution = true;
                    RechercheComplexe(va, villeA, trajetsRecursif, ++nbTrajetsRecursifs);
                }
                else if ( strcmp(vd, villeD) == 0 && strcmp(va, villeA) == 0 )
                {

                    //Affichage avec trajetsrecursif + curseur
                    for(i = 0; i<nbTrajetsRecursifs; i++){
                        //trajetsRecursif[i]->GetElem()->Afficher();
                    }
                    curseur->GetElem()->Afficher();
                    cout << endl;
                    //trajetsRecursif[0]->GetElem()->Afficher();
                }
            }
            
            curseur = curseur->GetNext();
            
            if(solution){
                --nbTrajetsRecursifs;
                trajetsRecursif[nbTrajetsRecursifs] = nullptr;
            }
        }

    }  
    
    


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ( )
// Algorithme :
//  Création d'une liste pour contenir les trajets
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

trajets = new Liste();


} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//  Destruction de la liste
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

    delete(trajets);


} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


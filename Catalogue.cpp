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
    void Catalogue::Ajouter(Trajet * trajet) const{
        trajets->AddSorted(trajet);
    }

// void Catalogue::Afficher ( )
// Algorithme :
//{
    void Catalogue::Afficher() const{
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
        }
        else
            cout << " -- Le catalogue est vide -- " << endl << endl;
        
    }
//} //----- Fin de Afficher

// void Catalogue::Sauvegarde ( )
// Algorithme :
//{
    void Catalogue::Sauvegarde() const{
    // Choix du types d'enregistrement
        char lecture [] = {'3'};
        int cdtType = 2;
        while (strcmp(lecture,"0")!=0)
        {
            cout << "Enregistrer :" << endl;
            cout << " tous les trajets     - taper 0." << endl;
            cout << " les trajets simples  - taper 1." << endl;
            cout << " les trajets composés - taper 2." << endl;
            cout << "--> "; 
            cin >> lecture;
            if (strcmp(lecture,"1")==0) {
                cdtType = 1; // On veut pas le type 1, soit pas de trajets composés
                lecture[0] = '0';
            }else if (strcmp(lecture,"2")==0) {
                cdtType = 0; // On veut pas le type 0, soit pas de trajets simples
                lecture[0] = '0';
            }
        }

    // Choix du nom du fichier
        char nomFichier [30] = "";
        cout << "Taper 0 pour quitter." << endl;
        cout << "Nom du fichier ? (sans extension) --> ";
        cin.ignore();
        cin.getline(nomFichier, 30);
        cout << endl;
        nomFichier[0] == '\0' ? strcat(nomFichier, "sauvegarde.txt") : strcat(nomFichier, ".txt");
    
        if(strcmp(nomFichier, "0.txt")==0) return;

    // Enregistrement des trajets
        ofstream fic;
        int n=1;
        Maillon * cursMaillon = trajets->GetPremier();
        if(cursMaillon!=nullptr){
            const char * ficN = nomFichier;
        // Reset du fichier quelque soit l'enregistrement voulu
            fic.open(ficN, ios_base::trunc);
            fic.close();
            if(cursMaillon->GetElem()->GetType() != cdtType){
                fic.open(ficN);
                fic << cursMaillon->GetElem()->GetType() << endl;
                fic << cursMaillon->GetElem()->GetVilleD() << "#" << cursMaillon->GetElem()->GetVilleA() << endl;
                fic.close();
                cursMaillon->GetElem()->SauvegarderTrajet(ficN);
            }           
            
            while(cursMaillon->GetNext()!=nullptr){
                ++n;
                cursMaillon=cursMaillon->GetNext();
                if(cursMaillon->GetElem()->GetType() != cdtType){
                    fic.open(ficN, ios_base::app);
                    fic << cursMaillon->GetElem()->GetType() << endl;
                    fic << cursMaillon->GetElem()->GetVilleD() << "#" << cursMaillon->GetElem()->GetVilleA() << endl;
                    fic.close();
                    cursMaillon->GetElem()->SauvegarderTrajet(ficN);
                }
            } 
        }
        cout << "Enregistrement de " << n << " trajets, effectué dans " << nomFichier << endl;
    }
//} //----- Fin de Sauvegarde

// void Catalogue::Chargement ( )
// Algorithme :
//{
    void Catalogue::Chargement() const{

        int n=0;

    // Choix du types de chargement
        char lecture [] = {'3'};
        char cdtType = '2';
        while (strcmp(lecture,"0")!=0)
        {
            cout << "Charger :" << endl;
            cout << " tous les trajets     - taper 0." << endl;
            cout << " les trajets simples  - taper 1." << endl;
            cout << " les trajets composés - taper 2." << endl;
            cout << "--> "; 
            cin >> lecture;
            if (strcmp(lecture,"1")==0) {
                cdtType = '1'; // On veut pas le type 1, soit pas de trajets composés
                lecture[0] = '0';
            }else if (strcmp(lecture,"2")==0) {
                cdtType = '0'; // On veut pas le type 0, soit pas de trajets simples
                lecture[0] = '0';
            }
        }

    // Choix du nom du fichier
        ifstream fic;
        const char * ficN;
        char nomFichier [30] = "";
        ficN = "simple.txt";

        do
        {
            cout << "Taper 0 pour quitter." << endl;
            cout << "Nom du fichier ? (sans extension) --> ";
            cin.ignore();
            cin.getline(nomFichier, 30);
            if (strcmp(nomFichier, "0")==0) return;
            strcat(nomFichier, ".txt");
            ficN = nomFichier;
            fic.open(ficN, ios_base::in);
            if (!fic) cout << "____ FICHIER " << ficN << " INCOMPATIBLE ____"  << endl;
        } while (!fic);

       if(strcmp(ficN, "0")==0) return;

    // Lecture du fichier
        char line [30];
        while(!fic.eof())
        {
            fic.getline(line, 30);
            if(line[0] == '0' && line[0] != cdtType)
            {
                ++n;
                fic.ignore(30, '\n');
                char vd [30], va [30], transport [30];
                fic.getline(vd, 30, '#');
                fic.getline(va, 30, '#');
                fic.getline(transport, 30);
                cout << vd << va << transport << endl;
                TrajetSimple * TS = new TrajetSimple(vd, va, transport);
                
                Ajouter(TS);
                
            }
            else if(line[0] == '1' && line[0] != cdtType)
            {
                ++n;
                fic.ignore(30, '\n');
                TrajetCompose * TC = new TrajetCompose();
                while(fic.peek() != 48 && fic.peek() != 49){ // ASCII pour 0 et 1
                    char vd [30], va [30], transport [30];
                    fic.getline(vd, 30, '#');
                    fic.getline(va, 30, '#');
                    fic.getline(transport, 30, '\n');
                    TrajetSimple * TS = new TrajetSimple(vd, va, transport);
                    TC->AddStep(TS);
                }
                Ajouter(TC);
            }
        }
        cout << "Chargement de " << n << " trajets, effectué depuis " << ficN << endl;
    }
//} //----- Fin de Chargement

// void Catalogue::RechercheSimple ( const char * villeD, const char * villeA )
// Algorithme :
//  Parcours toute la liste de trajets
//  On affiche toutes les solutions, la ville de départ et d'arrivée demandées correspondent au trajet
//{
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
                curseur->GetElem()->GetType()==0 ? cout << "Trajet simple  : " : cout << "Trajet composé : ";
                curseur->GetElem()->Afficher();
                cout << endl;
            }
            curseur = curseur->GetNext();
        }
        if(nbT==0){
            cout << "Pas de trajet trouvé. " << endl << endl;
        }
    }
//} //----- Fin de RechercheSimple

// void Catalogue::RechercheComplexe ( const char * villeD, const char * villeA )
// Algorithme :
//{
//  Parcours toute la liste de trajets
//  Si le trajet n'a pas déjà été utilisé on recherche sur celui ci
//  Si la ville de départ et d'arrivée correspond on a une solution
//  Sinon on prend la ville d'arrivée comme ville de départ et on fait une recursivité
//  L'affichage est supposé se faire en appelant un tableau de Maillon qui contient le chemin passé !Ne fonctionne pas

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
//} //----- Fin de RechercheComplexe   
    


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


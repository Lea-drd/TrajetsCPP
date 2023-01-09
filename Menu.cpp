#include <iostream>
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Liste.h"
#include "Maillon.h"
#include "Catalogue.h"
using namespace std;
#include <cstring>

void menu ();

TrajetSimple * creationTS()
{
   char vd [30], va [30], transport [30];
   cin.ignore();
   cout << "Ville de départ ? -->    ";
   cin.getline(vd, 30);
   cout << "Ville d'arrivée ? -->    ";
   cin.getline(va, 30);
   cout << "Moyen de transport ? --> ";
   cin.getline(transport, 30);
   cout << endl;  
   TrajetSimple * TS = new TrajetSimple(vd, va, transport);
   return TS;
}

void creationTC(Catalogue &c)
{
   TrajetCompose * TC = new TrajetCompose();
   char lecture [] = {'1'};

   while (strcmp(lecture,"0")!=0)
   {
      if (strcmp(lecture,"1")==0) {
         TrajetSimple * TS = creationTS();
         TC->AddStep(TS);
      }
      cout << "--------------------------------" << endl;
      cout << "Entrer une nouvelle étape - taper 1." << endl;
      cout << "Valider                   - taper 0." << endl;
      cout << "--> "; 
      cin >> lecture;
   }
   c.Ajouter(TC);
}


void AjoutCatalogue(Catalogue &c)
{
   char lecture [] = {'4'};
   while (strcmp(lecture,"0")!=0)
   {
      cout << "--------------------------------" << endl;
      cout << "Ajouter un trajet simple  - taper 1." << endl;
      cout << "Ajouter un trajet composé - taper 2." << endl;
      cout << "Charger des trajets       - taper 3." << endl;
      cout << "Retour au menu            - taper 0." << endl;
      cout << "--> "; 
      cin >> lecture;
      if (strcmp(lecture,"1")==0) {
         cout << "____Création d'un trajet simple____" << endl;
         TrajetSimple * TS = creationTS();
         c.Ajouter(TS);
      } else if (strcmp(lecture,"2")==0) {
         cout << "____Création d'un trajet composé___" << endl;
         creationTC(c);
      } else if (strcmp(lecture,"3")==0) {
         cout << "____Chargement de trajets___" << endl;
         c.Chargement();
      }
   }
}

void menu ()
{
   char lecture [] = {'4'};
   Catalogue c;
   
   while (strcmp(lecture,"0")!=0)
   {
      cout << "--------------------------------" << endl;
      cout << "Afficher le catalogue    - taper 1." << endl;
      cout << "Ajouter un trajet        - taper 2." << endl;
      cout << "Recherche un trajet      - taper 3." << endl;
      cout << "Enregistrer le catalogue - taper 4." << endl;
      cout << "Quitter                  - taper 0." << endl;
      cout << "--> "; 
      cin >> lecture;
      if (strcmp(lecture,"1")==0) {
         cout << "____Affichage du catalogue____" << endl;
         c.Afficher();
      } else if (strcmp(lecture,"2")==0) {
         AjoutCatalogue(c);
      } else if (strcmp(lecture,"3")==0) {
         cout << "____Recherche simple___" << endl;
         cin.ignore();
         char vd [30], va [30];
         cout << "Ville de départ ? -->    ";
         cin.getline(vd,30);
         cout << "Ville d'arrivée ? -->    ";
         cin.getline(va,30);
         cout << "Résultat de la recherche :" << endl;
         c.RechercheSimple(vd, va);
      
      // Pour tester la recherche complexe, décommenter les lignes suivantes.
         /*
         cout << "Recherche complexe : " << endl;
         Maillon * trajetsParcourus [15];
         c.RechercheComplexe(vd, va, trajetsParcourus, 0);
         */
      } else if (strcmp(lecture,"4")==0) {
         cout << "____Enregistrement____" << endl;
         c.Sauvegarde();
      }
   }
}

int main ()
{
   menu();
   return 0;
}
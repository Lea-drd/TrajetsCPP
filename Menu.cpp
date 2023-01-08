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
   cout << "Ville de départ ?\n--> ";
   cin.getline(vd, 30);
   cout << "Ville d'arrivée ?\n--> ";
   cin.getline(va, 30);
   cout << "Moyen de transport ?\n--> ";
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
      cout << "Retour au menu            - taper 0." << endl;
      cout << "--> "; 
      cin >> lecture;
      if (strcmp(lecture,"1")==0) {
         TrajetSimple * TS = creationTS();
         c.Ajouter(TS);
      } else if (strcmp(lecture,"2")==0) {
         creationTC(c);
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
      cout << "Afficher le catalogue - taper 1." << endl;
      cout << "Ajouter un trajet     - taper 2." << endl;
      cout << "Recherche un trajet   - taper 3." << endl;
      cout << "Quitter               - taper 0." << endl;
      cout << "--> "; 
      cin >> lecture;
      if (strcmp(lecture,"1")==0) {
         c.Afficher();
      } else if (strcmp(lecture,"2")==0) {
         AjoutCatalogue(c);
      } else if (strcmp(lecture,"3")==0) {
         char vd [30], va [30];
         cout << "Ville de départ ?" << endl << "--> ";
         cin.getline(vd,30);
         cout << "Ville d'arrivée ?" << endl << "--> ";
         cin.getline(va,30);
         cout << "Recherche simple : " << endl;
         c.RechercheSimple(vd, va);
      
      // Pour tester la recherche complexe, décommenter les lignes suivantes.
         /*
         cout << "Recherche complexe : " << endl;
         Maillon * trajetsParcourus [15];
         c.RechercheComplexe(vd, va, trajetsParcourus, 0);
         */
      }
   }
}

int main ()
{
   menu();
   return 0;
}
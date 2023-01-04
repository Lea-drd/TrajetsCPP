#include <iostream>
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Liste.h"
#include "Maillon.h"
#include "Catalogue.h"
#include <istream>
using namespace std;
#include <cstring>

void menu ();

TrajetSimple * creationTS()
{
   char vd [30], va [30], transport [30];
   cout << "Merci de remplacer les \" \" par des \"_\"" << endl;
   cout << "Ville de départ ?" << endl << "--> ";
   cin >> vd;
   cout << "Ville d'arrivée ?" << endl << "--> ";
   cin >> va;
   cout << "Moyen de transport ?" << endl << "--> ";
   cin >> transport;  
   cout << endl;  
   TrajetSimple * TS = new TrajetSimple(vd, va, transport);
   
   return TS;
}

void creationTC(Catalogue &c)
{
   bool entreeTrajet = 1;
   int reponse;
   TrajetCompose * TC = new TrajetCompose();
   while (entreeTrajet)
   {
      TrajetSimple * TS = creationTS();
      TC->AddStep(TS);
      cout << "--------------------------------" << endl;
      cout << "Entrer une nouvelle étape - taper 1." << endl;
      cout << "Valider          - taper 0." << endl;
      cout << "--> "; 
      cin >> reponse;
      cout << endl;

      switch (reponse)
      {
      case 1:
      {
         break;
      }

      case 0:
      {
         c.Ajouter(TC);
         entreeTrajet = 0;
         break;
      }
      
      default:
      {
         cout << "Réponse non reconnue." << endl;
         break;
      }

      }
   }
}


void AjoutCatalogue(Catalogue &c)
{
   int reponse;
   cout << "--------------------------------" << endl;
   cout << "Ajouter un trajet simple  - taper 1." << endl;
   cout << "Ajouter un trajet composé - taper 2." << endl;
   cout << "Retour au menu            - taper 0." << endl;
   cout << "--> "; 
   cin >> reponse;
   cout << endl;

   switch (reponse)
   {
   case 1:
   {
      TrajetSimple * TS = creationTS();
      c.Ajouter(TS);
      
      break;
   }

   case 2:
   {
      creationTC(c);
      break;
   }

   case 0:
   {
      menu();
      break;
   }

   default:
   {
      cout << "Réponse non reconnue." << endl;
      menu();
      break;
   }

   }
}

void menu ()
{
   bool appActive = true;
   int reponse;
   Catalogue c;


   while(appActive)
   {
      cout << "--------------------------------" << endl;
      cout << "Afficher le catalogue - taper 1." << endl;
      cout << "Ajouter un trajet     - taper 2." << endl;
      cout << "Recherche un trajet   - taper 3." << endl;
      cout << "Quitter               - taper 0." << endl;
      cout << "--> "; 
      cin >> reponse;
      cout << endl;
      
      switch (reponse)
      {
      case 1:
      {
         c.Afficher();
         break;
      }

      case 2:
      {
         AjoutCatalogue(c);
         break; 
      }

      case 3:
      {
         char vd [30], va [30];
         cout << "Ville de départ ?" << endl << "--> ";
         cin >> va;
         cout << "Ville d'arrivée ?" << endl << "--> ";
         cin >> va;
         cout << "Recherche simple : " << endl;
         c.RechercheSimple(vd, va);
      
      // Pour tester la recherche complexe, décommenter les lignes suivantes.
         /*
         cout << "Recherche complexe : " << endl;
         Maillon * trajetsParcourus [15];
         c.RechercheComplexe(vd, va, trajetsParcourus, 0);
         */
         break; 
      }
      
      case 0:
      {
         appActive = false;
         break;
      }

      default:
      {
         cout << "Réponse non reconnue." << endl;
         break;
      }

      }
   }
}

int main ()
{
   menu();
   return 0;
}


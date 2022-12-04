#include <iostream>
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Liste.h"
#include "Maillon.h"
#include "Catalogue.h"
using namespace std;
#include <cstring>
void construit();

int main ()
{

   Liste l (nullptr, 0, nullptr);
   TrajetSimple TS1 ("Lyon", "Grenoble", "Metro");
   TrajetSimple TS2 ("Paris", "Oloron", "Train");
   l.AddToQueue(&TS1);
   l.AddToQueue(&TS2);
   TrajetCompose TC1(&l, 2);

   Catalogue c;

   c.Ajouter(&TS1);
   c.Ajouter(&TC1);

   cout << "Affichage liste : " << endl;
   l.Afficher();
   cout << "Affichage trajet composé : " << endl;
   TC1.Afficher();
   cout << "Affichage catalogue : " << endl;
   c.Afficher();
   cout << "Résultat recherche ok : " << endl;
   c.RechercheSimple("Lyon", "Grenoble");
   cout << "Résultat recherche ko : " << endl;
   c.RechercheSimple("Lyon", "Turin");

   return 0;
}

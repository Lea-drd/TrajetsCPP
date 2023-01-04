#include <iostream>
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Liste.h"
#include "Maillon.h"
#include "Catalogue.h"
using namespace std;
#include <cstring>

int main ()
{

   Liste l = Liste();
   TrajetSimple TS1 ("Lyon", "Grenoble", "Metro");
   TrajetSimple TS2 ("Paris", "Oloron", "Train");
   l.AddToQueue(&TS1);
   l.AddToQueue(&TS2);
   TrajetCompose TC1 = TrajetCompose();
   TC1.AddStep(&TS1);
   TC1.AddStep(&TS2);

   Catalogue c;

   c.Ajouter(&TS1);
   c.Ajouter(&TC1);

   cout << "Affichage catalogue : " << endl;
   c.Afficher();

   return 0;
}
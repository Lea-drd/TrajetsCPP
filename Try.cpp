#include <iostream>
#include "TrajetSimple.h"
#include "Liste.h"
#include "Maillon.h"
using namespace std;
#include <cstring>
void construit();

int main ()
{

   Liste l (nullptr, 0, nullptr);
   TrajetSimple TS1 ("Lyon", "Grenoble", "Metro");
   TrajetSimple TS2 ("Paris", "Oloron", "Train");
   l.Ajouter(&TS1);
   l.Ajouter(&TS2);
/*   TS1.Afficher();
   TS2.Afficher();
*/
   l.Afficher();
   return 0;
}

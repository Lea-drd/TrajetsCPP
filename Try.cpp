#include <iostream>
#include "TrajetSimple.h"
#include "TrajetCompose.h"
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
   l.AddToQueue(&TS1);
   l.AddToQueue(&TS2);
   TrajetCompose TC1(&l, 2);
/* TS1.Afficher();
   TS2.Afficher();
*/
   l.Afficher();
   TC1.Afficher();
   return 0;
}

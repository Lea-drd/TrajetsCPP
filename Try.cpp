#include <iostream>
#include "TrajetSimple.h"
using namespace std;
#include <cstring>
void construit();

int main ()
{
   TrajetSimple TS ("Lyon", "Grenoble", "Metro");
   TS.Afficher();
   return 0;
}

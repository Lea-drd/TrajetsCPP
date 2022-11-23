#include <iostream>
#include "TrajetSimple.h"
using namespace std;

#include <cstring>

int main ()
{
   TrajetSimple *TS = new TrajetSimple("Lyon", "Grenoble", "Metro");
   TS->Afficher();
}
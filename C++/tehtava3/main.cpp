#include <iostream>
#include "matikka.h"
#include "geometria.h"

using namespace std;
using namespace matikka;
using namespace geometria;

int main()
{
    tulostaValilta(3, 6);
    cout << laskeSumma(55, 12);
    cout << laskeKolmio(12, 23);
    cout << laskeYmpyra(123);
    return 0;
}
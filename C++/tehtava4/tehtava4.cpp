#include <iostream>
#include "taulukot.h"
using namespace std;
using namespace taulukot;

int main()
{
    //luoTaulukko();
    kaannaTaulukko();
    setLed(2, 4, 1);
    printLed();
    clearLed();
    printLed();
}

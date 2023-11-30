// main.cpp
#include <iostream>
#include "DigitMaster.h"

using namespace std;

int main(){

    DigitMaster dm;
    int dec, bin;

    cout << "Introduce el número decimal: ";
    cin >> dec;
    bin = dm.BinADec(dec);
    cout << "El binario es: " << bin;

    return 0;
}
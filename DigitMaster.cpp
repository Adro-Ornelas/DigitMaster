// DigitMaster.cpp
#include "DigitMaster.h"

int DigitMaster::DecABin(int decimal){
    int bin = 0, pow10=1;
    while(decimal > 0){
        bin += decimal % 2 * pow10;
        decimal /=2;
        pow10 *= 10;
    }

    return bin;
}

int DigitMaster::BinADec(int binario){
    int dec=0, pow2=1;
    while(binario > 0){
        dec += binario % 10 * pow2;
        binario /= 10;
        pow2 *= 2;
    }    
    return dec;
}
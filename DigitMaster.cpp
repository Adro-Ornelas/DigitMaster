// DigitMaster.cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "DigitMaster.h"

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void DigitMaster::clrscr(){
	system(CLEAR);
}
void DigitMaster::pause(){
	std::cin.get();
	char pause = ' ';
	std::cout << "Presiona <Enter> para continuar...";
	// do{
		pause = std::cin.get();
	//}while(pause != '\n');
}

int DigitMaster::BaseYADec(int numY, int baseY){
    int dec=0, powY = 1;
    while(numY > 0){
        dec += numY % 10 * powY;
        numY /= 10;
        powY *= baseY;
    }    
    return dec;
}

int DigitMaster::DecABaseY(int decimal, int baseY){
    int numY = 0, pow10=1;

    while(decimal > 0){
        numY += decimal % baseY * pow10;
        decimal /= baseY;
        pow10 *= 10;
    }

    return numY;
}

void DigitMaster::MenuConversio(){
	int option;
    int dec, numY, baseY;
	do {
		clrscr();
		std::cout << "UTILIDADES DIGITALES>Conversiones\n"
					 "1. Decimal a Base X\n"
					 "2. Base X a DEcimal\n"
					 "3. Atrás\n";
					 "0. Salir\n";
		std::cout << "Selecciona una opción: ";
		std::cin >> option;
		
		switch(option){
			case 0:
				break;
			case 1: 
				std::cout << "Introduce el número decimal: ";
				std::cin >> dec;
				do{
					std::cin >> baseY;
					if(baseY < 2 || baseY > 16)
						std::cout << "Base no admitida";
				} while(baseY < 2 || baseY > 16);

				numY = DecABaseY(dec, baseY);
				std::cout << "El número base y es: " << numY
						 << std::endl;
				pause();
				break;

			case 2:
				std::cout << "Introduce el número en baseY y su base: ";
				std::cin >> numY  >> baseY;
				dec = BaseYADec(numY, baseY);
				std::cout << "El decimal es: " << dec
						  << std::endl;
			break;
		}
	} while(option != 0 && option != EOF);
}

void DigitMaster::MenuPrincipal(){
	int option;
	do {
		clrscr();
		std::cout << "UTILIDADES DIGITALES\n"
					 "1.   Conversiones\n"
					 "0.   Salir(EOF)\n";
		std::cout << "Selecciona una opción: ";
		std::cin >> option;

		switch(option){
			case 0:
				break;
			case 1:
				MenuConversio();
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				break;
		}
	} while(option != 0 && option != EOF);
}

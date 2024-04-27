#include <iostream>
#include <conio.h>
#include <locale.h>
#include "Inicio.h"


using namespace std;
using namespace System;

int main() 
{
	setlocale(LC_ALL, "ESP");
	srand(time(NULL));

	Inicio* us = new Inicio();
	
	us->main();
    
	
	return 0;
}
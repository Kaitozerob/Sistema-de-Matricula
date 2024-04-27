#pragma once
#include <iostream>
#include <string>

using namespace std;

class Usuario
{
protected:

	string nombre;
	string apellido;
	string numero;
	string sede;
	string correo;

public:
	Usuario(string n, string ap, string num, string dir, string cor)
	{
		nombre = n;
		apellido = ap;
		numero = num;
		sede = dir;
		correo = cor;
	}
};


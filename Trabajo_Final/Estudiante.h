#include "Usuario.h"
#include <iostream>

using namespace std;

class Estudiante : public Usuario
{

private:

	string dni;

	string edad;
	string usuario;
	string contrase�a;

public:

	Estudiante(string n, string ap, string num, string dir, string cor, string dn, string ed, string usuo, string contrase) :Usuario(n, ap, num, dir, cor)
	{
		dni = dn;
		edad = ed;
		usuario = usuo;
		contrase�a = contrase;
	}

	void MostrarEstudiante()
	{
		cout << nombre << apellido << dni << numero << correo << endl;
	}

	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	string getUsuario() { return usuario; }
	string getContrase�a() { return contrase�a; }

};
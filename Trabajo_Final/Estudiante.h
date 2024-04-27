#include "Usuario.h"
#include <iostream>

using namespace std;

class Estudiante : public Usuario
{

private:

	string dni;

	string edad;
	string usuario;
	string contraseña;

public:

	Estudiante(string n, string ap, string num, string dir, string cor, string dn, string ed, string usuo, string contrase) :Usuario(n, ap, num, dir, cor)
	{
		dni = dn;
		edad = ed;
		usuario = usuo;
		contraseña = contrase;
	}

	void MostrarEstudiante()
	{
		cout << nombre << apellido << dni << numero << correo << endl;
	}

	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	string getUsuario() { return usuario; }
	string getContraseña() { return contraseña; }

};
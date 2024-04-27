#include "Usuario.h"
#include <iostream>

using namespace std;

class Profesor : public Usuario
{
private:
	string curso;
	int id;
	string dias;
	int hinicio;
	int hfin;

public:

	Profesor(string n, string ap, string num, string sed, string cor, string espe, int i, int hi) :Usuario(n, ap, num, sed, cor)
	{
		curso = espe;
		id = i;
		dias = dias;
		hinicio = hi;
		hfin = hinicio + 2;
	}

	void toString()
	{
		cout << "Indice: " << id << endl;
		cout << "Nombre: " << nombre << " " << apellido << endl;
		cout << "Numero: " << numero << endl;
		cout << "Sede: " << sede << endl;
		cout << "Curso: " << curso << endl;
		cout << "Horario: " << hinicio << ":00" << " - " << hfin << ":00" << endl;
	}

	int getId() { return id; }
	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	string getCurso() { return curso; }
	int getHorario() { return hinicio; }
	void setHorario(int dato) { hinicio = dato; }


};